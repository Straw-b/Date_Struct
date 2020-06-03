#pragma once

typedef int DLDataType;

typedef struct DHCListNode
{
	DLDataType data;
	struct DHCListNode* next;//ָ��ǰ�ڵ����һ���ڵ�
	struct DHCListNode* prev;//ָ��ǰ�ڵ��ǰһ���ڵ�
}DHCLNode;


//��ʼ��
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