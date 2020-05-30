#include "SLish.h"


//�����½ڵ�
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
	assert(head);
	if (NULL == *head)
	{
		//������
		return;
	}
	
	SListNode* delNode = *head;
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

void SListInsert(SListNode* pos, SLDataType data);

void SListErase(SListNode* pos);

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
	assert(head);
	while (*head)  
	{
		SListNode* delNode = *head;
		*head = delNode->next;
		free(delNode);
	}
}



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



//////////////////////////////////////////////////////////////////////////////
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

void TestSList()
{
	//Test1();
	Test2();
}