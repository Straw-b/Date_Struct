#define _CRT_SECURE_NO_WARNINGS 1

//11. ����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//Ҫ�󷵻�����������ȿ���
//��������ĸ���

//����һ��
//��������ÿ���ڵ�����ָ����ֵ��
//1.���ԭ�����нڵ����ָ����ָ��ջ����Լ���Ҳ��������ǰ�ڵ����ָ����ָ��ջ����Լ�
//2.���ԭ�����нڵ����ָ����ָ�������ڵ�
//>>��ԭ�����е�ǰ�ڵ�����ָ����ԭ������ʼλ�õľ���dist
//>>��һ��ָ��p������ָ���������еĽڵ㣬��p����������ʼλ�������ƶ�dist��֮��ָ��Ľڵ�
//���������е�ǰ�ڵ�����ָ����Ӧ��ָ��Ľڵ�
//
//��������
//1.��ԭ����ÿ���ڵ�֮�����ֵ��ȵ��½ڵ�
//2.���²���ڵ�����ָ������и�ֵ
//3.���²���Ľڵ��ԭ�����в�����


struct Node {
	int val;
	struct TreeNode *next;
	struct TreeNode *random;
};


struct Node* copyRandomList(struct Node* head)
{
	//1.

	//2.

	//3.���½ڵ��ԭ�����в�����

}






//13. ��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ��
//�ظ��Ľ�㲻��������������ͷָ��

//1.�ҵ��ظ��ڵ����䷶Χ[start,end)
//2.ɾ���ظ������еĽڵ�[start,end)


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

			//���ظ��ڵ�ķ�Χ
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
				//ͷɾ
				if (start == end)
				{

				}
				else
				{
					//�����ڵ��ɾ����ʽ
					prev->next = start->next;
					free(start);

				}
			}
		}
		return head;
	}
};






//��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// �������������ͷ���.
ListNode* ListCreate();
// ˫����������
void ListDestory(ListNode* plist);
// ˫�������ӡ
void ListPrint(ListNode* plist);
// ˫������β��
void ListPushBack(ListNode* plist, LTDataType x);
// ˫������βɾ
void ListPopBack(ListNode* plist);

// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType x);
// ˫������ͷɾ
void ListPopFront(ListNode* plist);
// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType x);
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);