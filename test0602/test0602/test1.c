
//11. 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的深度拷贝
//复杂链表的复制

//方法一：
//新链表中每个节点的随机指针域赋值：
//1.如果原链表中节点随机指针域指向空或者自己，也让新链表当前节点随机指针域指向空或者自己
//2.如果原链表中节点随机指针域指向其他节点
//>>求原链表中当前节点的随机指针域到原链表起始位置的距离dist
//>>给一个指针p，让其指向新链表中的节点，让p从新链表起始位置往后移动dist步之后指向的节点
//即新链表中当前节点的随机指针域应该指向的节点
//
//方法二：
//1.在原链表每个节点之后插入值相等的新节点
//2.给新插入节点的随机指针域进行赋值
//3.将新插入的节点从原链表中拆下来


//struct Node {
//	int val;
//	struct TreeNode *next;
//	struct TreeNode *random;
//};
//
//typedef struct Node Node;
//
//Node* BuyRandomListNode(int val)
//{
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	if (NULL == newNode)
//		return NULL;
//
//	newNode->val = val;
//	newNode->next = NULL;
//	newNode->random = NULL;
//
//	return newNode;
//}
//
//struct Node* copyRandomList(struct Node* head)
//{
//	if (NULL == head)
//		return NULL;
//
//	//1.在原链表每个节点之后插入值相等的新节点
//	Node* cur = head;
//	Node* newNode = NULL;
//	while (cur)
//	{
//		newNode = BuyRandomListNode(cur->val);
//		if (NULL == newNode)
//			return NULL;
//
//		newNode->next = cur->next;
//		cur->next = newNode;
//		cur = newNode->next;
//
//	}
//	
//	//2.给新插入节点的随机指针域进行赋值
//	cur = head;
//	while (cur)
//	{
//		newNode = cur->next;
//		if (cur->random)
//			newNode->random = cur->random->next;
//		
//		cur = newNode->next;
//	}
//
//	//3.将新节点从原链表中拆下来
//	Node* newHead = head->next;
//	cur = head;
//	while (cur->next)
//	{
//		newNode = cur->next;
//		cur->next = newNode->next;
//		cur = newNode;
//	}
//
//	return newHead;
//}






//13. 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点
//重复的结点不保留，返回链表头指针

//1.找到重复节点区间范围[start,end)
//2.删除重复区间中的节点[start,end)


//struct ListNode 
//{
//	int val;
//	struct ListNode *next;
//	ListNode(int x) :val(x), next(NULL) 
//	{
//	}
//};
//
//typedef struct ListNode ListNode;
//
//ListNode* deleteDuplication(ListNode* pHead)
//{
//	ListNode* start = pHead;
//	ListNode* end = start;
//	ListNode* prev = NULL;
//
//	while (start)
//	{
//		end = start->next;
//
//		//找重复节点的范围
//		while (end)
//		{
//			if (start->val != end->val)
//				break;
//
//			end = end->next;
//		}
//
//		//删除重复区间[start,end)
//		if (start->next == end)
//		{
//			//区间中没有重复元素
//			prev = start;
//			start = end;
//		}
//		else
//		{
//			//[start,end)有重复的节点
//			while (start != end)
//			{
//				//头删
//				if (start == pHead)
//				{
//					pHead = start->next;
//					free(start);
//					start = pHead;
//				}
//				//其他节点的删除方式
//				else
//				{
//					prev->next = start->next;
//					free(start);
//					start = prev->next;
//				}
//			}
//		}
//	}
//	return pHead;
//}
