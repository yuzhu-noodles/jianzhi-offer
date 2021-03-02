#include<iostream>
using namespace std;
#include<algorithm>


//思路：
//判断字符串是否为空
//为空返回空字符串""
//不为空    例如：abcdef  2
//先旋转前n个字符串  ba cdef
//再旋转n后面的字符串 ba fedc
//最后旋转全部     cdefab
string LeftRotateString(string str, int n)
{
	if (str.empty())
		return "";
	reverse(str.begin(), str.begin() + n);
	reverse(str.begin() + n, str.end());
	reverse(str.begin(), str.end());
	return str;
}
int main()
{
	string s = "\0";
	string s2 = LeftRotateString(s, 2);
	cout << s2 << endl;
	system("pause");
	return 0;
}