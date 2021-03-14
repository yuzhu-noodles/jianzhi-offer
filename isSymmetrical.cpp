#include<iostream>
using namespace std;

typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode,*BiTree;

void Init(BiTree* tree)
{
	*tree = NULL;
}
void Creat(BiTree* tree)
{
	int val;
	cin>>val;
	if (val == 0)
		*tree = NULL;
	else
	{
		*tree = (BiTree)malloc(sizeof(TreeNode));
		if (*tree == NULL)
			return;
		else
		{
			(*tree)->val = val;
			(*tree)->left = NULL;
			(*tree)->right = NULL;
			cout << "左节点：";
			Creat(&(*tree)->left);
			cout << "右节点：";
			Creat(&(*tree)->right);
		}
	}
}
void PrePrint(BiTree* tree)
{
	if (*tree == NULL)
		return;
	cout << (*tree)->val<<"-->";
	PrePrint(&(*tree)->left);
	PrePrint(&(*tree)->right);
}
bool Compare(TreeNode* LChild,TreeNode* RChild)
{
	if (LChild == NULL && RChild == NULL)
		return true;
	else if (LChild == NULL && RChild != NULL || LChild != NULL && RChild == NULL)
		return false;
	else
	{
		if (LChild->val == RChild->val && Compare(LChild->left, RChild->right) && Compare(LChild->right, RChild->left))
			return true;
		else
			return false;
	}
}
bool isSymmetrical(TreeNode* root)
{
	if (root == NULL)
		return true;
	else
		return Compare(root->left, root->right);
}
int main()
{
	BiTree tree;
	Init(&tree);
	cout << "请输入根节点：";
	Creat(&tree);
	PrePrint(&tree);
	cout << endl;
	int ret = isSymmetrical(tree);
	if (ret == 1)
		cout << "该二叉树对称！" << endl;
	if(ret == 0)
		cout << "该二叉树不对称！" << endl;
	system("pause");
	return 0;
}