//4. 设计循环队列一

typedef struct
{
	int *data;//数据域
	int front;//队列头
	int rear;//队列尾
	int size;//队列大小,用以避免数组越界  
	int flag;//标志队列是否满 ,1 满, 0 不满
	//如果不用此标志位的话，数组需要留多一位空位用来判别队列是否满
	//即：当头指针在尾指针的下一个位置（多的空位）时，队列满
} MyCircularQueue;//采用数组实现

//函数声明
bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

//创建一个可以存放k个元素的循环队列
MyCircularQueue* myCircularQueueCreate(int k)
{
	if (k < 0)
	{
		//传参检查
		return NULL;
	}
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	if (obj == NULL)
	{
		return NULL;
	}
	obj->data = (int*)malloc(k * sizeof(int));
	if (obj->data == NULL)
	{
		return NULL;
	}
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
	{
		//判断队列是否满
		return false;
	}
	obj->data[obj->rear] = value;//插入数据
	obj->rear = ((obj->rear + 1) < obj->size) ? (obj->rear + 1) : 0;
	//判断是否到达数组边界，且尾指针+1
	if (obj->rear == obj->front)
	{
		//在插入新元素后，两指针指向相同，只有队列满一种情况
		obj->flag = 1;//队列已满
	}
	return true;
}

//从循环队列中删除一个元素,如果成功插入则返回真
bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		//判断队列是否空
		return false;
	}
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
	{
		return -1;
	}
	return obj->data[obj->front];
}

//获取队尾元素
int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	int i = (obj->rear == 0) ? (obj->size - 1) : (obj->rear - 1);
	//尾指针指向的是末尾数据的下一个位置，此处避免数组越界
	return obj->data[i];
}

//检查循环队列是否为空
bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	if (obj->flag == 0 && obj->front == obj->rear)
	{
		//队列未满 且 首尾指针指向相同，则表明队列空
		return true;
	}
	else
	{
		return false;
	}
}

//检查循环队列是否已满
bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	if (obj->flag == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->data);
	obj->data = NULL;
	free(obj);
	obj = NULL;
}





////////////////////////////////////////////////////////////////
//4. 设计循环队列二

//解题思路：
//通过一个定长数组实现循环队列
//入队：首先要判断队列是否已满，再进行入队的操作，入队操作需要考虑索引循环的问题，当索引越界，需要让它变成最小值
//出队：首先要判断队列是否为空，再进行出队操作，出队也需要考虑索引循环的问题
//判空： 队头 == 队尾
//判满： 队尾 + 1 == 队头

typedef struct {
	int* queue;
	int front;
	int rear;
	int k
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
//创建一个可以存放k个元素的循环队列，实际申请的空间为k + 1
MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* pcq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	pcq->queue = (int*)malloc(sizeof(int)*(k + 1));
	pcq->front = 0;
	pcq->rear = 0;
	pcq->k = k;

	return pcq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	//判满
	if ((obj->rear + 1) % (obj->k + 1) == obj->front)
	{
		return false;
	}
	//队尾入队
	obj->queue[obj->rear++] = value;
	//如果队尾越界，更新为最小值
	if (obj->rear == obj->k + 1)
		obj->rear = 0;

	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	//判空
	if (obj->front == obj->rear)
		return false;
	//队头出队
	++obj->front;
	//如果队头越界，更新为最小值
	if (obj->front == obj->k + 1)
		obj->front = 0;

	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return -1;
	else
		return obj->queue[obj->front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return -1;
	//队尾元素再rear索引的前一个位置，如果rear为0，
	//则队尾元素在数组的最后一个位置
	if (obj->rear == 0)
		return obj->queue[obj->k];
	else
		return obj->queue[obj->rear - 1];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->front == obj->rear;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->rear + 1) % (obj->k + 1) == obj->front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->queue);
	free(obj);
}

