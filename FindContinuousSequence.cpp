#include<iostream>
using namespace std;
#include<vector>

//等差数列求和公式(a0+an)*n/2

vector<vector<int> > FindContinuousSequence(int sum)
{
	vector<vector<int>> ret;
	int left = 1;
	int right = 2;
	while (right > left)
	{
		int s = (left + right) * (right - left + 1) / 2;
		if (s > sum)
		{
			left++;
		}
		else if (s < sum)
		{
			right++;
		}
		else
		{
			vector<int> v;
			for (int i = left; i <= right; i++)
			{
				v.push_back(i);
			}
			ret.push_back(v);
			left++;
		}
	}
	return ret;
}


int main()
{
	int sum = 0;
	cin >> sum;
	vector<vector<int>> ret = FindContinuousSequence(sum);
	for (int i = 0; i < ret.size(); i++)
	{
		for (int j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j]<<" ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}