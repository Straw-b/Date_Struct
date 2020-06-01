
//6.��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ

//����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣
//ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱䡣

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) 
	{}
};

typedef struct ListNode  ListNode;

ListNode* partition(ListNode* pHead, int x) 
{
	if (NULL == pHead)
		return NULL;

	ListNode lessxHead(0);//ͷ�ڵ�
	ListNode greatxHead(0);
	ListNode* lessTail = &lessxHead;
	ListNode* greatTail = &greatxHead;
	ListNode* cur = pHead;
	while (cur)
	{
		pHead = cur->next;

		//��cur�ڵ�β�嵽lessxHead����greatxHead
		if (cur->val < x)
		{
			lessTail->next = cur;
			lessTail = cur;
		}
		else
		{
			greatTail->next = cur;
			greatTail = cur;
		}
		cur = pHead;
	}

	greatTail->next = NULL;
	lessTail->next = greatxHead.next;
	return lessxHead.next;

}




//7.����Ļ��Ľṹ
//�ж��Ƿ��ǻ��Ľṹ

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL)
	{}
};

//////////////////////////////////����1
bool chkPalindrome(ListNode* A) 
{
	if (NULL == A)
		return true;

	int array[900] = { 0 };
	int size = 0;

	//�������еĽڵ���õ�array��������
	ListNode* cur = A;//����
	while (cur)
	{
		array[size++] = cur->val;
		cur = cur->next;
	}

	int left = 0;
	int right = size - 1;
	while (left < right)
	{
		if (array[left] != array[right])
			return false;
		left++;
		right--;
	}
	return true;
}


//////////////////////////////////����2
ListNode* ReverseList(ListNode* head)
{
	ListNode* cur = head;
	ListNode* prev = NULL;
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

bool chkPalindrome(ListNode* A)
{
	if (NULL == A)
		return true;

	//��������м�ڵ�
	ListNode* fast = A;
	ListNode* slow = A;
	ListNode* prevSlow = NULL;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		prevSlow = slow;
		slow = slow->next;
	}

	prevSlow->next = NULL;
	//�м�ڵ�Ϊslow
	//���м�ڵ㼰��������еĽڵ��������
	ListNode* rightHead = ReverseList(slow);

	//������������еĽڵ��Ƿ���ͬ
	ListNode* curLeft = A;
	ListNode* curRight = rightHead;
	while (curLeft && curRight)
	{
		if (curLeft->val != curRight->val)
			return false;

		curLeft = curLeft->next;
		curRight = curRight->next;
	}

	//��Ҫ��ԭ����ԭ
	prevSlow->next = ReverseList(rightHead);

	return true;
}





//8. �������������ҳ����ǵĵ�һ���������

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode ListNode;

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
	//����������Ҫ��һ��Ϊ�գ��򲻿����ཻ
	if (NULL == headA || NULL == headB)
		return NULL;
	
	//1.ȷ�����������Ƿ��ཻ
	//�ҵ����������е����һ���ڵ�
	ListNode* curA = headA;
	int countA = 1;
	while (curA->next)
	{
		countA++;
		curA = curA->next;
	}

	ListNode* curB = headB;
	int countB = 1;
	while (curB->next)
	{
		countB++;
		curB = curB->next;
	}
	//Ȼ�������һ���ڵ�ĵ�ַ�Ƿ���ͬ,����ͬ���ཻ
	if (curA != curB)
		return NULL;

	//2.�󽻵㣺��һ�������Ľڵ�
	//�ó�����������gap��
	curA = headA;
	curB = headB;
	int gap = countA - countB;
	if (gap > 0)
	{
		while (gap--)
			curA = curA->next;
	}
	else
	{
		while (gap++)
			curB = curB->next;
	}
	
	//���ϼ��curA��curB�Ƿ��ַ��ͬ
	while (curA != curB)
	{
		curA = curA->next;
		curB = curB->next;
	}

	return curA;
}





//9. ����һ�������ж��������Ƿ��л�

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/
 
typedef struct ListNode ListNode;

bool hasCycle(struct ListNode *head) 
{
	ListNode* fast = head;
	ListNode* slow = head;

	//������ܴ�����Ҳ���ܲ�����
	//�����������fastָ��϶����ߵ������ĩβ
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		
		if (fast == slow)
			return true;
	}
	return false;
}





//10.����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣
//��������޻����򷵻� NULL

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

typedef struct ListNode ListNode;

ListNode* hasCycle(ListNode *head)
{
	//��������Ƿ����
	ListNode* fast = head;
	ListNode* slow = head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
			return fast;
	}
	return NULL;
}

struct ListNode *detectCycle(struct ListNode *head) 
{
	ListNode* pM = hasCycle(head);//������

	//����ָ�벻���ʱ�򲻴���
	if (NULL == pM)
		return NULL;

	ListNode* pH = head;//��ͷ��
	while (pH != pM)
	{
		pH = pH->next;
		pM = pM->next;
	}
	return pM;
}