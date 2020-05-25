#include "SeqList.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>


//初始化
void SeqListInit(SeqList* s, int initCapacity)
{
	assert(s);
	initCapacity = initCapacity <= 3 ? 3 : initCapacity;
	//10个 SDataType ---->总的字节数:sizeof(SDataType)*10
	s->array = (SDataType*)malloc(sizeof(SDataType)*initCapacity);
	if (NULL == s->array)
		return;

	s->capacity = initCapacity;
	s->size = 0;
}

//扩容
int CheckCapacity(SeqList* s)
{
	assert(s);
	if (s->size == s->capacity)
	{
		int newCapacity = s->capacity * 2;
		s->array = (SDataType*)realloc(s->array, newCapacity*sizeof(SDataType));
		if (NULL == s->array)
			return 0;
		s->capacity = newCapacity;

		////开辟新空间
		//SDataType* temp = (SDataType*)malloc(newCapacity*sizeof(SDataType));
		//if (NULL == temp)
		//	return 0;
		////拷贝元素
		//memcpy(temp, s->array, s->capacity*sizeof(SDataType));
		////释放旧空间
		//free(s->array);
		////使用新空间
		//s->array = temp;
		//s->capacity = newCapacity;
	}
	return 1;
}


// 尾插:
// 1.不需要扩容，直接将元素插入在size的位置---O(1)
// 2.需要扩容
void SeqListPushBack(SeqList* s, SDataType data)
{
	assert(s);
	//在插入之前要保证有空间
	if (!CheckCapacity(s))
		return;

	s->array[s->size++] = data;
	//s->size++;
}

// 尾删---O(1)
void SeqListPopBack(SeqList* s)
{
	if (SeqListEmpty(s))
		return;

	s->size--;
}

// 头插
// 1.先检测是否需要扩容---需要则扩容
// 2.将顺序表中所有的元素整体往后搬移一个位置
// 3.将data插入到顺序表的起始位置
// O(N)
void SeqListPushFront(SeqList* s, SDataType data)
{
	//是否需要扩容
	if (!CheckCapacity(s))
		return;

	//需要将顺序表中所有的元素向后搬移一个位置
	for (int i = s->size - 1; i >= 0; i--)
		s->array[i + 1] = s->array[i];

	//在0号位置插入data
	s->array[0] = data;
	s->size++;
}

// 头删---除第一个元素外，剩余元素整体往前搬移一个位置---O(N)
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
	assert(s);
	//1.必须保证pos在[0,size]
	if (pos < 0 || pos > s->size)
		return;
	//2.检测是否扩容
	if (!CheckCapacity(s))
		return;

	//3.将[pos,size)位置的元素整体往后搬移一个位置
	//i：表示需要搬移元素的下标
	for (int i = s->size - 1; i >= pos; --i)
		s->array[i + 1] = s->array[i];
	//4.在pos的位置插入新元素
	s->array[pos] = data;
	s->size++;
}

// 任意位置删除
void SeqListErase(SeqList* s, int pos)
{
	assert(s);
	//1.pos必须在[0,size)
	if (pos < 0 || pos >= s->size)
		return;
	//2.将pos之后的元素整体往前搬移一个位置
	for (int i = pos + 1; i < s->size; ++i)
		s->array[i - 1] = s->array[i];
	s->size--;
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



void Test1()
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

void Test2()
{
	SeqList s;
	SeqListInit(&s, 2);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPrint(&s);

	//任意位置插入
	SeqListInsert(&s, 3, 0);
	SeqListPrint(&s);

	//删除第一个元素4
	SeqListErase(&s, SeqListFind(&s, 4));
	SeqListPrint(&s);
}

void TestSeqList()
{
	//Test1();
	Test2();
}