#include "Sort.h"
#include <stdio.h>


//��ӡ
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

// ��������������У�û��ʹ�ö���ĸ����ռ䣬�ռ临�Ӷȣ�O(1)
// ʱ�临�Ӷȣ�O(N^2)
// �ȶ��ԣ��ȶ�
void InsertSort(int array[], int size)
{
	//ע�⣺��1��ʼ--->ԭ��
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





///////////////////////////////////////////////////
void TestSort()
{
	int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));

	InsertSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));

}