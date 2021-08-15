#include "DHCList.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>


//����ڵ�
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

//��ʼ��--ֻ�轫ͷ�ڵ������
DHCLNode* DHCListInit()
{
	DHCLNode* head = BuyDHCListNode(0);
	head->next = head;
	head->prev = head;
	return head;
}

//β��
void DHCListPushBack(DHCLNode* pHead, DLDataType data)
{
	assert(pHead);
	DHCListInsert(pHead, data);
}

//βɾ
void DHCListPopBack(DHCLNode* pHead)
{
	if (DHCListEmpty(pHead))
		return;

	DHCListErase(pHead->prev);
}

//ͷ��
void DHCListPushFront(DHCLNode* pHead, DLDataType data)
{
	assert(pHead);
	DHCListInsert(pHead->next, data);
}

//ͷɾ
void DHCListPopFront(DHCLNode* pHead)
{
	if (DHCListEmpty(pHead))
		return;

	DHCListErase(pHead->next);
}

//����λ�ò���
void DHCListInsert(DHCLNode* pos, DLDataType data)
{
	DHCLNode* newNode;
	if (NULL == pos)
		return;

	//�����½ڵ�
	newNode = BuyDHCListNode(data);

	//1.�Ƚ��½ڵ����ӵ�˫��������
	newNode->next = pos;
	newNode->prev = pos->prev;

	//2.�Ͽ������ӣ����½ڵ����
	pos->prev = newNode;
	newNode->prev->next = newNode;
}

//����λ��ɾ��
void DHCListErase(DHCLNode* pos)
{
	if (NULL == pos)
		return;
	
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

//����
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

//ֻ�ǽ������е���Ч�ڵ�ɾ������ɾͷ
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

	//�����Ѿ�Ϊ��
	pHead->next = pHead;
	pHead->prev = pHead;
}

//��Ҫ��ͷ�ڵ��Լ����е���Ч�ڵ�ȫ��ɾ��
void DHCListDestroy(DHCLNode** pHead)
{
	assert(pHead);
	DHCListClear(*pHead);
	free(*pHead);
	*pHead = NULL;

}

//��ӡ
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