#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//4. 旋转数组
//解题思路：使用三次逆转法，让数组旋转k次
//1. 先整体逆转
//2. 逆转子数组[0, k - 1]
//3. 逆转子数组[k, size - 1]

//void reverse(int* nums, int begin, int end)
//{
//	while (begin < end)
//	{
//		int tmp = nums[begin];
//		nums[begin] = nums[end];
//		nums[end] = tmp;
//		++begin;
//		--end;
//	}
//}
//
//void rotate(int* nums, int numsSize, int k){
//	if (k > numsSize)
//	{
//		k %= numsSize; //有效位
//	}
//
//	reverse(nums, 0, numsSize - 1);
//	reverse(nums, 0, k - 1);
//	reverse(nums, k, numsSize - 1);
//}





////5. 数组形式的整数加法
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
//{
//	int size = ASize > 5 ? ASize + 1 : 5 + 1;
//	int* ret = calloc(size, sizeof(int));
//
//	//表示加完之后数据总的位数
//	int total = 0;
//	//用数组中的每一位加K
//	int retIdx = size - 1;
//	while (ASize > 0)
//	{
//		K += A[ASize - 1];
//		ret[retIdx--] = K % 10;
//		K /= 10;
//		total++;
//		ASize--;
//	}
//
//	//如果K比A数组中的数据长，K中还有剩余数据
//	while (K > 0)
//	{
//		ret[retIdx--] = K % 10;
//		K /= 10;
//		total++;
//	}
//
//	//往前搬移有效元素
//	if (total < size)
//	{
//		memmove(ret, ret + (size - total), total*sizeof(int));
//		//void *memmove(void *dest, const void *src, size_t count);
//	}
//
//	*returnSize = total;
//	return ret;
//}




////C语言中传参的方式
////值传递
//void Swap(int left, int right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
////传地址
//void Swap(int* pa, int* pb)
//{
//	int temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//}
//
////在Swap函数中如果交换外部两个指针实参的指向，必须传递二级指针
//void Swap(int** pleft, int** pright)
//{
//	int* temp = *pleft;
//	*pleft = *pright;
//	*pright = temp;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//
//	//Swap(a, b);
//	//Swap(&a, &b);
//
//	int* p1 = &a;
//	int* p2 = &b;
//
//	//通过Swap函数交换p1和p2两个指针的指向
//	Swap(&p1, &p2);//p1的类型int* , &p1--->int**
//
//	printf("a = %d,b = %d\n", a, b);
//	return 0;
//}





#include "SLish.h"

int main()
{
	TestSList();
	return 0;
}
