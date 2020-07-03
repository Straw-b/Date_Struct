#include "Sort.h"


//打印
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");

}

// 插入排序
void InsertSort(int array[], int size)
{
	

}


// 希尔排序
void ShellSort(int array[], int size)
{
	int gap = 1;
	while (gap > 0)
	{
		// 注意：i从1开始--->原因
		int key = array[i];
		int end = i - gap;

	}
	
}


// 选择排序
void SelectSort(int array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{


	}

}

//向下调整
void HeapAdjustDwon(int array[], int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size);
	{

		if (array[child + 1] > array[child])
			child += 1;
	}



}

// 堆排序
void HeapSort(int array[], int size)
{
	// 1.建堆
	//
	for (int root = (size - 2) / 2; root >= 0; root--)
		HeapAdjustDwon(array, size, root);
	
	// 2.排序



}





///////////////////////////////////////////////////
void TestSort()
{
	int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));

	InsertSort(array, sizeof(array) / sizeof(array[0]));

	ShellSort(array, sizeof(array) / sizeof(array[0]));

	SelectSort(array, sizeof(array) / sizeof(array[0]));

	PrintArray(array, sizeof(array) / sizeof(array[0]));

}