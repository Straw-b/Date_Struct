#include "SLish.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>


//����һ���½ڵ�
SListNode* BuySListNode(SLDataType data)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	if (NULL == newNode)
	{
		assert(0); //���Ժ꣬����Ϊ0��ͻᴥ��
		return NULL;
	}

	newNode->next = NULL;
	newNode->data = data;
	return newNode;
}

//β��
void SListPushBack(SListNode** head, SLDataType data)
{
	assert(head);
	//������
	SListNode* newNode = BuySListNode(data);
	if (NULL == *head)
	{
		*head = newNode;
	}
	else
	{
		//1.�ҵ������е����һ���ڵ�
		SListNode* cur = *head;
		while (cur->next)
		{
			cur = cur->next;
		}
		//2.�����½ڵ�
		cur->next = newNode;
	}
}

//βɾ
void SListPopBack(SListNode** head)
{
	assert(head);//���Ƿ����
	if (NULL == *head)
	{
		//������
		return;
	}
	else if (NULL == (*head)->next)
	{
		//ֻ��һ���ڵ�
		free(*head);
		*head = NULL;
	}
	else
	{
		//����ǿ�---������һ���ڵ�
		SListNode* cur = *head;
		SListNode* prev = NULL;//���cur��ǰһ���ڵ�
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		prev->next = cur->next;
		//�ҵ����һ���ڵ�,ɾ��
		free(cur);
	}
}

//ͷ��
void SListPushFront(SListNode** head, SLDataType data)
{
	assert(head);
	SListNode* newNode = BuySListNode(data);
	
	newNode->next = *head;
	*head = newNode;

	////1.������
	//if (NULL == *head)
	//{
	//	*head = newNode;
	//}
	////2.����ڵ�
	//else
	//{
	//	newNode->next = *head;
	//	*head = newNode;
	//}
}

//ͷɾ
void SListPopFront(SListNode** head)
{
	SListNode* delNode = NULL;
	assert(head);
	if (NULL == *head)
	{
		return;//������
	}
	
	delNode = *head;
	*head = delNode->next;
	free(delNode);
	
	//else if (NULL == (*head)->next)
	//{
	//	//ֻ��һ���ڵ�
	//	free(*head);
	//	*head = NULL;
	//}
	//else
	//{
	//	//����ǿ�---�ж���ڵ�
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

	//SListPushBack(NULL, 5);//�Ƿ�����

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
