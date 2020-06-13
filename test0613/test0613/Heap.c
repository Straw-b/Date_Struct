#include "Heap.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>


// 堆的初始化--空堆
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
	//用child标记parent的较小的孩子---默认先标记parent的左孩子
	int child = parent * 2 + 1;

	while (child < size)
	{
		// 找到parent的两个孩子中较小的孩子
		if (child + 1 < size && array[child + 1] < array[child])
			child += 1;

		// parent较小的孩子已将找到了
		// 检测parent是否满足堆的性质
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

// 堆的构建--用数组中的元素创建堆
void HeapCreate(Heap* hp, int* array, int size)
{
	//1. 先将数组中的元素放在堆结构中
	HeapInit(hp, size);
	memcpy(hp->array, array, sizeof(HDataType)*size);
	hp->size = size;

	//2. 进行调整
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp->array, hp->size, root);
	}
}

// 堆的插入
void HeapPush(Heap* hp, HDataType data);

// 堆的删除
void HeapPop(Heap* hp)
{
	if (HeapEmpty(hp))
		return;

	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	AdjustDown(hp->array, hp->size, 0);
}

// 取堆顶的数据
HDataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}

// 堆的判空,堆为空返回非0值
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}

// 堆的数据个数
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}

// 堆的销毁
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}


//// 对数组进行堆排序
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
