#include "Stack.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>


// ��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (SDataType*)malloc(sizeof(SDataType)* 10);
	if (NULL == ps->array)
	{
		assert(0);
		return;
	}

	ps->capacity = 10;
	ps->size = 0;
}

//����
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		//1.�����¿ռ�
		SDataType* temp = (SDataType*)malloc(sizeof(SDataType)*ps->size * 2);
		if (temp == NULL)
		{
			assert(0);
			return;
		}

		//2.����Ԫ��
		memcpy(temp, ps->array, sizeof(SDataType)*ps->size);

		//3.�ͷžɿռ�
		free(ps->array);

		//4.ʹ���¿ռ�
		ps->array = temp;
		ps->capacity *= 2;
	}
}

// ��ջ��β��
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);
	CheckCapacity(ps);//����Ƿ���Ҫ����
	ps->array[ps->size++] = data;
}

// ��ջ��βɾ
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;

	ps->size--;
}

// ��ȡջ��Ԫ��
SDataType StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));
	return ps->array[ps->size - 1];
}

// ��ȡջ����ЧԪ�صĸ���
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}

// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
