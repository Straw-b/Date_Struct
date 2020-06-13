#pragma once


typedef int HDataType;

typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
}Heap;


// �ѵĳ�ʼ��
void HeapInit(Heap* hp, int initCap);
// �ѵĹ���
void HeapCreate(Heap* hp, int* array, int size);
// �ѵĲ���
void HeapPush(Heap* hp, HDataType data);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HDataType HeapTop(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ�����
void HeapDestroy(Heap* hp);

//// ��������ж�����
//void HeapSort(int* a, int n);


////////////////////////////////////////////////////
void TestHeap();
