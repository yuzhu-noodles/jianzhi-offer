#include<iostream>
using namespace std;
#include<vector>

typedef struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;


TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	if (pre.empty()||vin.empty())
		return NULL;
	TreeNode* head = new TreeNode(pre[0]);
	int root= 0;
	for (int i =0; i < pre.size(); ++i)
	{
		if (vin[i] == pre[0])
		{
			root = i;
			break;
		}
	}
	vector<int> pre_left, pre_right, vin_left, vin_right;
	for (int i = 0; i < root; ++i)
	{
		pre_left.push_back(pre[i + 1]);
		vin_left.push_back(vin[i]);
	}
	for (int i = root+1; i < pre.size(); ++i)
	{
		pre_right.push_back(pre[i]);
		vin_right.push_back(vin[i]);
	}
	head->left = reConstructBinaryTree(pre_left, vin_left);
	head->right = reConstructBinaryTree(pre_right, vin_right);
	return head;
}
//Ç°Ðò±éÀú
void PrePrint(TreeNode* root)
{
	if (root)
	{
		cout << root->val << "-->";
		PrePrint(root->left);
		PrePrint(root->right);

	}
}

int main()
{
	int arr1[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int arr2[7] = { 3, 2, 4, 1, 6, 5, 7 };
	vector<int> v1(arr1,arr1+7);
	vector<int> v2(arr2,arr2+7);
	TreeNode* root = reConstructBinaryTree(v1, v2);
	PrePrint(root);
	system("pause");
	return 0;
}