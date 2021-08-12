#pragma once


typedef int SDataType;
//typedef double SDataType;

typedef struct SeqList //取别名
{
	SDataType* array; //存放元素的空间，不够时申请更大的
	int size; // 空间中有效元素的个数
    int capacity;  //空间总的大小	
}SeqList;


//初始化
void SeqListInit(SeqList* s, int initCapacity);

// 尾插
void SeqListPushBack(SeqList* s, SDataType data);

// 尾删
void SeqListPopBack(SeqList* s);

// 头插
void SeqListPushFront(SeqList* s, SDataType data);

// 头删
void SeqListPopFront(SeqList* s);

// 任意位置插入
void SeqListInsert(SeqList* s, int pos, SDataType data);

// 任意位置删除
void SeqListErase(SeqList* s, int pos);

// 获取顺序表中有效元素个数
int SeqListSize(SeqList* s);

// 获取顺序表的容量
int SeqListCapacity(SeqList* s);

// 检测顺序表是否为空
int SeqListEmpty(SeqList* s);

// 顺序表清空
void SeqListClear(SeqList* s);

// 查找值为data的元素是否在顺序表中，如果在返回下标，否则返回-1
int SeqListFind(SeqList* s, SDataType data);

// 顺序表销毁
void SeqListDestroy(SeqList* s);




// 测试方法
void TestSeqList();