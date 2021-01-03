#include<iostream>
using namespace std;

int Fibonacci(int n)
{
	int a = 0;
	int b = 1;
	int sum = 0;
	if (n == 0)
		sum = 0;
	if (n == 1)
		sum = 1;
	for (int i = 0; i < n-1; i++)
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
	int ret = Fibonacci(num);
	cout << "斐波那契数列的第" << num << "项：" << ret << endl;
	system("pause");
	return 0;
}