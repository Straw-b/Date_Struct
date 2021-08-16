#include "BinaryTree.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>



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

BTNode* CreateBinTree()
{
	BTNode* root = NULL;
	BTNode* n1 = BuyBinTreeNode(1);
	BTNode* n2 = BuyBinTreeNode(2);
	BTNode* n3 = BuyBinTreeNode(3);
	BTNode* n4 = BuyBinTreeNode(4);
	BTNode* n5 = BuyBinTreeNode(5);
	BTNode* n6 = BuyBinTreeNode(6);

	root = n1;
	root->left = n2;
	n2->left = n3;

	root->right = n4;
	n4->left = n5;
	n4->right = n6;
	return root;
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



////////////////////////////////////////
void TestBinTree()
{
	BTNode* root = CreateBinTree();
	printf("ǰ����������\n");
	PreOrder(root);
	printf("\n");

	printf("������������\n");
	InOrder(root);
	printf("\n");

	printf("������������\n");
	PostOrder(root);
	printf("\n");
}