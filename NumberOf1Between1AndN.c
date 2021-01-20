#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int NumberOf1Between1AndN(int n)
{
	if (n <= 0)
		return 0;
	int count = 0;
	int i = 0;
	for (i = 1; i <= n; i++)
	{
		int k = i;
		while (k)
		{
			if (k % 10 == 1)
			{
				count++;
			}
			k = k / 10;
		}
	}
	return count;
}
int main()
{
	
	int ret = NumberOf1Between1AndN(13);
	printf("%d\n",ret);
	return 0;
}