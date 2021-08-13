#include "SLish.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>


//申请一个新节点
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

//尾删
void SListPopBack(SListNode** head)
{
	assert(head);//检测非法情况
	if (NULL == *head)
	{
		//空链表
		return;
	}
	else if (NULL == (*head)->next)
	{
		//只有一个节点
		free(*head);
		*head = NULL;
	}
	else
	{
		//链表非空---至少有一个节点
		SListNode* cur = *head;
		SListNode* prev = NULL;//标记cur的前一个节点
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		//找到最后一个节点,删除
		free(cur);
	}
}

//头插
void SListPushFront(SListNode** head, SLDataType data)
{
	assert(head);
	SListNode* newNode = BuySListNode(data);
	
	newNode->next = *head;
	*head = newNode;

	////1.空链表
	//if (NULL == *head)
	//{
	//	*head = newNode;
	//}
	////2.多个节点
	//else
	//{
	//	newNode->next = *head;
	//	*head = newNode;
	//}
}

//头删
void SListPopFront(SListNode** head)
{
	SListNode* delNode = NULL;
	assert(head);
	if (NULL == *head)
	{
		return;//空链表
	}
	
	delNode = *head;
	*head = delNode->next;
	free(delNode);
	
	//else if (NULL == (*head)->next)
	//{
	//	//只有一个节点
	//	free(*head);
	//	*head = NULL;
	//}
	//else
	//{
	//	//链表非空---有多个节点
	//	SListNode* delNode = *head;
	//	*head = delNode->next;
	//	free(delNode);
	//}

}

void SListInsertAfter(SListNode* pos, SLDataType data)
{
	SListNode* newNode = NULL;
	if (NULL == pos)
		return;
	newNode = BuySListNode(data);
	newNode->next = pos->next;
	pos->next = newNode;
}

void SListEraseAfter(SListNode* pos)
{
	SListNode* delNode = NULL;
	if (NULL == pos || NULL == pos->next)
		return;
	delNode = pos->next;
	pos->next = delNode->next;
	free(delNode);
}

int SListSize(SListNode* head)
{
	//if (NULL == head)
	//	return 0;
	SListNode* cur = head;
	int count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

int SListEmpty(SListNode* head)
{
	return NULL == head;
}

SListNode* SListFind(SListNode* head, SLDataType data)
{
	SListNode* cur = head;
	while (cur)
	{
		if (cur->data == data)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void SListDestroy(SListNode** head)
{
	SListNode* delNode = NULL;
	assert(head);
	while (*head)  
	{
		delNode = *head;
		*head = delNode->next;
		free(delNode);
	}
}


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

void Test1()
{
	SListNode* listhead = NULL;
	SListPushBack(&listhead, 1);
	SListPushBack(&listhead, 2);
	SListPushBack(&listhead, 3);
	SListPushBack(&listhead, 4);
	SListPushBack(&listhead, 5);

	//SListPushBack(NULL, 5);//非法调用

	SListPopBack(&listhead);
	SListPopBack(&listhead);
	SListPopBack(&listhead);
	SListPopBack(&listhead);
	SListPopBack(&listhead);
	SListPopBack(&listhead);

	PrintSList(listhead);

	SListDestroy(&listhead);
}

void Test2()
{
	SListNode* listhead = NULL;
	SListPushFront(&listhead, 1);
	SListPushFront(&listhead, 2);
	SListPushFront(&listhead, 3);
	SListPushFront(&listhead, 4);
	SListPushFront(&listhead, 5);

	PrintSList(listhead);

	SListDestroy(&listhead);
}

void Test3()
{
	SListNode* listhead = NULL;
	SListPushBack(&listhead, 1);
	SListPushBack(&listhead, 2);
	SListPushBack(&listhead, 3);
	SListPushBack(&listhead, 4);
	SListPushBack(&listhead, 5);

	printf("%d\n", SListSize(listhead));

	SListInsertAfter(SListFind(listhead, 3), 0);
	PrintSList(listhead);
	SListInsertAfter(SListFind(listhead, 100), 10);
	PrintSList(listhead);

	SListEraseAfter(SListFind(listhead, 0));
	PrintSList(listhead);
	SListEraseAfter(SListFind(listhead, 9));
	PrintSList(listhead);

	SListDestroy(&listhead);
}
