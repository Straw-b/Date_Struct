#include "SLish.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>


//申请一个节点
SListNode* BuySListNode(SLDataType data)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == newNode)
	{
		assert(0); //调试宏，参数为0宏就会触发
		return NULL;
	}

	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

//尾插
void SListPushBack(SListNode** head, SLDataType data)
{
	assert(head);
	//空链表
	SListNode* newNode = BuySListNode(data);
	if (NULL == *head)
	{
		*head = newNode;
	}
	else
	{
		//1.找到链表中的最后一个节点
		SListNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		//2.插入新节点
		cur->next = newNode;
	}
}

void SListPopBack(SListNode** head);

void SListPushFront(SListNode** head, SLDataType data);

void SListPopFront(SListNode** head);

void SListInsert(SListNode* pos, SLDataType data);

void SListErase(SListNode* pos);

int SListSize(SListNode* head);

int SListEmpty(SListNode* head);

SListNode* SListFind(SListNode* list, SLDataType data);

void SListDestroy(SListNode** head);



//////////////////////////////////////////////////////////////////////////////
void PrintSList(SListNode* head)
{
	SListNode* cur = head;
	while (cur)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void TestSList()
{
	SListNode* head = NULL;
	SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPushBack(&head, 5);

	PrintSList(head);
}