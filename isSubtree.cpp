#include<iostream>
using namespace std;
#include<vector>

typedef struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int n) :val(n), left(NULL), right(NULL) {}
}TreeNode;

//创建二叉树树
TreeNode* CreatBiTree(vector<int> arr, int start) {
	if (arr[start] == '-1')
		return NULL;
	TreeNode* root = new TreeNode(arr[start]);
	int left_index = 2 * start + 1;
	int right_index = 2 * start + 2;
	if (left_index > arr.size() - 1)
		root->left = NULL;
	else
		root->left = CreatBiTree(arr, left_index);
	if (right_index > arr.size() - 1)
		root->right = NULL;
	else
		root->right = CreatBiTree(arr, right_index);
	return root;
}
//判断是否为子树
bool DFS(TreeNode* A, TreeNode* B) {
	if (!A || !B) {
		if (!B) return true;  //B已经为空，说明B已经遍历完，说明B为A的子结构
		else return false;   //A遍历完，B没有遍历完，说明B不为A的子结构
	}
	if (A->val != B->val) return false;  //AB节点不相等，B不为A的子结构
	return DFS(A->left, B->left) && DFS(A->right, B->right);  //递归判断A的左子树和右子树是否相等
}
bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
	if (!pRoot1 || !pRoot2) return false;  //判断空树
	return DFS(pRoot1, pRoot2) || isSubtree(pRoot1->left, pRoot2) || isSubtree(pRoot1->right, pRoot2);
}
//打印
void PrintBitree(TreeNode* root) {
	if (!root) return;
	cout << root->val << "->";
	PrintBitree(root->left);
	PrintBitree(root->right);
}
int main() {
	int a1[] = { 8,8,-1,9,-1,2,-1,5 }; 
	int len1 = sizeof(a1) / sizeof(*a1);
	vector<int> arr1(a1, a1 + len1);
	int a2[] = { 8,8,-1,9,-1,2 };
	int len2 = sizeof(a2) / sizeof(*a2);
	vector<int> arr2(a2, a2 + len2);
	TreeNode* root1 = CreatBiTree(arr1, 0);
	TreeNode* root2 = CreatBiTree(arr2, 0);
	//PrintBitree(root1);
	//cout << endl;
	//PrintBitree(root2);
	if (isSubtree(root1, root2))
		cout << "root2是root1的子树" << endl;
	else
		cout << "root2不是root1的子树" << endl;
	return 0;
}