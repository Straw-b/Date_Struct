#pragma once

// ���еײ���������ռ���ʵ�֣�Ч�����Ǻܺ�
// ���У���������ķ�ʽʵ�ֵ�

typedef int QDataType;

// ��ʽ�ṹ����ʾ����
//���еײ�ʹ�������еĽڵ�
typedef struct QNode
{
	struct QNode* next;
	QDataType data;
}QNode;

// ���еĽṹ
typedef struct Queue
{
	QNode* front;
	QNode* rear;
	int size;  //��¼��������ЧԪ�صĸ���
}Queue;

// ��ʼ������
void QueueInit(Queue* q);
// ��β�����
void QueuePush(Queue* q, QDataType data);
// ��ͷ������
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q);
// ���ٶ���
void QueueDestroy(Queue* q);


///////////////////////////////////////////////////////
void TestQueue();