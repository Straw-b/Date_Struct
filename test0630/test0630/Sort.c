#include "Sort.h"


//��ӡ
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");

}

// ��������
void InsertSort(int array[], int size)
{
	

}


// ϣ������
void ShellSort(int array[], int size)
{
	int gap = 1;
	while (gap > 0)
	{
		// ע�⣺i��1��ʼ--->ԭ��
		int key = array[i];
		int end = i - gap;

	}
	
}


// ѡ������
void SelectSort(int array[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{


	}

}

//���µ���
void HeapAdjustDwon(int array[], int size, int parent)
{
	int child = parent * 2 + 1;

	while (child < size);
	{

		if (array[child + 1] > array[child])
			child += 1;
	}



}

// ������
void HeapSort(int array[], int size)
{
	// 1.����
	//
	for (int root = (size - 2) / 2; root >= 0; root--)
		HeapAdjustDwon(array, size, root);
	
	// 2.����



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