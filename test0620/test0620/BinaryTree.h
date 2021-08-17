#pragma once


typedef int BTNDataType;

typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	BTNDataType data;
}BTNode;


// ����
BTNode* CreateBinTree(int array[], int size, int* index, int invaild);

// ����
BTNode* CopyBinTree(BTNode* root);

// ǰ�����
void PreOrder(BTNode* root);
// �������
void InOrder(BTNode* root);
// �������
void PostOrder(BTNode* root);

// �������
void LevelOrder(BTNode* root);

// �������ڵ����
int GetNodeCount(BTNode* root);
// ������Ҷ�ӽڵ����
int GetLeafNodeCount(BTNode* root);
// ��������k��ڵ����
int GetKLevelNodeCount(BTNode* root, unsigned int k);
// �������ĸ߶�
int GetHight(BTNode* root);

// ����������ֵΪdata�Ľڵ�
BTNode* Find(BTNode* root, BTNDataType data);

// ����������
void DestroyTree(BTNode** root);

// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);

// �������ľ���
void Mirror(BTNode* root);
void MirrorNor(BTNode* root);



//////////////////////////////////
void TestBinTree();