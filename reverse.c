#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* reverse(char *str)
{
	assert(str);
	int len = strlen(str);
	char* left = str;
	char* right = str + len - 1;
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
	return str;
}
int main()
{
	char arr[100] = {0};
	gets(arr);
	reverse(arr);
	printf("%s\n", arr);
	return 0;
}