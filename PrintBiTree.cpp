#include<iostream>
using namespace std;
#include<vector>
#include<stack>
typedef struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int n) :val(n), left(NULL), right(NULL) {}
}TreeNode;

TreeNode* CreatBiTree(vector<int> arr, int start) {
	if (arr[start] == -1)
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


//按之字形打印
vector<vector<int> > Print(TreeNode* pRoot) {
    vector<vector<int> > result;
    if (pRoot == NULL) {
        return result;
    }
    stack<TreeNode* > s[2];
    s[0].push(pRoot);
    while (!s[0].empty() || !s[1].empty()) {
        vector<int> v[2];
        // 偶数行
        while (!s[0].empty()) {
            v[0].push_back(s[0].top()->val);
            if (s[0].top()->left != NULL) {
                s[1].push(s[0].top()->left);
            }
            if (s[0].top()->right != NULL) {
                s[1].push(s[0].top()->right);
            }
            s[0].pop();
        }
        if (!v[0].empty()) {
            result.push_back(v[0]);
        }
        // 奇数行
        while (!s[1].empty()) {
            v[1].push_back(s[1].top()->val);
            if (s[1].top()->right != NULL) {
                s[0].push(s[1].top()->right);
            }
            if (s[1].top()->left != NULL) {
                s[0].push(s[1].top()->left);
            }
            s[1].pop();
        }
        if (!v[1].empty()) {
            result.push_back(v[1]);
        }
    }
    return result;
}
int main() {
	int a[] = { 1, 2, 3, 4, 5, -1, 6, -1, -1, 7, 8 };
	int len = sizeof(a) / sizeof(*a);
	vector<int> arr(a,  a + len);
	TreeNode* root = CreatBiTree(arr, 0);
    vector<vector<int>> ret = Print(root);
    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
}