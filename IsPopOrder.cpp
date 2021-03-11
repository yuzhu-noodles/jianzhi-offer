#include<iostream>
using namespace std;
#include<stack>
#include<vector>

//bool IsPopOrder(vector<int> pushV, vector<int> popV)
//{
//	stack<int> s;  //¸¨ÖúÕ»
//	for (int i = 0, j = 0; i < pushV.size();)
//	{
//		if (pushV[i] != popV[j])
//		{
//			s.push(pushV[i]);
//			i++;
//		}
//		else
//		{
//            i++;
//            j++;
//            while (!s.empty() && s.top() == popV[j])
//            {
//                s.pop();
//                j++;
//            }
//		}
//	}
//	return s.empty();
//}

bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
	stack<int> s;
	int j = 0;
	for (int i = 0; i < pushV.size(); i++)
	{
		s.push(pushV[i]);
		while (!s.empty() && s.top() == popV[j])
		{
			s.pop();
			j++;
		}
	}
	return s.empty();
}

void test()
{
	vector<int> pushV;
	vector<int> popV;
	pushV.push_back(1);
	pushV.push_back(2);
	pushV.push_back(3);
	pushV.push_back(4);
	pushV.push_back(5);
	popV.push_back(5);
	popV.push_back(4);
	popV.push_back(3);
	popV.push_back(2);
	popV.push_back(1);
	cout << IsPopOrder(pushV, popV);
}

int main()
{
	test();
	system("pause");
	return 0;
}