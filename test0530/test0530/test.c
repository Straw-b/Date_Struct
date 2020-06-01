
//6.编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前

//给定一个链表的头指针 ListNode* pHead，请返回重新排列后的链表的头指针。
//注意：分割以后保持原来的数据顺序不变。

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

	ListNode lessxHead(0);//头节点
	ListNode greatxHead(0);
	ListNode* lessTail = &lessxHead;
	ListNode* greatTail = &greatxHead;
	ListNode* cur = pHead;
	while (cur)
	{
		pHead = cur->next;

		//将cur节点尾插到lessxHead或者greatxHead
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




//7.链表的回文结构
//判断是否是回文结构

struct ListNode
{
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL)
	{}
};

//////////////////////////////////方法1
bool chkPalindrome(ListNode* A) 
{
	if (NULL == A)
		return true;

	int array[900] = { 0 };
	int size = 0;

	//将链表中的节点放置到array的数组中
	ListNode* cur = A;//遍历
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


//////////////////////////////////方法2
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

	//找链表的中间节点
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
	//中间节点为slow
	//将中间节点及其后续所有的节点进行逆置
	ListNode* rightHead = ReverseList(slow);

	//检测两个链表中的节点是否相同
	ListNode* curLeft = A;
	ListNode* curRight = rightHead;
	while (curLeft && curRight)
	{
		if (curLeft->val != curRight->val)
			return false;

		curLeft = curLeft->next;
		curRight = curRight->next;
	}

	//需要将原链表还原
	prevSlow->next = ReverseList(rightHead);

	return true;
}





//8. 输入两个链表，找出它们的第一个公共结点

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
	//两个链表主要有一个为空，则不可能相交
	if (NULL == headA || NULL == headB)
		return NULL;
	
	//1.确定两个链表是否相交
	//找到两个链表中的最后一个节点
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
	//然后检测最后一个节点的地址是否相同,不相同则不相交
	if (curA != curB)
		return NULL;

	//2.求交点：第一个公共的节点
	//让长的链表先走gap步
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
	
	//不断检测curA和curB是否地址相同
	while (curA != curB)
	{
		curA = curA->next;
		curB = curB->next;
	}

	return curA;
}





//9. 给定一个链表，判断链表中是否有环

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

	//链表可能带环，也可能不带环
	//如果不带环，fast指针肯定先走到链表的末尾
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		
		if (fast == slow)
			return true;
	}
	return false;
}





//10.给定一个链表，返回链表开始入环的第一个节点。
//如果链表无环，则返回 NULL

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
	//检测链表是否带环
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
	ListNode* pM = hasCycle(head);//环内走

	//两个指针不相等时则不带环
	if (NULL == pM)
		return NULL;

	ListNode* pH = head;//环头走
	while (pH != pM)
	{
		pH = pH->next;
		pM = pM->next;
	}
	return pM;
}