#include<iostream>
using namespace std;
#include<stack>


//借助辅助栈s2
//如果s2的栈顶元素>value,则s2将value压栈,这样之前的最小值就会成为次小值
class Solution {
public:
    void push(int value) 
    {
        s1.push(value);
        if (s2.empty() || s2.top() > value)
        {
            s2.push(value);
        }
    }
    void pop()
    {
        if (s1.top() == s2.top())
        {
            s2.pop();
        }
        s1.pop();
    }
    int top() 
    {
        return s1.top();
    }
    int min() 
    {
        return s2.top();
    }
private:
    stack<int> s1;
    stack<int> s2;
};

int main()
{
    Solution S;
    S.push(5);
    S.push(3);
    S.push(4);
    cout << "最小元素：" << S.min() << endl;
    cout << "栈顶元素:" << S.top() << endl;
	system("pause");
	return 0;
}