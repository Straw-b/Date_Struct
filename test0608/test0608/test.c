#include "Queue.h"

int main()
{
	TestQueue();
	return 0;
}
	



#if 0
//4. 设计循环队列

typedef struct
{
	int *data; //数据域
	int front; //队列头
	int rear; //队列尾
	int size; //队列大小,用以避免数组越界  
	int flag; //标志队列是否满 ,1 满, 0 不满
			  //如果不用此标志位的话，数组需要留多一位空位用来判别队列是否满
			  //即：当头指针在尾指针的下一个位置（多的空位）时，队列满
} MyCircularQueue;//采用数组实现

//声明
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

//创建一个可以存放k个元素的循环队列
MyCircularQueue* myCircularQueueCreate(int k)
{
	if (k < 0)
		return NULL;//传参检查
	
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (obj == NULL)
		return NULL;
	
	obj->data = (int*)malloc(k * sizeof(int));
	if (obj->data == NULL)
		return NULL;
	
	//赋各项初值
	obj->front = obj->rear = 0;
	obj->size = k;
	obj->flag = 0;
	return obj;
}

//向循环队列插入一个元素,如果成功插入则返回真
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
		return false;//判断队列是否满

	obj->data[obj->rear] = value;//插入数据
	obj->rear = ((obj->rear + 1) < obj->size) ? (obj->rear + 1) : 0;
	//判断是否到达数组边界，且尾指针+1
	if (obj->rear == obj->front)
		//在插入新元素后，两指针指向相同，只有队列满一种情况
		obj->flag = 1;//队列已满
	
	return true;
}

//从循环队列中删除一个元素,如果成功插入则返回真
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;//判断队列是否空
	
	obj->data[obj->front] = 0;//清除队头的数据
	obj->front = ((obj->front + 1) < obj->size) ? (obj->front + 1) : 0;
	//判断是否到达数组边界,且头指针+1
	obj->flag = 0;//只要删除了元素，队列就不可能满
	return true;
}

//从队首获取元素
int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	
	return obj->data[obj->front];
}

//获取队尾元素
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;
	
	//队尾元素在rear索引的前一个位置，如果rear为0，则队尾元素在数组的最后一个位置
	//尾指针指向的是末尾数据的下一个位置，此处避免数组越界
	if (obj->rear == 0)
		return obj->data[obj->size - 1];
	else
		return obj->data[obj->rear - 1];
}

//检查循环队列是否为空
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	if (obj->flag == 0 && obj->front == obj->rear)
		//队列未满 且 首尾指针指向相同，则表明队列空
		return true;
	else
		return false;
}

//检查循环队列是否已满
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	if (obj->flag == 1)
		return true;
	else
		return false;
}

//释放循环队列
void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->data);
	obj->data = NULL;
	free(obj);
	obj = NULL;
}
#endif