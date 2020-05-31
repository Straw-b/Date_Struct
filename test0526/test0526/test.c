#define _CRT_SECURE_NO_WARNINGS 1

//2. ��תһ��������

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




//4. ����һ����������������е�����k�����

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

//����1
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) 
{
	if (NULL == pListHead || k == 0)
		return NULL;
	ListNode* fast = pListHead;
	ListNode* slow = pListHead;

	// 1.��fast��������k��
	while (k--)
	{
		//���k�Ƿ���������нڵ�ĸ���
		if (NULL == fast)
			return NULL;

		fast = fast->next;
		//k--��
	}
	// 2.��slow��fastͬʱ�����ƶ���ֱ��fast�ߵ�NULLΪֹ��slow�պ�Ϊ������k���ڵ�
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

//����2
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (NULL == pListHead || k == 0)
		return NULL;
	ListNode* fast = pListHead;
	ListNode* slow = pListHead;

	// 1.��fast��������k-1��
	while (--k)
	{
		//���k�Ƿ���������нڵ�ĸ���
		if (NULL == fast)
			return NULL;

		fast = fast->next;
	}

	//���磺������ֻ��1���ڵ㣬����KΪ2��������K���ڵ�Ͳ�����
	if (NULL == fast)
		return NULL;

	// 2.��slow��fastͬʱ�����ƶ���ֱ��fast�ߵ����һ���ڵ�Ϊֹ��slow�պ�Ϊ������k���ڵ�
	while (fast->next)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}



//5. ��������������ϲ�Ϊһ���µ�������������
//��������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�

struct ListNode 
{
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;


////////////////////////////////////////////����1
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (NULL == l1)
		return l2;

	if (NULL == l2)
		return l1;

	//l1��l2�����������Ϊ��
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


////////////////////////////////////////////����2
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (NULL == l1)
		return l2;

	if (NULL == l2)
		return l1;

	//l1��l2�����������Ϊ��
	ListNode* cur1 = l1;
	ListNode* cur2 = l2;
	ListNode newhead;//��ͷ�ڵ�ĵ�����
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