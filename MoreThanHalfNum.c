#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int MoreThanHalfNum(int* arr,int len)
{
	int tmp[10] = { 0 };
	int i = 0;
	for (i = 0; i < len; i++)
	{
		tmp[arr[i]]++;
	}
	for (i = 0; i < 10; i++)
	{
		if (tmp[i] > (len / 2))
			return i;
	}
	return 0;
}
int main()
{
	int arr[] = { 1,2,3,2,4,2,5,2,3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int ret = MoreThanHalfNum(arr, len);
	printf("%d\n", ret);
	return 0;
}