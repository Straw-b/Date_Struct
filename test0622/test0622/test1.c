//1. 单值二叉树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool _isUnivalTree(struct TreeNode* root, int value)
{
	if (NULL == root)
		return true;

	if (root->val != value)
		return false;

	return _isUnivalTree(root->left, value) && _isUnivalTree(root->right, value);
}

bool isUnivalTree(struct TreeNode* root)
{
	if (NULL == root)
		return true;

	int value = root->val;
	return _isUnivalTree(root, value);
}




//2. 二叉树最大深度
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

int maxDepth(struct TreeNode* root)
{
	if (NULL == root)
		return 0;

	int leftHeight = maxDepth(root->left);
	int rightHeight = maxDepth(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}




//3. 翻转二叉树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

// 方法一：递归
struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root)
	{
		// 将root的左右孩子进行交换
		struct TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		invertTree(root->left);
		invertTree(root->right);
	}

	return root;
}




//4. 检查两颗树是否相同
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (NULL == p && NULL == q)
		return true;

	// 两棵树有一颗是空树
	if (NULL == p || NULL == q)
		return false;

	// 两棵树都不为空
	return p->val == q->val && 
		isSameTree(p->left, q->left) && 
		isSameTree(p->right, q->right);
}




//5. 对称二叉树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

// 检测p和q是否为镜像
bool _isSymmetric(struct TreeNode* p, struct TreeNode* q)
{
	if (NULL == p && NULL == q)
		return true;

	if (NULL == p || NULL == q)
		return false;

	return p->val == q->val &&
		_isSymmetric(p->left, q->right) &&
		_isSymmetric(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root)
{
	if (NULL == root)
		return true;

	return _isSymmetric(root->left, root->right);
}




// 6. 二叉树的前序遍历
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

// 对二叉树进行前序遍历，然后将遍历的结果保存在数组中返回
// 既然要保存在数组中：问题数组要给多大的空间呢？
// 数组要多大空间：取决于二叉数中节点的个数

// 获取二叉树中节点个数
int GetSize(struct TreeNode* root)
{
	if (NULL == root)
		return 0;

	return GetSize(root->left) + GetSize(root->right) + 1;
}

void _preorderTraversal(struct TreeNode* root, int* array, int* index)
{
	if (NULL == root)
		return;

	// 遍历操作：将节点中的值域保存在数组中
	array[(*index)++] = root->val;
	_preorderTraversal(root->left, array, index);
	_preorderTraversal(root->right, array, index);
}

// returnSize：输出型参数---类似于另外一种返回值的方式---即通过参数经返回值带回去
// 返回值：返回空间值的首地址
// 空间中元素的个数：通过returnSize参数带出的
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
	*returnSize = GetSize(root);
	int* ret = (int*)malloc((*returnSize) * sizeof(int));
	
	if (NULL == ret)
		return NULL;

	int index = 0;
	_preorderTraversal(root, ret, &index);
	return ret;
}




//10. 判断一颗二叉树是否是平衡二叉树
// 每个节点的左右两个子树的高度差的绝对值不超过1
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

// 方法一
// 时间复杂度：O(N^2)
int Height(struct TreeNode* root)
{
	if (NULL == root)
		return 0;

	int leftHeight = Height(root->left);
	int rightHeight = Height(root->right);
	return leftHeight > rightHeight? leftHeight + 1 : rightHeight + 1;
}

bool isBalanced(struct TreeNode* root)
{
	if (NULL == root)
		return true;

	//检测根节点是否满足平衡性
	int leftHeight = Height(root->left);
	int rightHeight = Height(root->right);
	if (abs(rightHeight - leftHeight) > 1)
		return false;

	//递归检测根节点的左右子树是否满足二叉树的性质
	return isBalanced(root->left) && isBalanced(root->right);
}

// 方法二：好处将方法一中重复求高度规避
// 时间复杂度：O(N)
bool _isBalanced(struct TreeNode* root, int* treeheight)
{
	if (NULL == root)
	{
		*treeheight = 0;
		return true;
	}

	int leftHeight = 0, rightHeight = 0;
	if (_isBalanced(root->left, &leftHeight) &&
		_isBalanced(root->right, &rightHeight) &&
		abs(rightHeight - leftHeight) <= 1)
	{
		*treeheight = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
		return true;
	}

	return false;
}

bool isBalanced(struct TreeNode* root)
{
	int height = 0;
	return _isBalanced(root, &height);
}




//11. 二叉树的构建及遍历
#include <stdio.h>
#include <malloc.h>

typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char ch;
}TreeNode;

TreeNode* BuyTreeNode(char ch)
{
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	if (NULL == newnode)
	{
		return NULL;
	}

	newnode->left = NULL;
	newnode->right = NULL;
	newnode->ch = ch;
	return newnode;
}

TreeNode* CreatBinTree(char szTree[], int size, int* index, char invalid)
{
	TreeNode* root = NULL;
	if (*index < size && szTree[*index] != invalid)
	{
		// 创建根节点
		root = BuyTreeNode(szTree[*index]);

		// 创建根节点的左子树
		++(*index);
		root->left = CreatBinTree(szTree, size, index, invalid);

		// 创建根节点的右子树
		++(*index);
		root->right = CreatBinTree(szTree, size, index, invalid);
	}
	return root;
}

void InOrder(TreeNode* root)
{
	if (root)
	{
		InOrder(root->left);
		printf("%c ", root->ch);
		InOrder(root->right);
	}
}

int main()
{
	char szTree[100] = { 0 };
	int size = 0;
	int index = 0;
	// 将输入的结果作为循环条件
	while (EOF != scanf("%s", szTree))
	{
		size = strlen(szTree);
		TreeNode* root = CreatBinTree(szTree, size, &index, '#');
		InOrder(root);
		printf("\n");
	}
	return 0;
}




//9. 另一颗树的子树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (NULL == p && NULL == q)
		return true;

	// 两棵树有一颗是空树
	if (NULL == p || NULL == q)
		return false;

	// 两棵树都不为空
	return p->val == q->val &&
		isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	if (NULL == s)
		return false;

	// s的树存在，t树不存在
	if (NULL == t)
		return true;

	// s和t树都不为空
	// 根节点一样，才有可能是子树
	if (s->val == t->val && isSameTree(s, t))
		return true;
	
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}
