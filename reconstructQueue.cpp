#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//根据身高重建队列
//假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。
//请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。


//方法，先按照身高排序，然后再通过K进行插入
class Solution {
public:
	static bool cmp(const vector<int> a, const vector<int> b)
	{
		if (a[0] == b[0]) return a[1] < b[1];
		return a[0] > b[0];
	}
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
	{
		sort(people.begin(), people.end(), cmp);
		vector<vector<int>> ret;
		for (int i = 0; i < people.size(); i++)
		{
			int index = people[i][1];
			ret.insert(ret.begin() + index, people[i]);
		}
		return ret;
	}
};
int main()
{
	int arr[6][2] = { {7,0},{4,4},{7,1},{5,0},{6,1},{5,2} };
	vector<vector<int>> people(6,vector<int>(2));
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			people[i][j] = arr[i][j];
		}
	}
	Solution s;
	vector<vector<int>> ret = s.reconstructQueue(people);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j]<<" ";
		}
		cout << "]";
	}
	return 0;
}