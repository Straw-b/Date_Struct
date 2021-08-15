//1. 用栈实现队列

typedef int DataType;

typedef struct Stack
{ 
	DataType* array;
	int capacity;
	int size;
}Stack;

//栈的初始化
void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (DataType*)malloc(sizeof(DataType)* 3);
	if (NULL == ps->array)
	{
		assert(0);
		return;
	}

	ps->capacity = 3;
	ps->size = 0;
}

//扩容
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		//1.开辟新空间
		int newCapacity = ps->capacity * 2;
		DataType* temp = (DataType*)malloc(sizeof(DataType)*newCapacity);
		if (temp == NULL)
		{
			assert(0);
			return;
		}

		//2.拷贝元素
		memcpy(temp, ps->array, sizeof(DataType)*ps->capacity);

		//3.释放旧空间
		free(ps->array);

		//4.使用新空间
		ps->array = temp;
		ps->capacity *= 2;
	}
}

// 入栈：尾插
void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);//检测是否需要扩容
	ps->array[ps->size++] = data;
}

// 出栈：尾删
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;

	ps->size--;
}

// 获取栈顶元素
DataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->array[ps->size - 1];
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}

// 销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;
}


////////////////////////////////////////////////////////////////
//使用栈实现队列的下列操作：
//push(x) --将一个元素放入队列的尾部。
//pop() --从队列首部移除元素。
//peek() --返回队列首部的元素。
//empty() --返回队列是否为空。

typedef struct 
{
	Stack s1; //模拟入队列
	Stack s2; //模拟出队列
} MyQueue;

//创建队列
MyQueue* myQueueCreate() 
{
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&mq->s1);
	StackInit(&mq->s2);
	return mq;
}

//入队列
void myQueuePush(MyQueue* obj, int x) 
{
	StackPush(&obj->s1, x);
}

//出队列
int myQueuePop(MyQueue* obj) 
{
	//s2中没有元素
	if (StackEmpty(&obj->s2))
	{
		//s1中有元素
		while (!StackEmpty(&obj->s1))
		{
			//将s1中的元素搬移到s2中
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}

	int ret = StackTop(&obj->s2);
	StackPop(&obj->s2);
	return ret;
}

//获取队头元素
int myQueuePeek(MyQueue* obj) 
{
	//s2中没有元素
	if (StackEmpty(&obj->s2))
	{
		//s1中有元素
		while (!StackEmpty(&obj->s1))
		{
			//将s1中的元素搬移到s2中
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}
	return StackTop(&obj->s2);
}

//检测队列是否为空
bool myQueueEmpty(MyQueue* obj) 
{
	return StackEmpty(&obj->s1) && StackEmpty(&obj->s2);
}

void myQueueFree(MyQueue* obj) 
{
	StackDestroy(&obj->s1);
	StackDestroy(&obj->s2);
	free(obj);
}







//2. 用队列实现栈

//入栈：哪个队列非空，就将元素插入到哪个队列中
//出栈：哪个队列不为空，将哪个队列中的前n-1个元素搬移到另一个队列中，然后将该元素删除掉
//获取栈顶元素：哪个队列非空，就直接获取队尾的元素

typedef int QDataType;

//队列底层使用链表中的节点
typedef struct QNode
{
	struct QNode* next;
	QDataType val;
}QNode;

//队列的结构
typedef struct Queue
{
	struct QNode* head;
	struct QNode* rear;
	int size;//记录队列中有效元素的个数
}Queue;

//申请节点的函数
QNode* BuyQNode(int val)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}

	newNode->val = val;
	newNode->next = NULL;

	return newNode;
}

// 初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->head = BuyQNode(0);
	q->size = 0;
	q->rear = q->head;
}

// 队尾入队列
void QueuePush(Queue* q, QDataType val)
{
	assert(q);
	QNode* newNode = BuyQNode(val);
	q->rear->next = newNode;
	q->rear = newNode;
	q->size++;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
	assert(q);
	return 0 == q->size;
}

// 队头出队列
void QueuePop(Queue* q)
{
	QNode* pDelNode = NULL;
	if (QueueEmpty(q))
		return;

	pDelNode = q->head->next;
	q->head->next = pDelNode->next;
	if (q->head->next == NULL)
		q->rear = q->head;

	free(pDelNode);
	q->size--;
}

// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->head->next->val;
}

// 获取队列尾部元素
QDataType QueueBack(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->rear->val;
}

// 销毁队列：带有节点的单链表
void QueueDestroy(Queue* q)
{
	//采用头删法将链表中有效节点和头节点全部删除点
	QNode* cur = NULL;
	while (cur)
	{
		q->head = cur->next;
		free(cur);
		cur = q->head;
	}

	q->head = NULL;
	q->rear = NULL;
	q->size = 0;
}


/////////////////////////////////////////////////////
//使用队列实现栈的下列操作：
//push(x) --元素 x 入栈
//pop() --移除栈顶元素
//top() --获取栈顶元素
//empty() --返回栈是否为空

typedef struct 
{
	Queue q1;
	Queue q2;
} MyStack;

//创建栈的结构
MyStack* myStackCreate() 
{
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&ms->q1);
	QueueInit(&ms->q2);
	return ms;
}

//入栈
void myStackPush(MyStack* obj, int x) 
{
	if (!QueueEmpty(&obj->q1))//如果q1不为空
		QueuePush(&obj->q1, x);
	else
		QueuePush(&obj->q2, x);
}

//出栈
int myStackPop(MyStack* obj) 
{
	int ret = 0;
	if (!QueueEmpty(&obj->q1))
	{
		//q1队列中有元素---将q1中n-1个元素搬移到q2中
		while (QueueSize(&obj->q1) > 1)
		{
			QueuePush(&obj->q2, QueueFront(&obj->q1));
			QueuePop(&obj->q1);
		}

		ret = QueueFront(&obj->q1);
		//最后将q1中剩余的1个元素删除掉
		QueuePop(&obj->q1);
	}
	else
	{
		//q2队列中有元素---将q2中n-1个元素搬移到q1中
		while (QueueSize(&obj->q2) > 1)
		{
			QueuePush(&obj->q1, QueueFront(&obj->q2));
			QueuePop(&obj->q2);
		}
		
		ret = QueueFront(&obj->q2);
		//最后将q2中剩余的1个元素删除掉
		QueuePop(&obj->q2);
	}
	return ret;
}

//获取栈顶元素
int myStackTop(MyStack* obj) 
{
	if (!QueueEmpty(&obj->q1))
		//q1队列中有元素---获取队尾元素
		return QueueBack(&obj->q1);
	else
		return QueueBack(&obj->q2);
}

//判断是否为空
bool myStackEmpty(MyStack* obj) 
{
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) 
{
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}
