#define _CRT_SECURE_NO_WARNINGS 1

////�����������
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



//12. ��������в�������

//ԭ�����δ�ԭ������ȡ�ڵ㣬������뵽�������С�
//1.��ԭ������ȡһ���ڵ�cur
//2.���ýڵ��ԭ������ɾ��
//3.������������cur�Ĳ���λ��pos
//4.��cur�ڵ���뵽��������posλ��֮ǰ


struct ListNode {
    int val;
    struct ListNode *next;
};


typedef struct ListNode ListNode;

struct ListNode* insertionSortList(struct ListNode* head)
{
	//����Ϊ�ջ���������ֻ��һ���ڵ�
	if (NULL == head || NULL == head->next)
		return head;

	//�����������������ڵ�
	//��ԭ�����л�ȡһ���ڵ㣬������뵽��������
	ListNode* newHead = NULL;
	ListNode* cur = head;
	while (cur)
	{
		//cur��Ϊ��Ҫ���������в���Ľڵ�
		head = cur->next;//��ԭ������ɾ��

		//���������нڵ㣬���²���ڵ��λ��
		ListNode* insertPos = newHead;
		ListNode* insertPosPrev = NULL;
		while (insertPos)//��λ��
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

		//cur�������������еĽڵ㶼С---ͷ��
		if (NULL == insertPosPrev)
		{
			cur->next = newHead;
			newHead = cur;
		}
		else
		{
			//cur�ڵ��е����ݱ�insertPos�ڵ������С
			cur->next = insertPos;
			insertPosPrev->next = cur;
		}

		cur = head;
	}
	return newHead;
}





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
	//��������
	
}