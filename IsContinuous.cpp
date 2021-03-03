#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

bool IsContinuous(vector<int> v)
{
	if (v.empty())
		return false;
	sort(v.begin(), v.end());
	int countZero = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		if (*it == 0)
			countZero++;
	}
	int small = countZero;
	int big = countZero + 1;
	int gap = 0;
	while (big < v.size())
	{
		if (v[small] == v[big])
			return false;
		gap += v[big] - v[small] - 1;
		small = big;
		big++;
	}
	if (countZero < gap)
		return false;
	else
		return true;
}
int main()
{
	vector<int> v;
	v.push_back(0);
	v.push_back(3);
	v.push_back(1);
	v.push_back(6);
	v.push_back(4);
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	//{
	//	cout << *it << endl;
	//}
	cout << IsContinuous(v) << endl;
	system("pause");
	return 0;
}
