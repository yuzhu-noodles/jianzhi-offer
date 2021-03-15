#include<iostream>
using namespace std;
#include<vector>

vector<int> printMatrix(vector<vector<int> > matrix)
{
	vector<int> ret;
	if (matrix.empty())
		return ret;
	int left = 0;
	int right = matrix[0].size()-1;
	int top = 0;
	int btm = matrix.size()-1;

	while (left <= right && top <= btm)
	{
		for (int i = left; i <= right; i++)
			ret.push_back(matrix[top][i]);
		if(top<btm)
			for (int i = top + 1; i <=btm; i++)
				ret.push_back(matrix[i][right]);
		if (top < btm&& left < right)
			for (int i = right - 1; i >= left; i--)
				ret.push_back(matrix[btm][i]);
		if (top + 1 < btm && left < right)
			for (int i = btm - 1; i >= top + 1; i--)
				ret.push_back(matrix[i][left]);
		++left;
		--right;
		++top;
		--btm;	
	}
	return ret;
}

int main()
{
	int arr[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	vector<vector<int> > matrix;
	vector<int> v;
	for (int i = 0; i < 4; i++)
	{
		v.clear();
		for (int j = 0; j < 4; j++)
		{
			v.push_back(arr[i][j]);
		}
		matrix.push_back(v);
	}
	vector<int> ret;
	ret = printMatrix(matrix);
	for (int i = 0; i < ret.size(); i++)
	{
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}