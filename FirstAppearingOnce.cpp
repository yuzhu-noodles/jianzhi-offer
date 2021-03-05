#include<iostream>
using namespace std;
#include<map>


map<char, int>Map;
string s = "";
//Insert one char from stringstream
void Insert(char ch)
{
	s += ch;
	Map[ch]++;
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
	for (int i = 0; i < s.size(); i++)
	{
		if (Map[s[i]] == 1)
			return s[i];
	}
	return '#';
}

int main()
{
	string str;
	cout << "请输入字符串:";
	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		Insert(str[i]);
	}
	cout <<"字符流中第一个不重复的字符："<< FirstAppearingOnce() << endl;
	system("pause");
	return 0;
}
