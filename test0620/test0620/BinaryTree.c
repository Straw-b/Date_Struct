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


// 创建
// array数组中：保存的是二叉树中所有节点的值域
// index：利用index取到数组中的每个元素，然后在递归函数中需要对index进行改变，递归结束后需要将改变带出来
// invaild：代表无效节点
BTNode* CreateBinTree(int array[], int size, int* index, int invaild)
{
	BTNode* root = NULL;
	if (*index < size && array[*index] != -1)
	{
		//创建根节点
		root = BuyBinTreeNode(array[*index]);

		//创建根节点的左子树
		++(*index);
		root->left = CreateBinTree(array, size, index, invaild);

		//创建根节点的右子树
		++(*index);
		root->right = CreateBinTree(array, size, index, invaild);
	}
	return root;
}

// 二叉树的拷贝
BTNode* CopyBinTree(BTNode* root)
{
	BTNode* newroot = NULL;
	if (root)
	{
		//拷贝根节点
		newroot = BuyBinTreeNode(root->data);

		//拷贝根节点的左子树
		newroot->left = CopyBinTree(root->left);

		//拷贝根节点的右子树
		newroot->right = CopyBinTree(root->right);
	}
	return newroot;
}


//假设：遍历操作就是将节点中的值域打印出来
//根节点--->根节点的左子树--->根节点的右子树
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

//层序遍历
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

		//如果cur左孩子存在，将左孩子入队列
		if (cur->left)
			QueuePush(&q, cur->left);

		//如果cur有孩子存在，将右孩子入队列
		if (cur->right)
			QueuePush(&q, cur->right);
	}

	QueueDestroy(&q);
}


// 二叉树节点个数
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

// 二叉树叶子节点个数
int GetLeafNodeCount(BTNode* root)
{
	if (NULL == root)
		return 0;

	//如果是叶子返回1
	if (NULL == root->left && NULL == root->right)
		return 1;

	return GetLeafNodeCount(root->left) + GetLeafNodeCount(root->right);
}

// 二叉树第K层节点个数
int GetKLevelNodeCount(BTNode* root, unsigned int k)
{
	if (NULL == root || k == 0)
		return 0;

	//第一层只有根节点
	if (k == 1)
		return 1;

	//将问题转化为：到子树中求k-1层节点的个数
	return GetKLevelNodeCount(root->left, k - 1) + GetKLevelNodeCount(root->right, k - 1);
}

// 二叉树的高度
int GetHight(BTNode* root)
{
	int leftHeight = 0, rightHeight = 0;
	if (NULL == root)
		return 0;

	leftHeight = GetHight(root->left);
	rightHeight = GetHight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}


// 二叉树查找值为data的节点
BTNode* Find(BTNode* root, BTNDataType data)
{
	BTNode* ret = NULL;
	if (NULL == root)
		return NULL;

	// 根节点中找
	if (root->data == data)
		return root;

	// 先在左子树中找，找到了直接返回
	// 如果左子树中没有找到，再到右子树中找
	if (ret = Find(root->left, data))
		return ret;
	return Find(root->right, data);
}


// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	int flag = 0;
	int ret = 0;
	//空数也是完全二叉树
	if (NULL == root)
		return 1;

	//非空
	//1.按照层序遍历规则找第一个不饱和点
	QueueInit(&q);
	QueuePush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* cur = QueueFront(&q);
		if (flag)
		{
			//不饱和的节点已经找到，后序节点就不能有孩子
			if (cur->left || cur->right)
				break;	//中途退出，代码没有销毁
		}	
		else
		{
			//找第一个不饱和的点
			if (cur->left && cur->right)
			{
				//左右孩子都存在
				QueuePush(&q, cur->left);
				QueuePush(&q, cur->right);
			}
			else if (cur->left)
			{
				//cur只有左孩子
				QueuePush(&q, cur->left);
				flag = 1; //标记临界节点
			}
			else if (cur->right)
			{
				//cur只有右孩子
				break; //不是完全二叉树
			}
			else
			{
				//既没有左，也没有右，后面的节点就不能有孩子
				flag = 1;
			}
		}
		QueuePop(&q); //队头元素拿出来
	}
	
	if (QueueEmpty(&q))
		ret = 1; //为空，是完全二叉树

	QueueDestroy(&q);
	return ret;
}


//该处的传参与单链表头删是一样的
void DestroyTree(BTNode** root)
{
	assert(root); //root中的内容：就是外部实参的地址
	if (*root) //*root才是外部的实参
	{
		//&(*root)是root的地址
		DestroyTree(&(*root)->left);
		DestroyTree(&(*root)->right);
		free(*root);
		*root = NULL; //外部的实参指向空
	}
}



//////////////////////////////////////////////////////////////////////////
void TestBinTree()
{
	// 将二叉树中元素放在数组中
	// -1表示该节点不存在
	int array[] = { 1, 2, 3, -1, -1, -1, 4, 5, -1, -1, 6 };
	int index = 0;
	BTNode* root = CreateBinTree(array, sizeof(array) / sizeof(array[0]), &index, -1);
	BTNode* newroot = NULL;

	printf("前序遍历结果：\n");
	PreOrder(root);
	printf("\n");
	printf("中序遍历结果：\n");
	InOrder(root);
	printf("\n");
	printf("后序遍历结果：\n");
	PostOrder(root);
	printf("\n");
	printf("层序遍历结果：\n");
	LevelOrder(root);
	printf("\n");

	printf("GetNodeCount：%d\n", GetNodeCount(root));
	printf("GetLeafNodeCount：%d\n", GetLeafNodeCount(root));
	printf("GetKLevelNodeCount2：%d\n", GetKLevelNodeCount(root, 2));
	printf("GetKLevelNodeCount3：%d\n", GetKLevelNodeCount(root, 3));
	printf("GetKLevelNodeCount10：%d\n", GetKLevelNodeCount(root, 10));
	printf("GetHight：%d\n", GetHight(root));

	//查找
	BTNode* cur = Find(root, 5);
	if (cur)
		printf("5 is in binary tree!\n");
	else
		printf("5 is not in binary tree!\n");

	//是否完全二叉树
	if (BinaryTreeComplete(root))
		printf("Is complete binary tree!\n");
	else
		printf("Is not complete binary tree!\n");

	//拷贝
	newroot = CopyBinTree(root);
	printf("拷贝结果：\n");
	PreOrder(newroot);
	printf("\n");
	InOrder(newroot);
	printf("\n");
	PostOrder(newroot);
	printf("\n");

	DestroyTree(&root);
	DestroyTree(&newroot);
}