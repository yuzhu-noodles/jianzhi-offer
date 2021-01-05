#include<iostream>
using namespace std;

int rectCover(int number)
{
    int a = 0;
    int b = 1;
    int n = 0;
    if (number == 1)
    {
        n = 1;
    }
    else
    {
        for (int i = 1; i <= number; i++)
        {
            n = a + b;
            a = b;
            b = n;
        }
    }
    return n;
}
int main()
{
    int a = 0;
    cin >> a;
    cout << rectCover(a) << endl;
    system("pause");
    return 0;
}
