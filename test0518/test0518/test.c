#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//long long Fib(int n)
//{
//	long long first = 1, second = 1, ret = 1;
//	for (int i = 3; i <= n; i++)
//	{
//		ret = first + second;
//		first = second;
//		second = ret;
//	}
//	return ret;
//}
//
//int main()
//{
//	printf("%d", Fib(10));
//	return 0;
//}





//�ϲ�������������
//ʱ�临�Ӷȣ�O(M+N)
//�ռ临�Ӷȣ�O(M+N)

//#include <malloc.h>
//
//int* MergeData(int array1[], int size1, int array2[], int size2)
//{
//	int index1 = 0;
//	int index2 = 0;
//	int index = 0;
//	int* array = (int*) malloc((size1 + size2)*sizeof(array1[0]));
//	if (NULL == array)
//		return NULL;
//
//	while (index1 < size1 && index2 < size2)
//	{
//		if (array1[index1] <= array2[index2])
//			array[index++] = array1[index1++];
//		else
//			array[index++] = array2[index2++];
//	}
//	while (index1 < size1)
//		array[index++] = array1[index1++];
//
//	while (index2 < size2)
//		array[index++] = array2[index2++];
//	return array;
//}
//
//int main()
//{
//	int array1[] = { 2, 5, 6, 8 };
//	int array2[] = { 1, 3, 5, 7, 8, 9 };
//	int* array = MergeData( array1, sizeof(array1) / sizeof(array1[0]), 
//		array2, sizeof(array2) / sizeof(array2[0]) );
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", array[i]);
//	}
//	printf("\n");
//	free(array);
//	array = NULL;
//	return  0;
//}




//// ˳���ľ�̬�洢
//#define N 100
//typedef int SLDataType;
//typedef struct SeqList
//{
//	SLDataType array[N]; // ��������
//		size_t size; // ��Ч���ݵĸ���
//}SeqList;
//
//// ˳���Ķ�̬�洢
//typedef struct SeqList
//{
//	SLDataType* array; // ָ��̬���ٵ�����
//	size_t size; // ��Ч���ݸ���
//	size_t capicity; // �����ռ�Ĵ�С
//}SeqList;




#include "SeqList.h"

int main()
{
	TestSeqList();
	return 0;
}