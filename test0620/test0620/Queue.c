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
		q->front = cur->next;
		free(cur);
		cur = q->front;
	}

	q->front = q->rear = NULL;
	q->size = 0;
}
