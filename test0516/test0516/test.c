#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//ʱ�临�Ӷ�

//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//
//
//void Func2(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//
//
//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k)
//	{
//		++count;
//	}
//	for (int k = 0; k < N; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//
//
//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//
//
//int main()
//{
//	Func1(10);
//	Func2(10);
//	Func3(10,10);
//	Func4(10);
//	return 0;
//}



//// ����strchr��ʱ�临�Ӷ�
//const char * strchr(const char * str, int character);



//// ����BubbleSort��ʱ�临�Ӷ�
//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}



//// ����BinarySearch��ʱ�临�Ӷ�
//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	int begin = 0;
//	int end = n - 1;
//	while (begin < end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid;
//		else
//			return mid;
//	}
//	return -1;
//}



//// ����׳˵ݹ�Factorial��ʱ�临�Ӷ�
//long long Factorial(size_t N)
//{
//	return N < 2 ? N : Factorial(N - 1)*N;
//}



//// ����쳲������ݹ�Fibonacci��ʱ�临�Ӷ�
//long long Fibonacci(size_t N)
//{
//	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
//}

