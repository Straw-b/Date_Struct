//12. ��������в�������

//ԭ�����δ�ԭ������ȡ�ڵ㣬������뵽�������С�
//1.��ԭ������ȡһ���ڵ�cur
//2.���ýڵ��ԭ������ɾ��
//3.������������cur�Ĳ���λ��pos
//4.��cur�ڵ���뵽��������posλ��֮ǰ

//struct ListNode 
//{
//    int val;
//    struct ListNode *next;
//};


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
        //cur�ڵ��е����ݱ�insertPos�ڵ������С
		else
		{		
			cur->next = insertPos;
			insertPosPrev->next = cur;
		}
		cur = head;//curȡԭ�����е���һ���ڵ�
	}
	return newHead;
}





//11. ����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//Ҫ�󷵻�����������ȿ�������������ĸ���

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

//struct Node 
//{
//    int val;
//    struct TreeNode *next;
//    struct TreeNode *random;
//};


typedef struct Node Node;

Node* BuyRandomListNode(int val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (NULL == newNode)
		return NULL;

	newNode->val = val;
	newNode->next = NULL;
	newNode->random = NULL;

	return newNode;
}

struct Node* copyRandomList(struct Node* head)
{
	if (NULL == head)
		return NULL;

	//1.��ԭ����ÿ���ڵ�֮�����ֵ��ȵ��½ڵ�
	Node* cur = head;
	Node* newNode = NULL;
	while (cur)
	{
		newNode = BuyRandomListNode(cur->val);
		if (NULL == newNode)
			return NULL;

		newNode->next = cur->next;
		cur->next = newNode;
		cur = newNode->next;

	}
	
	//2.���²���ڵ�����ָ������и�ֵ
	cur = head;
	while (cur)
	{
		newNode = cur->next;
		if (cur->random)
			newNode->random = cur->random->next;
		
		cur = newNode->next;
	}

	//3.���½ڵ��ԭ�����в�����
	Node* newHead = head->next;
	cur = head;
	while (cur->next)
	{
		newNode = cur->next;
		cur->next = newNode->next;
		cur = newNode;
	}

	return newHead;
}

