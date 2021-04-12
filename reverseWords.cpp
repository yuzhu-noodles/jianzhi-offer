#include<iostream>
using namespace std;

//删除多余空格
void removespace(string& s)
{
	int fast = 0;
	int slow = 0;
	//去除字符串前面的空格
	while(s.size()>0 && fast<s.size() && s[fast] == ' ')
	{
		fast++;
	}
	for(;fast<s.size();fast++)
	{
		if(fast-1>0 && s[fast] == s[fast-1] && s[fast] == ' ')
		{
			continue;
		}
		else
		{
			s[slow++] = s[fast];
		}
	}
	if(slow-1>0 && s[slow-1] == ' ')
	{
		s.resize(slow-1);
	}
	else
	{
		s.resize(slow);
	}
}
//反转单个单词
void reverse(string& s)
{
	int begin = 0;
	int end = 0;
	for(int i = 0;i<=s.size();i++)
	{
		if(s[i] == ' '|| i == s.size())
		{
			end = i-1;
			while(begin<end)
			{
				swap(s[begin++],s[end--]);
			}
			begin = i+1;
			end = i+1;
		}
	}
}

string reverseWords(string s)
{
	//删除多余空格
	//反转单词
	//反转全部
	int begin =0 ;
	int end = s.size()-1;
	while(begin<end)
	{
		swap(s[begin++],s[end--]);
	}
    return s;
}

int main()
{
	string s = "  the  sky is                       blue   ";
	removespace(s);
	reverse(s);
	string str = reverseWords(s);
	cout<<str<<endl;
	return 0;
}

