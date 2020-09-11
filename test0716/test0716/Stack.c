#include "Stack.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>


// 初始化栈
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

//扩容
void CheckCapacity(Stack* ps)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		//1.开辟新空间
		SDataType* temp = (SDataType*)malloc(sizeof(SDataType)*ps->size * 2);
		if (temp == NULL)
		{
			assert(0);
			return;
		}

		//2.拷贝元素
		memcpy(temp, ps->array, sizeof(SDataType)*ps->size);

		//3.释放旧空间
		free(ps->array);

		//4.使用新空间
		ps->array = temp;
		ps->capacity *= 2;
	}
}

// 入栈：尾插
void StackPush(Stack* ps, SDataType data)
{
	assert(ps);
	CheckCapacity(ps);//检测是否需要扩容
	ps->array[ps->size++] = data;
}

// 出栈：尾删
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;

	ps->size--;
}

// 获取栈顶元素
SDataType StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));
	return ps->array[ps->size - 1];
}

// 获取栈中有效元素的个数
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}

// 销毁栈
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;
}
