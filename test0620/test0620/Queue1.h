#pragma once


typedef int QDataType;

// ��ʽ�ṹ����ʾ����
// ���еײ�ʹ�������еĽڵ�
typedef struct QNode
{
	struct QNode* next;
	QDataType data;
}QNode;

// ���еĽṹ
typedef struct Queue
{
	QNode* front; //��ͷ
	QNode* rear; //��β
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(Queue* q);
// ���ٶ���
void QueueDestroy(Queue* q);
