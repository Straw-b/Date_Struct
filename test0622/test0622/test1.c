//1. ��ֵ������
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




//2. ������������
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




//3. ��ת������
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

// ����һ���ݹ�
struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root)
	{
		// ��root�����Һ��ӽ��н���
		struct TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;

		invertTree(root->left);
		invertTree(root->right);
	}

	return root;
}




//4. ����������Ƿ���ͬ
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

	// ��������һ���ǿ���
	if (NULL == p || NULL == q)
		return false;

	// ����������Ϊ��
	return p->val == q->val && 
		isSameTree(p->left, q->left) && 
		isSameTree(p->right, q->right);
}




//5. �Գƶ�����
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

// ���p��q�Ƿ�Ϊ����
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




// 6. ��������ǰ�����
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

// �Զ���������ǰ�������Ȼ�󽫱����Ľ�������������з���
// ��ȻҪ�����������У���������Ҫ�����Ŀռ��أ�
// ����Ҫ���ռ䣺ȡ���ڶ������нڵ�ĸ���

// ��ȡ�������нڵ����
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

	// �������������ڵ��е�ֵ�򱣴���������
	array[(*index)++] = root->val;
	_preorderTraversal(root->left, array, index);
	_preorderTraversal(root->right, array, index);
}

// returnSize������Ͳ���---����������һ�ַ���ֵ�ķ�ʽ---��ͨ������������ֵ����ȥ
// ����ֵ�����ؿռ�ֵ���׵�ַ
// �ռ���Ԫ�صĸ�����ͨ��returnSize����������
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




//10. �ж�һ�Ŷ������Ƿ���ƽ�������
// ÿ���ڵ���������������ĸ߶Ȳ�ľ���ֵ������1
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

// ����һ
// ʱ�临�Ӷȣ�O(N^2)
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

	//�����ڵ��Ƿ�����ƽ����
	int leftHeight = Height(root->left);
	int rightHeight = Height(root->right);
	if (abs(rightHeight - leftHeight) > 1)
		return false;

	//�ݹ�����ڵ�����������Ƿ����������������
	return isBalanced(root->left) && isBalanced(root->right);
}

// ���������ô�������һ���ظ���߶ȹ��
// ʱ�临�Ӷȣ�O(N)
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




//11. �������Ĺ���������
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
		// �������ڵ�
		root = BuyTreeNode(szTree[*index]);

		// �������ڵ��������
		++(*index);
		root->left = CreatBinTree(szTree, size, index, invalid);

		// �������ڵ��������
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
	// ������Ľ����Ϊѭ������
	while (EOF != scanf("%s", szTree))
	{
		size = strlen(szTree);
		TreeNode* root = CreatBinTree(szTree, size, &index, '#');
		InOrder(root);
		printf("\n");
	}
	return 0;
}




//9. ��һ����������
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

	// ��������һ���ǿ���
	if (NULL == p || NULL == q)
		return false;

	// ����������Ϊ��
	return p->val == q->val &&
		isSameTree(p->left, q->left) &&
		isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
	if (NULL == s)
		return false;

	// s�������ڣ�t��������
	if (NULL == t)
		return true;

	// s��t������Ϊ��
	// ���ڵ�һ�������п���������
	if (s->val == t->val && isSameTree(s, t))
		return true;
	
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}
