#include<iostream>
using namespace std;

//Ì°À·Ëã·¨
int cutRope(int number)
{
	if (number == 1)
		return 0;
	if (number == 2)
		return 1;
	if (number == 3)
		return 2;
	if (number == 4)
		return 4;
	int i = number % 3;  
	int j = number / 3;
	if (i == 1)
		return pow(3, j - 1) * 4;
	else if (i == 2)
		return pow(3, j) * 2;
	else
		return pow(3, j);
}
int main()
{
	int ret = cutRope(8);
	cout << ret << endl;
	system("pause");
	return 0;
}