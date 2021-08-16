#include "Heap.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>


int Less(HDataType left, HDataType right)
{
	return left < right;
}

int Greater(HDataType left, HDataType right)
{
	return left > right;
}


// 堆的初始化--空堆
void HeapInit(Heap* hp, int initCap, CMP cmp)
{
	assert(hp);
	//初始容量
	initCap = initCap < 10 ? 10 : initCap;
	hp->array = (HDataType*)malloc(sizeof(HDataType)* initCap);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}

	hp->capacity = 10;
	hp->size = 0;
	//接收比较的方式
	hp->Cmp = cmp;
}

// 交换数据
void Swap(HDataType* left, HDataType*right)
{
	HDataType temp = *left;
	*left = *right;
	*right = temp;
}

// 向下调整
void AdjustDown(Heap* hp, int parent)
{
	// 用child标记parent的较小的孩子---默认先标记parent的左孩子
	int size = hp->size;
	int* array = hp->array;
	int child = parent * 2 + 1;
    
	//说明孩子存在
	while (child < size) 
	{
		// 找到parent的两个孩子中较小的孩子
		if (child + 1 < size && hp->Cmp(array[child + 1], array[child]))
			child += 1;

		// parent较小的孩子已将找到了，检测parent是否满足堆的性质
		if (hp->Cmp(array[child], array[parent]))
		{
			Swap(&array[child], &array[parent]);
			//调整子树
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}

// 堆的构建--用数组中的元素创建堆
void HeapCreate(Heap* hp, int* array, int size, CMP cmp)
{
	//1. 先将数组中的元素放在堆结构中
	HeapInit(hp, size, cmp);
	memcpy(hp->array, array, sizeof(HDataType)*size);
	hp->size = size;

	//2. 进行调整
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp, root);
	}
}

//  向上调整
void AdjustUp(Heap* hp, int child)
{
	HDataType* array = hp->array;
	int parent = ((child - 1) >> 1);
	while (child)
	{
		if (hp->Cmp(array[child], array[parent]))
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else
		{
			return;
		}
	}
}

//检测扩容
void CheckCapacity(Heap* hp)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		//1.开辟新空间
		int newCapacity = hp->capacity * 2;
		HDataType* temp = (HDataType*)malloc(sizeof(HDataType)* newCapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}

		//2.拷贝元素
		//memcpy(temp, hp->array, hp->size*sizeof(HDataType));
		for (int i = 0; i < hp->size; ++i)
			temp[i] = hp->array[i];

		//3.释放旧空间
		free(hp->array);

		//4.使用新空间
		hp->array = temp;
		hp->capacity = newCapacity;
	}
}


// 堆的插入
void HeapPush(Heap* hp, HDataType data)
{
	assert(hp);
	// 0. 检测是否需要扩容
	CheckCapacity(hp);

	// 1. 将新元素插入到数组的末尾，即：将新节点插入到完全二叉树的最后
	hp->array[hp->size++] = data;

	// 2. 新元素插入后，可能会破坏堆的性质
	AdjustUp(hp, hp->size - 1);
}

// 堆的删除---删除堆顶元素
void HeapPop(Heap* hp)
{
	if (HeapEmpty(hp))
		return;

	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	AdjustDown(hp, 0);
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
	HeapCreate(&hp, array, sizeof(array) / sizeof(array[0]), Greater);
	printf("heap size = %d\n", HeapSize(&hp));
	printf("heap top = %d\n", HeapTop(&hp));

	HeapPop(&hp);
	printf("heap size = %d\n", HeapSize(&hp));
	printf("heap top = %d\n", HeapTop(&hp));

	HeapPush(&hp, 0);
	HeapDestroy(&hp);
}
