#include<iostream>
using namespace std;

void FindNumbersWithSum(int *arr,int sz,int sum)
{
	int start = 0;
	int end = sz - 1;
	while (start < end)
	{
		if (arr[start] + arr[end] < sum)
		{
			start++;
		}
		else if (arr[start] + arr[end] > sum)
		{
			end--;
		}
		else
		{
			cout << "num1= " << arr[start] << " num2= " << arr[end] << endl;
			break;
		}
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int sum = 11;
	FindNumbersWithSum(arr,sz,sum);
	system("pause");
	return 0;
}