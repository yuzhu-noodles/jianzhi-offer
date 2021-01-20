#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void reOrderArray(int *p,int sz)
{
	int j = 0;
	int k = 0;
	for (int i = 0; i < sz; i++)
	{
		if (p[i] % 2 == 1)
		{
			int tmp = p[i];
			int j = 0;
			for (j = i; j >k; j--)
			{
				p[j] = p[j-1];
			}
			p[k] = tmp;
			k++;
		}
	}

}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int len = sizeof(arr) / sizeof(arr[0]);
	reOrderArray(arr, len);
	int i = 0;
	for (i = 0; i < len; i++)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	return 0;
}