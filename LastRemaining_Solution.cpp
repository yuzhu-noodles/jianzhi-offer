#include<iostream>
using namespace std;
#include<list>

int LastRemaining_Solution(int n, int m)  //数m  孩子数n
{
	if (n <= 0 || m < 0)
		return -1;
	list<int> L;
	for (int i = 0; i < n; i++)
		L.push_back(i);
	int index = 0;
	while (n > 1)
	{
		index = (index + m - 1) % n;
		list<int>::iterator it = L.begin();
		advance(it, index);
		L.erase(it);
		n--;
	}
	return L.back();
}

int main()
{
	int n;
	cout << "请问有多少个孩子：";
	cin >> n;
	cout << "请问输入一个数：";
	int m;
	cin >> m;
	cout << "中奖的孩子：";
	int pos = LastRemaining_Solution(n, m);
	cout << pos;
	system("pause");
	return 0;
}