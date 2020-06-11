//3. ��ջʵ�ֶ���
typedef int DataType;
typedef struct Stack
{ 
	DataType* array;
	int capacity;
	int size;
}Stack;

//ջ�ĳ�ʼ��
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

//����
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		//1.�����¿ռ�
		int newCapacity = ps->capacity * 2;
		DataType* temp = (DataType*)malloc(sizeof(DataType)*newCapacity);
		if (temp == NULL)
		{
			assert(0);
			return;
		}

		//2.����Ԫ��
		memcpy(temp, ps->array, sizeof(DataType)*ps->capacity);

		//3.�ͷžɿռ�
		free(ps->array);

		//4.ʹ���¿ռ�
		ps->array = temp;
		ps->capacity *= 2;
	}
}

// ��ջ��β��
void StackPush(Stack* ps, DataType data)
{
	assert(ps);
	CheckCapacity(ps);//����Ƿ���Ҫ����
	ps->array[ps->size++] = data;
}

// ��ջ��βɾ
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;

	ps->size--;
}

// ��ȡջ��Ԫ��
DataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->array[ps->size - 1];
}

// ��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}

// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;
}


////////////////////////////////////////////////////////////////
//ʹ��ջʵ�ֶ��е����в�����
//push(x) --��һ��Ԫ�ط�����е�β����
//pop() --�Ӷ����ײ��Ƴ�Ԫ�ء�
//peek() --���ض����ײ���Ԫ�ء�
//empty() --���ض����Ƿ�Ϊ�ա�

typedef struct 
{
	Stack s1; //ģ�������
	Stack s2; //ģ�������
} MyQueue;

/** Initialize your data structure here. */
//��������
MyQueue* myQueueCreate() 
{
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&mq->s1);
	StackInit(&mq->s2);
	return mq;
}

/** Push element x to the back of queue. */
//�����
void myQueuePush(MyQueue* obj, int x) 
{
	StackPush(&obj->s1,x);
}

/** Removes the element from in front of queue and returns that element. */
//������
int myQueuePop(MyQueue* obj) 
{
	if (StackEmpty(&obj->s2))
	{
		//��s1�е�Ԫ�ذ��Ƶ�s2��
		while (!StackEmpty(&obj->s1))
		{
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}

	int ret = StackTop(&obj->s2);
	StackPop(&obj->s2);
	return ret;
}

/** Get the front element. */
//��ȡ��ͷԪ��
int myQueuePeek(MyQueue* obj) 
{
	if (StackEmpty(&obj->s2))
	{
		//��s1�е�Ԫ�ذ��Ƶ�s2��
		while (!StackEmpty(&obj->s1))
		{
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}
	return StackTop(&obj->s2);
}

/** Returns whether the queue is empty. */
//�������Ƿ�Ϊ��
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

/**
* Your MyQueue struct will be instantiated and called as such:
* MyQueue* obj = myQueueCreate();
* myQueuePush(obj, x);

* int param_2 = myQueuePop(obj);

* int param_3 = myQueuePeek(obj);

* bool param_4 = myQueueEmpty(obj);

* myQueueFree(obj);
*/






//2. �ö���ʵ��ջ
//���У��Ƚ��ȳ���ջ��������

//1.��ջ���ĸ����зǿգ��ͽ�Ԫ�ز��뵽�ĸ�������
//2.��ջ���ĸ����в�Ϊ�գ����ĸ������е�ǰn-1��Ԫ�ذ��Ƶ���һ�������У�Ȼ�󽫸�Ԫ��ɾ����
//3.��ȡջ��Ԫ�أ��ĸ����зǿգ���ֱ�ӻ�ȡ��β��Ԫ��

typedef int QDataType;

//���еײ�ʹ�������еĽڵ�
typedef struct QNode
{
	struct QNode* next;
	QDataType val;
}QNode;

//���еĽṹ
typedef struct Queue
{
	struct QNode* head;
	struct QNode* rear;
	int size;//��¼��������ЧԪ�صĸ���
}Queue;

//����ڵ�ĺ���
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

// ��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->head = BuyQNode(0);
	q->size = 0;
	q->rear = q->head;
}

// ��β�����
void QueuePush(Queue* q, QDataType val)
{
	assert(q);
	QNode* newNode = BuyQNode(val);
	q->rear->next = newNode;
	q->rear = newNode;
	q->size++;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q)
{
	assert(q);
	return 0 == q->size;
}

// ��ͷ������
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

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->head->next->val;
}

// ��ȡ����β��Ԫ��
QDataType QueueBack(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->rear->val;
}

// ���ٶ��У����нڵ�ĵ�����
void QueueDestroy(Queue* q)
{
	//����ͷɾ������������Ч�ڵ��ͷ�ڵ�ȫ��ɾ����
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
//ʹ�ö���ʵ��ջ�����в�����
//push(x) --Ԫ�� x ��ջ
//pop() --�Ƴ�ջ��Ԫ��
//top() --��ȡջ��Ԫ��
//empty() --����ջ�Ƿ�Ϊ��

typedef struct 
{
	Queue q1;
	Queue q2;
} MyStack;

/** Initialize your data structure here. */
//����ջ�Ľṹ
MyStack* myStackCreate() 
{
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&ms->q1);
	QueueInit(&ms->q2);
	return ms;
}

/** Push element x onto stack. */
//��ջ
void myStackPush(MyStack* obj, int x) 
{
	if (!QueueEmpty(&obj->q1))//���q1��Ϊ��
		QueuePush(&obj->q1, x);
	else
		QueuePush(&obj->q2, x);
}

/** Removes the element on top of the stack and returns that element. */
//��ջ
int myStackPop(MyStack* obj) 
{
	int ret = 0;
	if (!QueueEmpty(&obj->q1))
	{
		//q1��������Ԫ��---��q1��n-1��Ԫ�ذ��Ƶ�q2��
		while (QueueSize(&obj->q1) > 1)
		{
			QueuePush(&obj->q2, QueueFront(&obj->q1));
			QueuePop(&obj->q1);
		}

		ret = QueueFront(&obj->q1);
		//���q1��ʣ���1��Ԫ��ɾ����
		QueuePop(&obj->q1);
	}
	else
	{
		//q2��������Ԫ��---��q2��n-1��Ԫ�ذ��Ƶ�q1��
		while (QueueSize(&obj->q2) > 1)
		{
			QueuePush(&obj->q1, QueueFront(&obj->q2));
			QueuePop(&obj->q2);
		}
		
		ret = QueueFront(&obj->q2);
		//���q2��ʣ���1��Ԫ��ɾ����
		QueuePop(&obj->q2);
	}
	return ret;
}

/** Get the top element. */
//��ȡջ��Ԫ��
int myStackTop(MyStack* obj) 
{
	if (!QueueEmpty(&obj->q1))
		return QueueBack(&obj->q1);
	else
		return QueueBack(&obj->q2);
}

/** Returns whether the stack is empty. */
//�ж��Ƿ�Ϊ��
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

/**
* Your MyStack struct will be instantiated and called as such:
* MyStack* obj = myStackCreate();
* myStackPush(obj, x);

* int param_2 = myStackPop(obj);

* int param_3 = myStackTop(obj);

* bool param_4 = myStackEmpty(obj);

* myStackFree(obj);
*/