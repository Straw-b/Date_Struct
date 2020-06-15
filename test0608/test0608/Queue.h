#pragma once


// 队列底层采用连续空间来实现，效果不是很好
// 队列：采用链表的方式实现的

typedef int QDataType;
typedef struct QNode
{
	struct QNode* next;
	QDataType data;
}QNode;


typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType data);
void QueuePop(Queue* q);
QDataType QueueFront(Queue* q);
QDataType QueueBack(Queue* q);
int QueueSize(Queue* q);
int QueueEmpty(Queue* q);
void QueueDestroy(Queue* q);



///////////////////////////////////////////////////////
void TestQueue();










typedef int QDataType;

// 链式结构：表示队列
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// 队列的结构
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列
void QueueInit(Queue* q);
// 队尾入队列
void QueuePush(Queue* q, QDataType data);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列队尾元素
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);