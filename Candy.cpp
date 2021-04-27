#include<iostream>
using namespace std;
#include<vector>
//老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
//你需要按照以下要求，帮助老师给这些孩子分发糖果：
//每个孩子至少分配到 1 个糖果。
//评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。

//贪心算法
int Candy(vector<int>& ratings)
{
    int size = ratings.size();
    vector<int> candynum(size, 1);
    for (int i = 1; i < size; i++) //正序遍历，如果右边大于左边，则右边糖果数量比左边+1
    {
        if (ratings[i] > ratings[i - 1]) candynum[i] = candynum[i - 1] + 1;
    }
    for (int i = size - 2; i >= 0; i--)//倒序遍历
    {
        if (ratings[i] > ratings[i + 1]) //如果左边大于右边，取左边糖果数量和右边糖果+1 的最大值
        {
            candynum[i] = max(candynum[i], candynum[i + 1] + 1);
        }
    }
    int ret = 0;
    for (int i = 0; i < size; i++)
    {
        ret += candynum[i];
    }
    return ret;
}

int main()
{
    int a[3] = { 1,2,2 };
    vector<int>v(a, a + 3);
    cout << "至少要准备的糖果数量：" << Candy(v) << endl;
	return 0;
}