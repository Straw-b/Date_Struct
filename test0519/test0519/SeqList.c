#include "SeqList.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>


//��ʼ��
void SeqListInit(SeqList* s, int initCapacity)
{
	assert(s);
	initCapacity = initCapacity <= 3 ? 3 : initCapacity;
	//10�� SDataType ---->�ܵ��ֽ���:sizeof(SDataType)*10
	s->array = (SDataType*)malloc(sizeof(SDataType)*initCapacity);
	if (NULL == s->array)
		return;

	s->capacity = initCapacity;
	s->size = 0;
}

//����
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

		////�����¿ռ�
		//SDataType* temp = (SDataType*)malloc(newCapacity*sizeof(SDataType));
		//if (NULL == temp)
		//	return 0;
		////����Ԫ��
		//memcpy(temp, s->array, s->capacity*sizeof(SDataType));
		////�ͷžɿռ�
		//free(s->array);
		////ʹ���¿ռ�
		//s->array = temp;
		//s->capacity = newCapacity;
	}
	return 1;
}


// β��:
// 1.����Ҫ���ݣ�ֱ�ӽ�Ԫ�ز�����size��λ��---O(1)
// 2.��Ҫ����
void SeqListPushBack(SeqList* s, SDataType data)
{
	assert(s);
	//�ڲ���֮ǰҪ��֤�пռ�
	if (!CheckCapacity(s))
		return;

	s->array[s->size++] = data;
	//s->size++;
}

// βɾ---O(1)
void SeqListPopBack(SeqList* s)
{
	if (SeqListEmpty(s))
		return;

	s->size--;
}

// ͷ��
// 1.�ȼ���Ƿ���Ҫ����---��Ҫ������
// 2.��˳��������е�Ԫ�������������һ��λ��
// 3.��data���뵽˳������ʼλ��
// O(N)
void SeqListPushFront(SeqList* s, SDataType data)
{
	//�Ƿ���Ҫ����
	if (!CheckCapacity(s))
		return;

	//��Ҫ��˳��������е�Ԫ��������һ��λ��
	for (int i = s->size - 1; i >= 0; i--)
		s->array[i + 1] = s->array[i];

	//��0��λ�ò���data
	s->array[0] = data;
	s->size++;
}

// ͷɾ---����һ��Ԫ���⣬ʣ��Ԫ��������ǰ����һ��λ��---O(N)
void SeqListPopFront(SeqList* s)
{
	if (SeqListEmpty(s))
		return;

	for (int i = 1; i < s->size; ++i)
		s->array[i - 1] = s->array[i];
	s->size--;
}

// ����λ�ò���
void SeqListInsert(SeqList* s, int pos, SDataType data)
{
	assert(s);
	//1.���뱣֤pos��[0,size]
	if (pos < 0 || pos > s->size)
		return;
	//2.����Ƿ�����
	if (!CheckCapacity(s))
		return;

	//3.��[pos,size)λ�õ�Ԫ�������������һ��λ��
	//i����ʾ��Ҫ����Ԫ�ص��±�
	for (int i = s->size - 1; i >= pos; --i)
		s->array[i + 1] = s->array[i];
	//4.��pos��λ�ò�����Ԫ��
	s->array[pos] = data;
	s->size++;
}

// ����λ��ɾ��
void SeqListErase(SeqList* s, int pos)
{
	assert(s);
	//1.pos������[0,size)
	if (pos < 0 || pos >= s->size)
		return;
	//2.��pos֮���Ԫ��������ǰ����һ��λ��
	for (int i = pos + 1; i < s->size; ++i)
		s->array[i - 1] = s->array[i];
	s->size--;
}

// ��ȡ˳�������ЧԪ�ظ���
int SeqListSize(SeqList* s)
{
	assert(s);
	return s->size;
}

// ��ȡ˳��������
int SeqListCapacity(SeqList* s)
{
	assert(s);
	return s->capacity;
}

// ���˳����Ƿ�Ϊ��
int SeqListEmpty(SeqList* s)
{
	assert(s);
	return 0 == s->size;
}

// ˳������
void SeqListClear(SeqList* s)
{
	assert(s);
	s->size = 0;
}

// ����ֵΪdata��Ԫ���Ƿ���˳����У�����ڷ����±꣬���򷵻�-1
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

// ˳�������
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




//���Է�ʽ
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

	//����λ�ò���
	SeqListInsert(&s, 3, 0);
	SeqListPrint(&s);

	//ɾ����һ��Ԫ��4
	SeqListErase(&s, SeqListFind(&s, 4));
	SeqListPrint(&s);
}

void TestSeqList()
{
	//Test1();
	Test2();
}