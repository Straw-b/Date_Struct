#include "SeqList.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>


//��ʼ��
void SeqListInit(SeqList* s, int initCapacity)
{
	assert(s);
	initCapacity = initCapacity <= 10 ? 10 : initCapacity;
	//10�� SDataType ---->�ܵ��ֽ���:sizeof(SDataType)*10
	s->array = (SDataType*)malloc(sizeof(SDataType)*initCapacity);
	if (NULL == s->array)
		return;

	s->capacity = initCapacity;
	s->size = 0;
}

// β��
void SeqListPushBack(SeqList* s, SDataType data)
{
	assert(s);
	//�ڲ���֮ǰҪ��֤�пռ�
	s->array[s->size++] = data;
	//s->size++;
}

// βɾ
void SeqListPopBack(SeqList* s)
{
	if (SeqListEmpty(s))
		return;

	s->size--;
}

// ͷ��
void SeqListPushFront(SeqList* s, SDataType data)
{
	//�Ƿ���Ҫ����

	//��Ҫ��˳��������е�Ԫ��������һ��λ��
	for (int i = s->size - 1; i >= 0; i--)
		s->array[i+1] = s->array[i];

	//��0��λ�ò���data
	s->array[0] = data;
	s->size++;
}

// ͷɾ
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

}

// ����λ��ɾ��
void SeqListErase(SeqList* s, int pos)
{

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