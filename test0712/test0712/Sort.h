#pragma once

///////////////////////////////////////////////////////
// �Ƚ�������

// ��������
void InsertSort(int array[], int size);

// ϣ������
void ShellSort(int array[], int size);

// ѡ������
void SelectSort(int array[], int size);

// ������
void HeapAdjustDwon(int array[], int size, int parent);
void HeapSort(int array[], int size);

// ð������
void BubbleSort(int array[], int size);

// ��������
void QuickSort(int array[], int left, int right);

// ��������ǵݹ�
void QuickSortNor(int array[], int size);

// �鲢����
void MergeSort(int array[], int size);

// �鲢����ǵݹ飨ѭ����
void MergeSortNor(int array[], int size);


///////////////////////////////////////////////////////
// �ǱȽ�������

// ��������
void CountSort(int array[], int size);





/////////////////////////////////////////////////////////
void TestSort();

