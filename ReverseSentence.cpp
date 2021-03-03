#include<iostream>
#include<algorithm>
using namespace std;

//以空格为分界点，，先翻转字符串中每个单词；
//然后整体翻转

string ReverseSentence(string str) 
{
	int n = 0;
	for (int i = 0; i < str.length(); i++)
	{
		while (i<str.length()&&str[i] != ' ')
		{
			i++;
		}
		reverse(str.begin() + n, str.begin() + i);
		n = i + 1;
	}
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	string s = "student. a am i";//
	string ss = ReverseSentence(s);
	cout << ss << endl;
	system("pause");
	return 0;
}