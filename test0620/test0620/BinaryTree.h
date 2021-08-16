#pragma once


typedef int BTNDataType;

typedef struct BTNode
{
	struct BTNode* left;
	struct BTNode* right;
	BTNDataType data;
}BTNode;


// 创建
BTNode* CreateBinTree(int array[], int size, int* index, int invaild);

// 拷贝
BTNode* CopyBinTree(BTNode* root);

// 前序遍历
void PreOrder(BTNode* root);
// 中序遍历
void InOrder(BTNode* root);
// 后序遍历
void PostOrder(BTNode* root);

// 层序遍历
void LevelOrder(BTNode* root);

// 二叉树节点个数
int GetNodeCount(BTNode* root);
// 二叉树叶子节点个数
int GetLeafNodeCount(BTNode* root);
// 二叉树第k层节点个数
int GetKLevelNodeCount(BTNode* root, unsigned int k);
// 二叉树的高度
int GetHight(BTNode* root);

// 二叉树查找值为data的节点
BTNode* Find(BTNode* root, BTNDataType data);

// 二叉树销毁
void DestroyTree(BTNode** root);

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);

// 二叉树的镜像
void Mirror(BTNode* root);
void MirrorNor(BTNode* root);



//////////////////////////////////
void TestBinTree();