#pragma once

typedef int SDataType;


//��̬ջ�Ľṹ
//#define MAXSIZE 100
//
//typedef struct Stack
//{
//	SDataType array[MAXSIZE];
//	int top; // ���ջ��
//}Stack;
//�������ʱ��Ҫ�õ�ջ�����Կ��ٶ���һ��ջ�����ÿ�������


// ֧�ֶ�̬������ջ
typedef struct Stack
{
	SDataType* array;
	int capacity; // ����
	int size; // ջ��Ԫ�صĸ���--ջ��
}Stack;


//ע�⣺
//1.ջ��û������λ�õĲ����ɾ������
//2.ջ����Ҫ����--����

// ��ʼ��ջ
void StackInit(Stack* ps);

// ��ջ��β��
void StackPush(Stack* ps, SDataType data);

// ��ջ��βɾ
void StackPop(Stack* ps);

// ��ȡջ��Ԫ��
SDataType StackTop(Stack* ps);

// ��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps);

// ����ջ
void StackDestroy(Stack* ps);


///////////////////////////////////
void TestStack();