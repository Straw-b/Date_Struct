#pragma once


typedef int HDataType;

// 大小堆定义
int Less(HDataType left, HDataType right);
int Greater(HDataType left, HDataType right);
//int Equal(HDataType left, HDataType right);

// 函数指针变量：可以指向任何有两个HDataType参数以及一个int类型返回值的所有函数
// Cmp是函数指针变量：Cmp即可以指向Less，也可以指向Greater
// Cmp的类型：int(*)(HDataType, HDataType)
int (*Cmp)(HDataType left, HDataType right);

// CMP就是int(*)(HDataType, HDataType)类型的别名
typedef int(*CMP)(HDataType, HDataType);


typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
	CMP Cmp; //函数指针变量
}Heap;


// 堆的初始化
void HeapInit(Heap* hp, int initCap, CMP cmp);
// 堆的构建
void HeapCreate(Heap* hp, int* array, int size, CMP cmp);
// 堆的插入
void HeapPush(Heap* hp, HDataType data);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HDataType HeapTop(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的销毁
void HeapDestroy(Heap* hp);

//// 对数组进行堆排序
//void HeapSort(int* a, int n);


////////////////////////////////////////////////////
void TestHeap();
