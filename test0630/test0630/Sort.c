#include "Sort.h"
#include <stdio.h>


//打印
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");

}




// 插入排序
// 时间复杂度：O(N^2)
// 在整个排序过程中，没有使用额外的辅助空间，空间复杂度：O(1)
// 稳定性：稳定
void InsertSort(int array[], int size)
{
	// 注意：i从1开始--->原因：
	// 外层循环控制：有多少个数据需要插入size-1
	for (int i = 1; i < size; ++i)
	{
		// 模拟单个元素的插入过程
		int key = array[i];
		int end = i - 1;

		// 找待插入元素在区间中的位置
		// 最差情况下：需要将i位置之前所有的元素整体往后进行搬移，数时间复杂度为O(N)
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			end--;
		}

		//插入元素
		array[end + 1] = key;
	}
}




// 希尔排序
// 时间复杂度：O(N^1.25)--O(1.6N^1.25)
// 空间复杂度：O(1)
// 稳定性：不稳定
void ShellSort(int array[], int size)
{
	int gap = size; // 下标的间隔
	while (gap > 1)
	{
		// gap /= 2 或者 gap每次取素数
		// gap的最小值为1
		gap = gap / 3 + 1; //4 2 1

		// 注意：i从gap开始，交替排序
		for (int i = gap; i < size; ++i)
		{
			// 模拟单个元素的插入过程
			int key = array[i];
			int end = i - gap;

			// 找待插入元素在区间中的位置
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}

			//插入元素：插入到当前分组的下一个位置
			array[end + gap] = key;
		}
	}
}




// 选择排序
// 时间复杂度：O(N^2)
// 空间复杂度：O(1)
// 稳定性：不稳定

void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void SelectSort(int array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		// 找当前区间中最大元素的位置
		int maxPos = 0;
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}

		// 交换
		if (maxPos != size - i - 1)
		{
			Swap(&array[maxPos], &array[size - i - 1]);
		}
	}
}


// 选择排序改进
void SelectSortOP(int array[], int size)
{
	int begin = 0, end = size - 1; // [begin end]
	while (begin < end)
	{
		// 在[begin end]区间中找最大和最小的元素
		int maxPos = begin, minPos = begin;
		int  j = begin + 1;

		while (j <= end)
		{
			if (array[j] > array[maxPos])
				maxPos = j;

			if (array[j] < array[minPos])
				minPos = j;

			++j;
		}
		
		// 如果最大元素不在区间最后的位置
		if (maxPos != end)
		{
			Swap(&array[maxPos], &array[end]);
		}

		// 如果end位置存储的刚好是最小元素，上面的交换就将最小的位置更改了
		// 最小元素的位置发生改变，则必须更新minPos
		if (minPos == end)
			minPos = maxPos;

		// 如果最小元素不在区间起始后的位置
		if (minPos != begin)
		{
			Swap(&array[minPos], &array[begin]);
		}	

		++begin;
		--end;
	}
}




// 堆排序

// 向下调整
void HeapAdjustDwon(int array[], int size, int parent)
{
	// 用child标记parent较大的孩子，默认先标记parent的左孩子
	int child = parent * 2 + 1;

	while (child < size)
	{
		// 找parent中较大的孩子：用parent左右孩子比较
		// 必须先保证parent的右孩子存在
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;

		// 检测parent是否满足堆的性质，大堆
		if (array[child] > array[parent])
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}	
	}
}

void HeapSort(int array[], int size)
{
	int end = size - 1;
	// 1.建堆
	// 从倒数第一个非叶子节点的位置开始使用堆调整，一直调整到根节点的位置
	for (int root = (size - 2) / 2; root >= 0; root--)
		HeapAdjustDwon(array, size, root); //向下调整
	
	// 2.排序-->利用堆删除的思想排序
	while (end)
	{
		//堆顶为最大元素放到最后位置
		Swap(&array[0], &array[end]);
		HeapAdjustDwon(array, end, 0);
		end--;
	}
}




////////////////////////////////////////////////////////////////////
void TestSort()
{
	int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintArray(array, size);

	//InsertSort(array, size);
	//ShellSort(array, size);
	//SelectSort(array, size);
	//SelectSortOP(array, size);
	HeapSort(array, size);

	PrintArray(array, size);
}