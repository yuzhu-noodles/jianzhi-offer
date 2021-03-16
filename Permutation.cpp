#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<string>

void permperm(string str, int pos, set<string>& ret)
{
	if (pos + 1 == str.size())
	{
		ret.insert(str);
		return;
	}

	for (int i = pos; i < str.size(); i++)
	{
		swap(str[i], str[pos]);
		permperm(str, pos + 1, ret);
		swap(str[pos], str[i]);
	}
}
vector<string> Permutation(string str)
{
	set<string> s;
	if (str.empty())
		return {};
	permperm(str, 0, s);
	vector<string> v(s.begin(),s.end());
	return v;
}

int main()
{
	string str = "ABC";
	vector<string> v = Permutation(str);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	system("pause");
	return 0;
}