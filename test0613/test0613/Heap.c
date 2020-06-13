#include "Heap.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>


// �ѵĳ�ʼ��--�ն�
void HeapInit(Heap* hp, int initCap)
{
	assert(hp);
	initCap = initCap < 10 ? 10 : initCap;
	hp->array = (HDataType*)malloc(sizeof(HDataType)* initCap);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}

	hp->capacity = 10;
	hp->size = 0;
}

void Swap(HDataType* left, HDataType*right)
{
	HDataType temp = *left;
	*left = *right;
	*right = temp;
}

void AdjustDown(HDataType* array, int size, int parent)
{
	//��child���parent�Ľ�С�ĺ���---Ĭ���ȱ��parent������
	int child = parent * 2 + 1;

	while (child < size)
	{
		// �ҵ�parent�����������н�С�ĺ���
		if (child + 1 < size && array[child + 1] < array[child])
			child += 1;

		// parent��С�ĺ����ѽ��ҵ���
		// ���parent�Ƿ�����ѵ�����
		if (array[child] < array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

// �ѵĹ���--�������е�Ԫ�ش�����
void HeapCreate(Heap* hp, int* array, int size)
{
	//1. �Ƚ������е�Ԫ�ط��ڶѽṹ��
	HeapInit(hp, size);
	memcpy(hp->array, array, sizeof(HDataType)*size);
	hp->size = size;

	//2. ���е���
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp->array, hp->size, root);
	}
}

// �ѵĲ���
void HeapPush(Heap* hp, HDataType data);

// �ѵ�ɾ��
void HeapPop(Heap* hp)
{
	if (HeapEmpty(hp))
		return;

	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->array, hp->size, 0);
}

// ȡ�Ѷ�������
HDataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}

// �ѵ��п�,��Ϊ�շ��ط�0ֵ
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}

// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

// �ѵ�����
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}


//// ��������ж�����
//void HeapSort(int* a, int n);


////////////////////////////////////////////////////
void TestHeap()
{
	int array[] = { 3, 6, 9, 1, 5, 2, 0, 7, 8, 4 };
	Heap hp;
	HeapCreate(&hp, array, sizeof(array) / sizeof(array[0]));
	printf("heap size = %d\n", HeapSize(&hp));
	printf("heap top = %d\n", HeapTop(&hp));

	HeapPop(&hp);
	printf("heap size = %d\n", HeapSize(&hp));
	printf("heap top = %d\n", HeapTop(&hp));

	HeapDestroy(&hp);
}
