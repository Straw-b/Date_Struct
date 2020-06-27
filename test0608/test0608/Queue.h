#pragma once

// 队列底层采用连续空间来实现，效果不是很好
// 队列：采用链表的方式实现的

typedef int QDataType;

// 链式结构：表示队列
//队列底层使用链表中的节点
typedef struct QNode
{
	struct QNode* next;
	QDataType data;
}QNode;

// 队列的结构
typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;  //记录队列中有效元素的个数
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


///////////////////////////////////////////////////////
void TestQueue();