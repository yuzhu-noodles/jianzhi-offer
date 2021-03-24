#include<iostream>
using namespace std;


bool isNumeric(string str)
{
    bool sign = false, decimal = false, hasE = false;
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        if (str[i] == 'e' || str[i] == 'E')
        {
            if (hasE || i == size - 1) 
                return false;
            hasE = true;
        }
        else if (str[i] == '+' || str[i] == '-')
        {
            if (sign && str[i - 1] != 'e' && str[i - 1] != 'E') 
                return false;
            if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E') 
                return false;
            sign = true;
        }
        else if (str[i] == '.')
        {
            if (hasE || decimal)
                return false;
            decimal = true;
        }
        else if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}



int main()
{
	string str= "123.45e+6";
	cout << isNumeric(str) << endl;
	system("pause");
	return 0;
}