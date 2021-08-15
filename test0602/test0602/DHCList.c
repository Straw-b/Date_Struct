#include "DHCList.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>


//申请节点
DHCLNode* BuyDHCListNode(DLDataType data)
{
	DHCLNode* newNode = (DHCLNode*)malloc(sizeof(DHCLNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}

	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

//初始化--只需将头节点申请好
DHCLNode* DHCListInit()
{
	DHCLNode* head = BuyDHCListNode(0);
	head->next = head;
	head->prev = head;
	return head;
}

//尾插
void DHCListPushBack(DHCLNode* pHead, DLDataType data)
{
	assert(pHead);
	DHCListInsert(pHead, data);
}

//尾删
void DHCListPopBack(DHCLNode* pHead)
{
	if (DHCListEmpty(pHead))
		return;

	DHCListErase(pHead->prev);
}

//头插
void DHCListPushFront(DHCLNode* pHead, DLDataType data)
{
	assert(pHead);
	DHCListInsert(pHead->next, data);
}

//头删
void DHCListPopFront(DHCLNode* pHead)
{
	if (DHCListEmpty(pHead))
		return;

	DHCListErase(pHead->next);
}

//任意位置插入
void DHCListInsert(DHCLNode* pos, DLDataType data)
{
	DHCLNode* newNode;
	if (NULL == pos)
		return;

	//申请新节点
	newNode = BuyDHCListNode(data);

	//1.先将新节点连接到双向链表中
	newNode->next = pos;
	newNode->prev = pos->prev;

	//2.断开旧链接，将新节点插入
	pos->prev = newNode;
	newNode->prev->next = newNode;
}

//任意位置删除
void DHCListErase(DHCLNode* pos)
{
	if (NULL == pos)
		return;
	
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

//查找
DHCLNode* DHCListFind(DHCLNode* pHead, DLDataType data)
{
	assert(pHead);
	DHCLNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (data == cur->data)
			return cur;

		cur = cur->next;
	}
	return NULL;
}

int DHCListSize(DHCLNode* pHead)
{
	assert(pHead);
	DHCLNode* cur = pHead->next;
	int count = 0;
	while (cur != pHead)
	{
		++count;
		cur = cur->next;
	}
	return count;
}

int DHCListEmpty(DHCLNode* pHead)
{
	assert(pHead);
	return pHead->next == pHead;
}

//只是将链表中的有效节点删除，不删头
void DHCListClear(DHCLNode* pHead)
{
	assert(pHead);
	DHCLNode* cur = pHead->next;

	while (cur != pHead)
	{
		pHead->next = cur->next;
		free(cur);
		cur = pHead->next;
	}

	//链表已经为空
	pHead->next = pHead;
	pHead->prev = pHead;
}

//需要将头节点以及所有的有效节点全部删除
void DHCListDestroy(DHCLNode** pHead)
{
	assert(pHead);
	DHCListClear(*pHead);
	free(*pHead);
	*pHead = NULL;

}

//打印
void PrintDHCList(DHCLNode* head)
{
	DHCLNode* cur = head->next;
	while (cur != head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//////////////////////////////////////////////////////////////////////////////
void TestDHCList()
{
	DHCLNode* head = DHCListInit();
	DHCListPushBack(head, 1);
	DHCListPushBack(head, 2);
	DHCListPushBack(head, 3);
	DHCListPushBack(head, 4);
	DHCListPushBack(head, 5);
	PrintDHCList(head);

	DHCListPushFront(head, 0);
	PrintDHCList(head);

	DHCListPopBack(head);
	DHCListPopFront(head);
	PrintDHCList(head);

	DHCListInsert(DHCListFind(head, 3), 100);
	PrintDHCList(head);

	DHCListErase(DHCListFind(head, 3));
	PrintDHCList(head);

	DHCListDestroy(&head);
}