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
	if (NULL == value)
		return true;

	if (root->val != value)
		return false;

	return _isUnivalTree()
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

struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root)
	{
		struct TreeNode* temp = root->left;
		root->

	}

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

bool isSymmetric(struct TreeNode* root)
{

}