
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
//	//1.��ԭ����ÿ���ڵ�֮�����ֵ��ȵ��½ڵ�
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
//	//2.���²���ڵ�����ָ������и�ֵ
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
//	//3.���½ڵ��ԭ�����в�����
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






//13. ��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ��
//�ظ��Ľ�㲻��������������ͷָ��

//1.�ҵ��ظ��ڵ����䷶Χ[start,end)
//2.ɾ���ظ������еĽڵ�[start,end)


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
//		//���ظ��ڵ�ķ�Χ
//		while (end)
//		{
//			if (start->val != end->val)
//				break;
//
//			end = end->next;
//		}
//
//		//ɾ���ظ�����[start,end)
//		if (start->next == end)
//		{
//			//������û���ظ�Ԫ��
//			prev = start;
//			start = end;
//		}
//		else
//		{
//			//[start,end)���ظ��Ľڵ�
//			while (start != end)
//			{
//				//ͷɾ
//				if (start == pHead)
//				{
//					pHead = start->next;
//					free(start);
//					start = pHead;
//				}
//				//�����ڵ��ɾ����ʽ
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
