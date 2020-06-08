#define _CRT_SECURE_NO_WARNINGS 1

////数组插入排序
//int main()
//{
//	for (int i = 1; i < size; ++i)
//	{
//		int key = array[i];
//		int end = i - 1;
//
//		while (end >= 0 && key < array[end])
//		{
//			array[end + 1] = array[end];
//			end--;
//		}
//		array[end - 1] = key;
//	}
//	return 0;
//}



//12. 对链表进行插入排序

//原理：依次从原链表中取节点，将其插入到新链表中。
//1.从原链表中取一个节点cur
//2.将该节点从原链表中删除
//3.在新链表中找cur的插入位置pos
//4.将cur节点插入到新链表中pos位置之前


struct ListNode {
    int val;
    struct ListNode *next;
};


typedef struct ListNode ListNode;

struct ListNode* insertionSortList(struct ListNode* head)
{
	//链表为空或者链表中只有一个节点
	if (NULL == head || NULL == head->next)
		return head;

	//链表中至少有两个节点
	//从原链表中获取一个节点，将其插入到新链表当中
	ListNode* newHead = NULL;
	ListNode* cur = head;
	while (cur)
	{
		//cur即为需要向新链表中插入的节点
		head = cur->next;//从原链表中删除

		//新链表中有节点，找新插入节点的位置
		ListNode* insertPos = newHead;
		ListNode* insertPosPrev = NULL;
		while (insertPos)//找位置
		{
			if (cur->val > insertPos->val)
			{
				insertPosPrev = insertPos;
				insertPos = insertPos->next;
			}
			else
			{
				break;
			}
		}

		//cur比新链表中所有的节点都小---头插
		if (NULL == insertPosPrev)
		{
			cur->next = newHead;
			newHead = cur;
		}
		else
		{
			//cur节点中的数据比insertPos节点的数据小
			cur->next = insertPos;
			insertPosPrev->next = cur;
		}

		cur = head;
	}
	return newHead;
}





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
	//课堂试例
	
}