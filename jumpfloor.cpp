#include<iostream>
using namespace std;

int JumpFloor(int n)
{
	int a = 0;
	int b = 1;
	int sum = 0;
	if (n == 1)
		sum = 1;
	for (int i = 0; i < n ; i++)
	{
		sum = a + b;
		a = b;
		b = sum;
	}
	return sum;
}
int main()
{
	int num = 0;
	cin >> num;
	int ret = JumpFloor(num);
	cout << "Ìø·¨£º" << ret << endl;
	system("pause");
	return 0;
}