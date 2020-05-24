#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <malloc.h>
//
////合并两个有序数组
////时间复杂度：O(M+N)
////空间复杂度：O(M+N)
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




//// 顺序表的静态存储
//#define N 100
//typedef int SLDataType;
//typedef struct SeqList
//{
//	SLDataType array[N]; // 定长数组
//		size_t size; // 有效数据的个数
//}SeqList;
//
//// 顺序表的动态存储
//typedef struct SeqList
//{
//	SLDataType* array; // 指向动态开辟的数组
//	size_t size; // 有效数据个数
//	size_t capicity; // 容量空间的大小
//}SeqList;





#include "SeqList.h"

int main()
{
	TestSeqList();
	return 0;
}