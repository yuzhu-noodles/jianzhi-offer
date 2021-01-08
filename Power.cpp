#include<iostream>
using namespace std;

double Power(double base, int exponent)
{
	double result = base;
	if (base == 0)
		return 0;
	if (exponent > 0)
	{
		for (int i = 0; i < exponent-1; i++)
		{
			result *= base;
		}
		return result;
	}
	else if (exponent < 0)
	{
		for (int i = exponent+1; i < 0; i++)
		{
			result *= base;
		}
		return 1 / result;
	}
	else
	{
		return 1;
	}
}
int main()
{
	double a = 2;
	int b = -2;
	double ret = Power(a, b);
	cout << ret << endl;
	system("pause");
	return 0;
}