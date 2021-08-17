#include "BinaryTree.h"

#include <malloc.h>
#include <assert.h>
#include <stdio.h>

#include "Queue1.h"


BTNode* BuyBinTreeNode(BTNDataType data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}

	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}


// ����
// array�����У�������Ƕ����������нڵ��ֵ��
// index������indexȡ�������е�ÿ��Ԫ�أ�Ȼ���ڵݹ麯������Ҫ��index���иı䣬�ݹ��������Ҫ���ı������
// invaild��������Ч�ڵ�
BTNode* CreateBinTree(int array[], int size, int* index, int invaild)
{
	BTNode* root = NULL;
	if (*index < size && array[*index] != -1)
	{
		//�������ڵ�
		root = BuyBinTreeNode(array[*index]);

		//�������ڵ��������
		++(*index);
		root->left = CreateBinTree(array, size, index, invaild);

		//�������ڵ��������
		++(*index);
		root->right = CreateBinTree(array, size, index, invaild);
	}
	return root;
}

// �������Ŀ���
BTNode* CopyBinTree(BTNode* root)
{
	BTNode* newroot = NULL;
	if (root)
	{
		//�������ڵ�
		newroot = BuyBinTreeNode(root->data);

		//�������ڵ��������
		newroot->left = CopyBinTree(root->left);

		//�������ڵ��������
		newroot->right = CopyBinTree(root->right);
	}
	return newroot;
}


//���裺�����������ǽ��ڵ��е�ֵ���ӡ����
//���ڵ�--->���ڵ��������--->���ڵ��������
void PreOrder(BTNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void InOrder(BTNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%d ", root->data);
		InOrder(root->right);
	}
}

void PostOrder(BTNode* root)
{
	if (root)
	{
		PostOrder(root->left);
		PostOrder(root->right);
		printf("%d ", root->data);
	}
}

//�������
void LevelOrder(BTNode* root)
{
	Queue q;
	if (NULL == root)
		return;

	QueueInit(&q);
	QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		printf("%d ", cur->data);
		QueuePop(&q);

		//���cur���Ӵ��ڣ������������
		if (cur->left)
			QueuePush(&q, cur->left);

		//���cur�к��Ӵ��ڣ����Һ��������
		if (cur->right)
			QueuePush(&q, cur->right);
	}

	QueueDestroy(&q);
}


// �������ڵ����
int GetNodeCount(BTNode* root)
{
	//if (NULL == root)
	//	return 0;
	//int leftSize = GetNodeCount(root->left);
	//int rightSize = GetNodeCount(root->right);
	//return leftSize + rightSize + 1;

	if (NULL == root)
		return 0;
	return GetNodeCount(root->left) + GetNodeCount(root->right) + 1;

	//return NULL == root ? 0 : GetNodeCount(root->left) + GetNodeCount(root->right) + 1;
}

// ������Ҷ�ӽڵ����
int GetLeafNodeCount(BTNode* root)
{
	if (NULL == root)
		return 0;

	//�����Ҷ�ӷ���1
	if (NULL == root->left && NULL == root->right)
		return 1;

	return GetLeafNodeCount(root->left) + GetLeafNodeCount(root->right);
}

// ��������K��ڵ����
int GetKLevelNodeCount(BTNode* root, unsigned int k)
{
	if (NULL == root || k == 0)
		return 0;

	//��һ��ֻ�и��ڵ�
	if (k == 1)
		return 1;

	//������ת��Ϊ������������k-1��ڵ�ĸ���
	return GetKLevelNodeCount(root->left, k - 1) + GetKLevelNodeCount(root->right, k - 1);
}

// �������ĸ߶�
int GetHight(BTNode* root)
{
	int leftHeight = 0, rightHeight = 0;
	if (NULL == root)
		return 0;

	leftHeight = GetHight(root->left);
	rightHeight = GetHight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}


