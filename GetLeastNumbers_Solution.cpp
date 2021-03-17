#include<iostream>
using namespace std;
#include<vector>
#include<set>
//暴力法
vector<int> GetLeastNumbers_Solution1(vector<int> input, int k)
{
	vector<int> ret;
	int size = input.size();
	if (size < k)
		return ret;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if (input[j] < input[j + 1])
			{
				swap(input[j], input[j + 1]);
			}
		}
		ret.push_back(input[input.size()-1]);
		input.pop_back();
	}
	return ret;
}

//使用set容器
vector<int> GetLeastNumbers_Solution2(vector<int> input, int k)
{
	if (input.size() < k)
		return {};
	set<int> s(input.begin(), input.end());
	set<int>::iterator it = s.begin();
	while (k)
	{
		it++;
		k--;
	}
	vector<int> ret(s.begin(),it);
	return ret;
}

int main()
{
	vector<int> input;
	int arr[8] = { 4, 5, 1, 6, 2, 7, 3, 8 };
	for (int i = 0; i < 8; i++)
	{
		input.push_back(arr[i]);
	}
	vector<int> ret = GetLeastNumbers_Solution2(input,4);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i]<<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}