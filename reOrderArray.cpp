#include<iostream>
using namespace std;
#include<vector>

//暴力法，便利
vector<int> reOrderArray1(vector<int>& array)
{
	vector<int> v;
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] % 2 != 0)
		{
			v.push_back(array[i]);
		}
	}
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i] % 2 == 0)
		{
			v.push_back(array[i]);
		}
	}
	return v;
}

//冒泡法，交换左右奇偶数
vector<int> reOrderArray2(vector<int>& array)
{

	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array.size() - 1; j++)
		{
			if (array[j] % 2 == 0 && array[j + 1] % 2 != 0)
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
	return array;
}
int main()
{
	vector<int> v;
	for (int i = 1; i < 8; i++)
	{
		v.push_back(i);
	}
	vector<int> v2 = reOrderArray2(v);
	cout << "交换后：" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << v2[i] << " ";
	}
	system("pause");
	return 0;
}