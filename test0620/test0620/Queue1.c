#include "Queue1.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>


//申请节点
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

// 初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
	q->size = 0;
}

// 队尾入队列
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

// 队头出队列
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

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->front->data;
}

// 获取队列尾部元素
QDataType QueueBack(Queue* q)
{
	assert(!QueueEmpty(q));
	return q->rear->data;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL == q->front;
}

// 销毁队列：带有节点的单链表
void QueueDestroy(Queue* q)
{
	//采用头删法将链表中有效节点和头节点全部删除点
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
