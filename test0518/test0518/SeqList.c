#include "SeqList.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>


//初始化
void SeqListInit(SeqList* s, int initCapacity)
{
	assert(s);
	initCapacity = initCapacity <= 10 ? 10 : initCapacity;
	//10个 SDataType ---->总的字节数:sizeof(SDataType)*10
	s->array = (SDataType*)malloc(sizeof(SDataType)*initCapacity);
	if (NULL == s->array)
		return;

	s->capacity = initCapacity;
	s->size = 0;
}

// 尾插
void SeqListPushBack(SeqList* s, SDataType data)
{
	assert(s);
	//在插入之前要保证有空间
	s->array[s->size++] = data;
	//s->size++;
}

// 尾删
void SeqListPopBack(SeqList* s)
{
	if (SeqListEmpty(s))
		return;

	s->size--;
}

// 头插
void SeqListPushFront(SeqList* s, SDataType data)
{
	//是否需要扩容

	//需要将顺序表中所有的元素向后搬移一个位置
	for (int i = s->size - 1; i >= 0; i--)
		s->array[i+1] = s->array[i];

	//在0号位置插入data
	s->array[0] = data;
	s->size++;
}

// 头删
void SeqListPopFront(SeqList* s)
{
	if (SeqListEmpty(s))
		return;

	for (int i = 1; i < s->size; ++i)
		s->array[i - 1] = s->array[i];
	s->size--;
}

// 任意位置插入
void SeqListInsert(SeqList* s, int pos, SDataType data)
{

}

// 任意位置删除
void SeqListErase(SeqList* s, int pos)
{

}

// 获取顺序表中有效元素个数
int SeqListSize(SeqList* s)
{
	assert(s);
	return s->size;
}

// 获取顺序表的容量
int SeqListCapacity(SeqList* s)
{
	assert(s);
	return s->capacity;
}

// 检测顺序表是否为空
int SeqListEmpty(SeqList* s)
{
	assert(s);
	return 0 == s->size;
}

// 顺序表清空
void SeqListClear(SeqList* s)
{
	assert(s);
	s->size = 0;
}

// 查找值为data的元素是否在顺序表中，如果在返回下标，否则返回-1
int SeqListFind(SeqList* s, SDataType data)
{
	assert(s);
	for (int i = 0; i < s->size; ++i)
	{
		if (s->array[i] == data)
			return i;
	}
	return -1;
}

// 顺序表销毁
void SeqListDestroy(SeqList* s)
{
	assert(s);
	if (s->array)
	{
		free(s->array);
		s->array = NULL;
		s->capacity = 0;
		s->size = 0;
	}
}




//测试方式
void SeqListPrint(SeqList* s)
{
	assert(s);
	for (int i = 0; i < s->size; ++i)
		printf("%d ", s->array[i]);
	printf("\n");
}


void TestSeqList()
{
	SeqList s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);

	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);

	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);

    SeqListDestroy(&s);
}