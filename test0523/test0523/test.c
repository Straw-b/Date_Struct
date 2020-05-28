#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//讨论题
//void PrintArray(int* array, int size)
void PrintArray(int array[], int size)
{
	printf("%d\n",sizeof(array) / sizeof(array[0]));
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	int array[] = { 1, 2, 3, 4, 5 };
	int* p1 = (int*)(&array + 1);
	int* p2 = (int*)(array + 1);
	char* p3 = NULL;

	int a = p1[-2] + *p2 + sizeof(&array) + sizeof(*p3);//4+2+4+1//p3是空指针，实则是char
	//printf("%d\n", *p3);
	printf("%d\n", a);//11

	//int* p4 = &array;//err

	//在传参期间数组名已经退化为首元素的地址
	PrintArray(array, sizeof(array) / sizeof(array[0]));

	return 0;
}






//数组相关面试题
//4. 旋转数组




//5. 数组形式的整数加法
