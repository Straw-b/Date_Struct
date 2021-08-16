#pragma once


typedef int HDataType;

// ��С�Ѷ���
int Less(HDataType left, HDataType right);
int Greater(HDataType left, HDataType right);
//int Equal(HDataType left, HDataType right);

// ����ָ�����������ָ���κ�������HDataType�����Լ�һ��int���ͷ���ֵ�����к���
// Cmp�Ǻ���ָ�������Cmp������ָ��Less��Ҳ����ָ��Greater
// Cmp�����ͣ�int(*)(HDataType, HDataType)
int (*Cmp)(HDataType left, HDataType right);

// CMP����int(*)(HDataType, HDataType)���͵ı���
typedef int(*CMP)(HDataType, HDataType);


typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
	CMP Cmp; //����ָ�����
}Heap;


// �ѵĳ�ʼ��
void HeapInit(Heap* hp, int initCap, CMP cmp);
// �ѵĹ���
void HeapCreate(Heap* hp, int* array, int size, CMP cmp);
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
