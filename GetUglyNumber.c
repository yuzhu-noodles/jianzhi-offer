#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int GetUglyNumber(int n)
{
	int num = 1;
	int k = 0;
	while (k < n)
	{
		//isUgly
		int tmp = num;
		while (tmp % 2 == 0)
		{
			tmp /= 2;
		}
		while (tmp % 3 == 0)
		{
			tmp /= 3;
		}
		while (tmp % 5 == 0)
		{
			tmp /= 5;
		}
		if (tmp == 1)
		{
			k++;
		}
		num++;
	}
	return num-1;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = GetUglyNumber(n);
	printf("%d", ret);
	return 0;
}
