#define _CRT_SECURE_NO_WARNINGS 1

//2. 反转一个单链表

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode ListNode;

struct ListNode* reverseList(struct ListNode* head)
{
	ListNode* prev = NULL;
	ListNode* cur = head;
	ListNode* next = NULL;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	return prev;
}




//4. 输入一个链表，输出该链表中倒数第k个结点

/*
struct ListNode 
{
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) 
{
}
};*/

//方法1
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
	if (NULL == pListHead || k == 0)
		return NULL;
	ListNode* fast = pListHead;
	ListNode* slow = pListHead;

	// 1.让fast先往后走k步
	while (k--)
	{
		//检测k是否大于链表中节点的个数
		if (NULL == fast)
			return NULL;

		fast = fast->next;
		//k--；
	}
	// 2.让slow与fast同时往后移动，直到fast走到NULL为止，slow刚好为倒数第k个节点
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

//方法2
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (NULL == pListHead || k == 0)
		return NULL;
	ListNode* fast = pListHead;
	ListNode* slow = pListHead;

	// 1.让fast先往后走k-1步
	while (--k)
	{
		//检测k是否大于链表中节点的个数
		if (NULL == fast)
			return NULL;

		fast = fast->next;
	}

	//比如：链表中只有1个节点，但是K为2，倒数第K个节点就不存在
	if (NULL == fast)
		return NULL;

	// 2.让slow与fast同时往后移动，直到fast走到最后一个节点为止，slow刚好为倒数第k个节点
	while (fast->next)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}



//5. 将两个有序链表合并为一个新的有序链表并返回
//新链表是通过拼接给定的两个链表的所有节点组成的

struct ListNode 
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;


////////////////////////////////////////////方法1
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (NULL == l1)
		return l2;

	if (NULL == l2)
		return l1;

	//l1和l2两个链表均不为空
	ListNode* newhead = NULL;
	ListNode* cur1 = l1;
	ListNode* cur2 = l2;
	ListNode* tailNode = NULL;

	if (cur1->val <= cur2->val)
	{
		newhead = cur1;
		tailNode = cur1;
		cur1 = cur1->next;
	}
	else
	{
		newhead = cur2;
		tailNode = cur2;
		cur2 = cur2->next;
	}

	while (cur1 && cur2)
	{
		if (cur1->val <= cur2->val)
		{
			tailNode->next = cur1;
			cur1 = cur1->next;
		}
		else
		{
			tailNode->next = cur2;
			cur2 = cur2->next;
		}
		tailNode = tailNode->next;
	}

	if (cur1)
		tailNode->next = cur1;
	else
		tailNode->next = cur2;

	return newhead;
}


////////////////////////////////////////////方法2
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (NULL == l1)
		return l2;

	if (NULL == l2)
		return l1;

	//l1和l2两个链表均不为空
	ListNode* cur1 = l1;
	ListNode* cur2 = l2;
	ListNode newhead;//带头节点的单链表
	ListNode* tailNode = &newhead;

	while (cur1 && cur2)
	{
		if (cur1->val <= cur2->val)
		{
			tailNode->next = cur1;
			cur1 = cur1->next;
		}
		else
		{
			tailNode->next = cur2;
			cur2 = cur2->next;
		}
		tailNode = tailNode->next;
	}

	if (cur1)
		tailNode->next = cur1;
	else
		tailNode->next = cur2;

	return newhead.next;
}