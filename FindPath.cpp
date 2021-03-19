#include<iostream>
using namespace std;
#include<vector>

typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode,*BiTree;

void InitBT(BiTree* tree)
{
	*tree = NULL;
}

void CreatBT(BiTree* tree)
{
	int num;
	cin >> num;
	if (num == 0)
		(*tree) = NULL;
	else
	{
		*tree = (BiTree)malloc(sizeof(TreeNode));
		if (!(*tree))
			return;
		else
		{
			(*tree)->val = num;
			(*tree)->left = NULL;
			(*tree)->right = NULL;
			cout << "左节点：";
			CreatBT(&(*tree)->left);
			cout << "右节点：";
			CreatBT(&(*tree)->right);
		}
	}
}
//打印
//void PrintBT(BiTree* tree)
//{
//	if (!(*tree))
//		return;
//	else
//	{
//		cout << (*tree)->val << "->";
//		PrintBT(&(*tree)->left);
//		PrintBT(&(*tree)->right);
//	}
//}

void Path(vector<vector<int>> &ret, vector<int> &path,TreeNode* root,int num)
{
	if (root==NULL)
		return;
	path.push_back(root->val);
	if (root->left == NULL && root->right == NULL && root->val == num)
		ret.push_back(path);
	if (root->left)
		Path(ret, path, root->left, num - root->val);
	if(root->right)
		Path(ret, path, root->right, num - root->val);
	path.pop_back();
}
vector<vector<int> > FindPath(TreeNode* root, int expectNumber)
{
	vector<vector<int>> ret;
	vector<int> path;
	Path(ret, path, root, expectNumber);
	return ret;
}

int main()
{
	BiTree tree;
	InitBT(&tree);
	cout << "请输入根节点：";
	CreatBT(&tree);
	/*PrintBT(&tree);*/
	int expectNumber;
	cout << "请输入expectNumber：";
	cin >> expectNumber;
	vector<vector<int>> ret = FindPath(tree, expectNumber);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
