#include "Sort.h"
#include <stdio.h>


//��ӡ
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");

}




// ��������
// ʱ�临�Ӷȣ�O(N^2)
// ��������������У�û��ʹ�ö���ĸ����ռ䣬�ռ临�Ӷȣ�O(1)
// �ȶ��ԣ��ȶ�
void InsertSort(int array[], int size)
{
	// ע�⣺i��1��ʼ--->ԭ��
	// ���ѭ�����ƣ��ж��ٸ�������Ҫ����size-1
	for (int i = 1; i < size; ++i)
	{
		// ģ�ⵥ��Ԫ�صĲ������
		int key = array[i];
		int end = i - 1;

		// �Ҵ�����Ԫ���������е�λ��
		// �������£���Ҫ��iλ��֮ǰ���е�Ԫ������������а��ƣ���ʱ�临�Ӷ�ΪO(N)
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			end--;
		}

		//����Ԫ��
		array[end + 1] = key;
	}
}




// ϣ������
// ʱ�临�Ӷȣ�O(N^1.25)--O(1.6N^1.25)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ����ȶ�
void ShellSort(int array[], int size)
{
	int gap = size; // �±�ļ��
	while (gap > 1)
	{
		// gap /= 2 ���� gapÿ��ȡ����
		// gap����СֵΪ1
		gap = gap / 3 + 1; //4 2 1

		// ע�⣺i��gap��ʼ����������
		for (int i = gap; i < size; ++i)
		{
			// ģ�ⵥ��Ԫ�صĲ������
			int key = array[i];
			int end = i - gap;

			// �Ҵ�����Ԫ���������е�λ��
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}

			//����Ԫ�أ����뵽��ǰ�������һ��λ��
			array[end + gap] = key;
		}
	}
}




// ѡ������
// ʱ�临�Ӷȣ�O(N^2)
// �ռ临�Ӷȣ�O(1)
// �ȶ��ԣ����ȶ�

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
		// �ҵ�ǰ���������Ԫ�ص�λ��
		int maxPos = 0;
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}

		// ����
		if (maxPos != size - i - 1)
		{
			Swap(&array[maxPos], &array[size - i - 1]);
		}
	}
}


// ѡ������Ľ�
void SelectSortOP(int array[], int size)
{
	int begin = 0, end = size - 1; // [begin end]
	while (begin < end)
	{
		// ��[begin end]��������������С��Ԫ��
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
		
		// ������Ԫ�ز�����������λ��
		if (maxPos != end)
		{
			Swap(&array[maxPos], &array[end]);
		}

		// ���endλ�ô洢�ĸպ�����СԪ�أ�����Ľ����ͽ���С��λ�ø�����
		// ��СԪ�ص�λ�÷����ı䣬��������minPos
		if (minPos == end)
			minPos = maxPos;

		// �����СԪ�ز���������ʼ���λ��
		if (minPos != begin)
		{
			Swap(&array[minPos], &array[begin]);
		}	

		++begin;
		--end;
	}
}




// ������

// ���µ���
void HeapAdjustDwon(int array[], int size, int parent)
{
	// ��child���parent�ϴ�ĺ��ӣ�Ĭ���ȱ��parent������
	int child = parent * 2 + 1;

	while (child < size)
	{
		// ��parent�нϴ�ĺ��ӣ���parent���Һ��ӱȽ�
		// �����ȱ�֤parent���Һ��Ӵ���
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;

		// ���parent�Ƿ�����ѵ����ʣ����
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
	// 1.����
	// �ӵ�����һ����Ҷ�ӽڵ��λ�ÿ�ʼʹ�öѵ�����һֱ���������ڵ��λ��
	for (int root = (size - 2) / 2; root >= 0; root--)
		HeapAdjustDwon(array, size, root); //���µ���
	
	// 2.����-->���ö�ɾ����˼������
	while (end)
	{
		//�Ѷ�Ϊ���Ԫ�طŵ����λ��
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