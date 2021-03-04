#include<iostream>
using namespace std;

int FirstNotRepeatingChar1(string str)
{
	if (str.empty())
		return -1;
	unsigned int count[256] = {0};
	for (int i = 0; i < str.size(); i++)
	{
		count[str[i]]++;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (count[str[i]] == 1)
			return i;
	}
	return -1;
}

//利用string find和rfind
//从头遍历，如果正反查找返回值相等，则返回第一个只出现一次的字符
int FirstNotRepeatingChar2(string str)
{
	if (str.empty())
		return -1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str.find(str[i]) == str.rfind(str[i]))
			return i;
	}
	return -1;
}
int main()
{
	string s = "google";
	cout << FirstNotRepeatingChar1(s) << endl;
	system("pause");
	return 0;
}
