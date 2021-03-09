#include<iostream>
using namespace std;
#include<queue>

typedef struct TreeNode
{
	char data;
	struct TreeNode* LChild;
	struct TreeNode* RChild;

}TreeNode, * BiTree;

void InitTree(BiTree* tree)
{
	(*tree) = NULL;
}

void Creat(BiTree* tree)
{
	char ch;
	cin >> ch;
	if (ch == '#')
	{
		*tree = NULL;
	}
	else
	{
		*tree = (BiTree)malloc(sizeof(TreeNode));
		if (NULL == (*tree))
		{
			exit(0);
		}
		else
		{
			(*tree)->data = ch;
			(*tree)->LChild = NULL;
			(*tree)->RChild = NULL;
			cout << "左子树：";
			Creat(&(*tree)->LChild);
			cout << "右子树：";
			Creat(&(*tree)->RChild);
		}
	}
}

TreeNode* Mirror(TreeNode* root)
{
	if (!root)
	{
		return NULL;
	}
	TreeNode* temp = root->LChild;
	root->LChild = root->RChild;
	root->RChild = temp;
	Mirror(root->LChild);
	Mirror(root->RChild);
	return root;
}

//层序遍历
void FloorPrint(BiTree& tree)
{
	queue<BiTree> q;
	if (tree != NULL)
	{
		q.push(tree);
	}
	while (q.empty() == false)
	{
		cout << q.front()->data << "->";
		if (q.front()->LChild != NULL)
		{
			q.push(q.front()->LChild);
		}
		if (q.front()->RChild != NULL)
		{
			q.push(q.front()->RChild);
		}
		q.pop();
	}
}



int main()
{
	BiTree tree;
	InitTree(&tree);
	cout << "输入跟节点：";
	Creat(&tree);
	cout << "镜像前：" << endl;
	FloorPrint(tree);
	cout << "镜像后：" << endl;
	TreeNode* mirror = Mirror(tree);
	FloorPrint(mirror);
	system("pause");
	return 0;
}