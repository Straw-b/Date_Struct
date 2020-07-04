#include "Sort.h"
#include <stdio.h>


//打印
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

// 在整个排序过程中，没有使用额外的辅助空间，空间复杂度：O(1)
// 时间复杂度：O(N^2)
// 稳定性：稳定
void InsertSort(int array[], int size)
{
	//注意：从1开始--->原因：
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





///////////////////////////////////////////////////
void TestSort()
{
	int array[] = { 4, 1, 7, 6, 3, 9, 5, 8, 0, 2 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));

	InsertSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));

}