#include<iostream>
using namespace std;
#include<vector>
#include<map>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) 
    {
        // write code here
        vector<int> v;
        map<int,int> m;
        for (int i = 0; i < array.size(); i++)
        {
            m[array[i]]++;
        }
        for (int i = 0; i < array.size(); i++)
        {
            if (m[array[i]] == 1)
            {
                v.push_back(array[i]);
            }
        }
        return v;
    }
};
int main()
{
    vector<int>v1;
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(1);
    v1.push_back(6);
    v1.push_back(6);
    v1.push_back(5);
    Solution S;
    vector<int> v2 = S.FindNumsAppearOnce(v1);
    for (int i = 0; i < v2.size(); i++)
    {
        cout<<v2[i]<<" ";
    }
	system("pause");
	return 0;
}