#include "Queue.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>

//����ڵ�ĺ���
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

// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
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


//////////////////////////////////////////////////////////////
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

	QueueDestroy(&q);
}
