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

struct TreeNode* invertTree(struct TreeNode* root)
{
	if (root)
	{
		struct TreeNode* temp = root->left;
		root->

	}

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

bool isSymmetric(struct TreeNode* root)
{

}