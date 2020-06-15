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



















//�ο�
///////////////////////////////////////////////

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
