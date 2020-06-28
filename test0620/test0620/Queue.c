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


// �������ʱ��ʲô�����Ӧ����assert��ʲô�����Ӧ����if���ж�
// if: ����������ʱ�����������һ�ֺϷ��������Ӧ����if---���磺������
// assert: ����������ʱ�����������һ�ַǷ��������Ӧ��if---���磺��������
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
	// ����β��
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
