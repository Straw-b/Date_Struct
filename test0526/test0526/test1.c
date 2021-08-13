#define _CRT_SECURE_NO_WARNINGS 1

#if 0

//带头节点的单链表
typedef struct SHListNode
{
	int data;
	struct SHListNode* next;
}SHListNode;

#include <stdio.h>
#include <malloc.h>

void SHListPushBack(SHListNode* head, int data)
{
	SHListNode* newNode = (SHListNode*)malloc(sizeof(SHListNode));
	newNode->next = NULL;
	newNode->data = data;

	SHListNode* tailNode = head;
	while (tailNode->next)
	{
		tailNode = tailNode->next;
	}

	tailNode->next = newNode;
}

void TestHList()
{
	SHListNode headNode;//链表的头节点
	headNode.next = NULL;

	SHListPushBack(&headNode, 1);
	SHListPushBack(&headNode, 2);
	SHListPushBack(&headNode, 3);
	SHListPushBack(&headNode, 4);
	SHListPushBack(&headNode, 5);
}

int main()
{
	TestHList();
	return 0;
}

#endif