// ����������ֵΪdata�Ľڵ�
BTNode* Find(BTNode* root, BTNDataType data)
{
	BTNode* ret = NULL;
	if (NULL == root)
		return NULL;

	// ���ڵ�����
	if (root->data == data)
		return root;

	// �������������ң��ҵ���ֱ�ӷ���
	// �����������û���ҵ����ٵ�����������
	if (ret = Find(root->left, data))
		return ret;
	return Find(root->right, data);
}


// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	int flag = 0;
	int ret = 0;
	//����Ҳ����ȫ������
	if (NULL == root)
		return 1;

	//�ǿ�
	//1.���ղ�����������ҵ�һ�������͵�
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		if (flag)
		{
			//�����͵Ľڵ��Ѿ��ҵ�������ڵ�Ͳ����к���
			if (cur->left || cur->right)
				break;	//��;�˳�������û������
		}	
		else
		{
			//�ҵ�һ�������͵ĵ�
			if (cur->left && cur->right)
			{
				//���Һ��Ӷ�����
				QueuePush(&q, cur->left);
				QueuePush(&q, cur->right);
			}
			else if (cur->left)
			{
				//curֻ������
				QueuePush(&q, cur->left);
				flag = 1; //����ٽ�ڵ�
			}
			else if (cur->right)
			{
				//curֻ���Һ���
				break; //������ȫ������
			}
			else
			{
				//��û����Ҳû���ң�����Ľڵ�Ͳ����к���
				flag = 1;
			}
		}
		QueuePop(&q); //��ͷԪ���ó���
	}
	
	if (QueueEmpty(&q))
		ret = 1; //Ϊ�գ�����ȫ������

	QueueDestroy(&q);
	return ret;
}


//�ô��Ĵ����뵥����ͷɾ��һ����
void DestroyTree(BTNode** root)
{
	assert(root); //root�е����ݣ������ⲿʵ�εĵ�ַ
	if (*root) //*root�����ⲿ��ʵ��
	{
		//&(*root)��root�ĵ�ַ
		DestroyTree(&(*root)->left);
		DestroyTree(&(*root)->right);
		free(*root);
		*root = NULL; //�ⲿ��ʵ��ָ���
	}
}



//////////////////////////////////////////////////////////////////////////
void TestBinTree()
{
	// ����������Ԫ�ط���������
	// -1��ʾ�ýڵ㲻����
	int array[] = { 1, 2, 3, -1, -1, -1, 4, 5, -1, -1, 6 };
	int index = 0;
	BTNode* root = CreateBinTree(array, sizeof(array) / sizeof(array[0]), &index, -1);
	BTNode* newroot = NULL;

	printf("ǰ����������\n");
	PreOrder(root);
	printf("\n");
	printf("������������\n");
	InOrder(root);
	printf("\n");
	printf("������������\n");
	PostOrder(root);
	printf("\n");
	printf("������������\n");
	LevelOrder(root);
	printf("\n");

	printf("GetNodeCount��%d\n", GetNodeCount(root));
	printf("GetLeafNodeCount��%d\n", GetLeafNodeCount(root));
	printf("GetKLevelNodeCount2��%d\n", GetKLevelNodeCount(root, 2));
	printf("GetKLevelNodeCount3��%d\n", GetKLevelNodeCount(root, 3));
	printf("GetKLevelNodeCount10��%d\n", GetKLevelNodeCount(root, 10));
	printf("GetHight��%d\n", GetHight(root));

	//����
	BTNode* cur = Find(root, 5);
	if (cur)
		printf("5 is in binary tree!\n");
	else
		printf("5 is not in binary tree!\n");

	//�Ƿ���ȫ������
	if (BinaryTreeComplete(root))
		printf("Is complete binary tree!\n");
	else
		printf("Is not complete binary tree!\n");

	//����
	newroot = CopyBinTree(root);
	printf("���������\n");
	PreOrder(newroot);
	printf("\n");
	InOrder(newroot);
	printf("\n");
	PostOrder(newroot);
	printf("\n");

	DestroyTree(&root);
	DestroyTree(&newroot);
}