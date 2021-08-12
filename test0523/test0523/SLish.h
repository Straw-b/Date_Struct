#pragma once


typedef int SLDataType;

typedef struct SListNode
{
	struct SListNode* next; //指向下一个节点的地址
	SLDataType data; //存储该节点中的数据
}SListNode;


void SListPushBack(SListNode** head, SLDataType data);
void SListPopBack(SListNode** head);

void SListPushFront(SListNode** head, SLDataType data);
void SListPopFront(SListNode** head);

void SListInsert(SListNode* pos, SLDataType data);

void SListErase(SListNode* pos);

int SListSize(SListNode* head);

int SListEmpty(SListNode* head);

SListNode* SListFind(SListNode* head, SLDataType data);

void SListDestroy(SListNode** head);


//////////////////////////////////////////////////////////////////////////////
void TestSList();