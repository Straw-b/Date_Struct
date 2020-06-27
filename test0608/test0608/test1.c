//4. 设计循环队列

typedef struct
{
	int *data;//数据域
	int front;//队列头
	int rear;//队列尾
	int size;//队列大小 -> 用以避免数组越界  
	int flag;//标志队列是否满 ->   1 满   0 不满
	//如果不用此标志位的话，数组需要留多一位空位用来 判别 队列是否满
	//即：当 头指针 在 尾指针的下一个位置（多的空位）时，队列满。
} MyCircularQueue;//采用数组实现

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);
//注意加上函数声明


/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) 
{

}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) 
{

} 

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) 
{

}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) 
{

}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) 
{

}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) 
{

}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) 
{

}

void myCircularQueueFree(MyCircularQueue* obj) 
{

}

/**
* Your MyCircularQueue struct will be instantiated and called as such:
* MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);
* bool param_2 = myCircularQueueDeQueue(obj);
* int param_3 = myCircularQueueFront(obj);
* int param_4 = myCircularQueueRear(obj);
* bool param_5 = myCircularQueueIsEmpty(obj);
* bool param_6 = myCircularQueueIsFull(obj);
* myCircularQueueFree(obj);
*/


//////////////////////////////////////////////////////////////////////////参考
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
		//在插入新元素后，两指针指向相同，只有队列满一种情况。
		obj->flag = 1;//队列已满
	}
	return true;
}


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


int myCircularQueueFront(MyCircularQueue* obj) 
{
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	return obj->data[obj->front];
}


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
