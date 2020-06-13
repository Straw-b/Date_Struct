#pragma once


typedef int HDataType;

typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
}Heap;


// 堆的初始化
void HeapInit(Heap* hp, int initCap);
// 堆的构建
void HeapCreate(Heap* hp, int* array, int size);
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
