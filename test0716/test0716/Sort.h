#pragma once

///////////////////////////////////////////////////////
// 比较类排序

// 插入排序
void InsertSort(int array[], int size);

// 希尔排序
void ShellSort(int array[], int size);

// 选择排序
void SelectSort(int array[], int size);

// 堆排序
void HeapAdjustDwon(int array[], int size, int parent);
void HeapSort(int array[], int size);

// 冒泡排序
void BubbleSort(int array[], int size);

// 快速排序
void QuickSort(int array[], int left, int right);

// 快速排序非递归
void QuickSortNor(int array[], int size);

// 归并排序
void MergeSort(int array[], int size);

// 归并排序非递归（循环）
void MergeSortNor(int array[], int size);


///////////////////////////////////////////////////////
// 非比较类排序

// 计数排序
void CountSort(int array[], int size);





/////////////////////////////////////////////////////////
void TestSort();

