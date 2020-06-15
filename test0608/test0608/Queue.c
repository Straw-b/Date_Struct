#include "Queue.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>


QNode* BuyQNode(QDataType data)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}

	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


// 参数检测时：什么情况下应该用assert，什么情况下应该用if来判断
// if: 当条件成立时，该种情况是一种合法的情况，应该用if---比如：空链表
// assert: 当条件成立时，该种情况是一种非法的情况，应用if---比如：链表不存在
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

void QueuePush(Queue* q, QDataType data)
{
	QNode* newNode = BuyQNode(data);
	// 链表尾插
	if (QueueEmpty(q))
	{
		q->front = newNode;
	}
	else
	{
		q->rear->next = newNode;
	}

	q->rear = newNode;
	q->size++;
}

void QueuePop(Queue* q)
{
	QNode* delNode = NULL;
	if (QueueEmpty(q))
		return;

	delNode = q->front;
	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
		q->front = delNode->next;

	free(delNode);
	q->size--;
}

QDataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->front->data;
}


QDataType QueueBack(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->rear->data;
}

int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->front;
}

void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		q->front = cur;
		free(cur);
		cur = q->front;
	}

	q->front = q->rear = NULL;
	q->size = 0;
}




void TestQueue()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);
	QueuePush(&q, 6);

	printf("%d \n", QueueSize(&q));
	printf("%d \n", QueueFront(&q));
	printf("%d \n", QueueBack(&q));

	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);
	QueuePop(&q);

	printf("%d \n", QueueSize(&q));
	printf("%d \n", QueueFront(&q));
	printf("%d \n", QueueBack(&q));

	QueuePop(&q);
	QueuePop(&q);
	printf("%d \n", QueueSize(&q));
}



















//参考
///////////////////////////////////////////////

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
