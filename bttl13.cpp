#include <iostream>
using namespace std;

int UCLN(int a, int b)
{
    while ( a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    return a; 
}

int BCNN(int a, int b)
{
    int result = UCLN(a, b);
    return a * b / result;
}

int main()
{
    int a, b;
    cout << "nhap a: ";
    cin >> a;

    cout << "nhap b:";
    cin >> b;

    int result = UCLN(a, b);
    cout << "UCLN : "<<result<<endl;
    result = BCNN(a, b);
    cout << "BCNN : " << result << endl;
}
