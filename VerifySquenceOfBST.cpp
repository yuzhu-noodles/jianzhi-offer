#include<iostream>
using namespace std;
#include<vector>


//二叉搜索树特征：左子树<根节点，右子树>根节点
//后续遍历
bool verifty(vector<int>S, int begin, int end);
bool VerifySquenceOfBST(vector<int> sequence)
{
	if (sequence.empty())
		return false;
	return verifty(sequence, 0, sequence.size()-1);
}

bool verifty(vector<int>S, int begin, int end)
{
	if (S.empty() || begin > end)
		return false;
	int i = begin;         //划分左子树，都小于根节点
	for (; i < end; i++)
	{
		if (S[i] > S[end])
			break;
	}
	int j = i;             //判断右子树
	for (; j < end; j++)
	{
		if (S[j] < S[end])
			return false;
	}
	bool left = true;
	if (begin < i)
	{
		left = verifty(S, begin, i-1);
	}
	bool right = true;
	if (i < end - 1)
		right = verifty(S, i, end - 1);
	return left && right;
}

int main()
{
	int arr[7] = { 4,8,6,12,16,14,10 };
	int len = sizeof(arr) / sizeof(arr[0]);
	vector<int>v(arr,arr+len);
	cout << VerifySquenceOfBST(v) << endl;
	system("pause");
	return 0;
}