#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


//������
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

	int a = p1[-2] + *p2 + sizeof(&array) + sizeof(*p3);//4+2+4+1//p3�ǿ�ָ�룬ʵ����char
	//printf("%d\n", *p3);
	printf("%d\n", a);//11

	//int* p4 = &array;//err

	//�ڴ����ڼ��������Ѿ��˻�Ϊ��Ԫ�صĵ�ַ
	PrintArray(array, sizeof(array) / sizeof(array[0]));

	return 0;
}






//�������������
//4. ��ת����




//5. ������ʽ�������ӷ�
