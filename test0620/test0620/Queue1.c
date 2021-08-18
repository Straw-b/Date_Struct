#include "Queue1.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>


//����ڵ�
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

// ��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

// ��β�����
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

// ��ͷ������
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

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->front->data;
}

// ��ȡ����β��Ԫ��
QDataType QueueBack(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->rear->data;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->front;
}

// ���ٶ��У����нڵ�ĵ�����
void QueueDestroy(Queue* q)
{
	//����ͷɾ������������Ч�ڵ��ͷ�ڵ�ȫ��ɾ����
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