#pragma once

typedef int DLDataType;

typedef struct DHCListNode
{
	DLDataType data;
	struct DHCListNode* next;//指向当前节点的下一个节点
	struct DHCListNode* prev;//指向当前节点的前一个节点
}DHCLNode;


//初始化
DHCLNode* DHCListInit();


void DHCListPushBack(DHCLNode* pHhead, DLDataType data);
void DHCListPopBack(DHCLNode** head);

void SListPushFront(SListNode** head, SLDataType data);
void SListPopFront(SListNode** head);

void SListInsertAfter(SListNode* pos, SLDataType data);
void SListEraseAfter(SListNode* pos);

int SListSize(SListNode* head);

int SListEmpty(SListNode* head);

SListNode* SListFind(SListNode* head, SLDataType data);

void SListDestroy(SListNode** head);


//////////////////////////////////////////////////////////////////////////////
void TestSList();