#include<iostream>
using namespace std;

typedef struct TreeNode
{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode,*BiTree;

void InitTree(BiTree* tree)
{
	(*tree) = NULL;
}

void CreatTree(BiTree* tree)
{
	int num;
	cin >> num;
	if (num == 0)
		tree = NULL;
	else
	{
		*tree = (TreeNode*)malloc(sizeof(TreeNode));
		if (*tree == NULL)
			return;
		else
		{
			(*tree)->data = num;
			(*tree)->left = NULL;
			(*tree)->right = NULL;
			cout << "左节点:";
			CreatTree(&(*tree)->left);
			cout << "右节点:";
			CreatTree(&(*tree)->right);
		}
	}
}

void PrePrint(BiTree root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	PrePrint(root->left);
	PrePrint(root->right);
}

//计算深度
int TreeDepth(BiTree pRoot)
{
	int Ldepth = 0;
	int Rdepth = 0;
	if (!pRoot)
		return 0;
	Ldepth = TreeDepth(pRoot->left);
	Rdepth = TreeDepth(pRoot->right);
	if (Ldepth > Rdepth)
		return Ldepth + 1;
	else
		return Rdepth + 1;
}
int main()
{
	BiTree root;
	InitTree(& root);
	cout << "跟节点：";
	CreatTree(&root);
	cout << "前序遍历树\n";
	PrePrint(root);
	cout << "树深度：" << TreeDepth(root) << endl;
	system("pause");
	return 0;
}