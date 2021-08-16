#pragma once


//binary tree node data type
typedef int BTNDataType;

typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	BTNDataType data;
}BTNode;


BTNode* CreateBinTree();

//ǰ�����
void PreOrder(BTNode* root);
//�������
void InOrder(BTNode* root);
//�������
void PostOrder(BTNode* root);



//////////////////////////////////
void TestBinTree();