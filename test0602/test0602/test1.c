#define _CRT_SECURE_NO_WARNINGS 1

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


struct Node {
	int val;
	struct TreeNode *next;
	struct TreeNode *random;
};


struct Node* copyRandomList(struct Node* head)
{
	//1.

	//2.

	//3.将新节点从原链表中拆下来

}






//13. 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点
//重复的结点不保留，返回链表头指针

//1.找到重复节点区间范围[start,end)
//2.删除重复区间中的节点[start,end)


struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) 
	{
	}
};

class Solution 
{
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode* start = pHead;
		ListNode* end = start;
		ListNode* prev = NULL;

		while (start)
		{
			end = start->next;

			//找重复节点的范围
			while (end)
			{

			}

		}

		if (start->next != end)
		{
			prev = start;
			start = end;
		}
		else
		{

			while (start != end)
			{
				//头删
				if (start == end)
				{

				}
				else
				{
					//其他节点的删除方式
					prev->next = start->next;
					free(start);

				}
			}
		}
		return head;
	}
};






//带头+双向+循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// 创建返回链表的头结点.
ListNode* ListCreate();
// 双向链表销毁
void ListDestory(ListNode* plist);
// 双向链表打印
void ListPrint(ListNode* plist);
// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x);
// 双向链表尾删
void ListPopBack(ListNode* plist);

// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x);
// 双向链表头删
void ListPopFront(ListNode* plist);
// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x);
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos);