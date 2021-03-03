#include<iostream>
using namespace std;


string replaceSpace(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			s.replace(i, 1, "%20");
		}
	}
	return s;
}

string replaceSpace2(string s)
{
	string temps;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != ' ')
			temps += s[i];
		else
			temps += "%20";
	}
	return temps;
}

int main()
{
	string s = "We Are Happy";
	cout<< replaceSpace2(s) << endl;
	system("pause");
	return 0;
}