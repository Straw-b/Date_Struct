#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//4. ��ת����
//����˼·��ʹ��������ת������������תk��
//1. ��������ת
//2. ��ת������[0, k - 1]
//3. ��ת������[k, size - 1]

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
//		k %= numsSize; //��Чλ
//	}
//
//	reverse(nums, 0, numsSize - 1);
//	reverse(nums, 0, k - 1);
//	reverse(nums, k, numsSize - 1);
//}





////5. ������ʽ�������ӷ�
//int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
//{
//	int size = ASize > 5 ? ASize + 1 : 5 + 1;
//	int* ret = calloc(size, sizeof(int));
//
//	//��ʾ����֮�������ܵ�λ��
//	int total = 0;
//	//�������е�ÿһλ��K
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
//	//���K��A�����е����ݳ���K�л���ʣ������
//	while (K > 0)
//	{
//		ret[retIdx--] = K % 10;
//		K /= 10;
//		total++;
//	}
//
//	//��ǰ������ЧԪ��
//	if (total < size)
//	{
//		memmove(ret, ret + (size - total), total*sizeof(int));
//		//void *memmove(void *dest, const void *src, size_t count);
//	}
//
//	*returnSize = total;
//	return ret;
//}




////C�����д��εķ�ʽ
////ֵ����
//void Swap(int left, int right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
////����ַ
//void Swap(int* pa, int* pb)
//{
//	int temp = *pa;
//	*pa = *pb;
//	*pb = temp;
//}
//
////��Swap��������������ⲿ����ָ��ʵ�ε�ָ�򣬱��봫�ݶ���ָ��
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
//	//ͨ��Swap��������p1��p2����ָ���ָ��
//	Swap(&p1, &p2);//p1������int* , &p1--->int**
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
