#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void input(double x)
{
    double s=1.0;
    for (int i=2;i<=x;i++)
    {
        s=sqrt(i+s);
    }
    cout << fixed<<setprecision(5)<<s<<endl;
}
int main()
{
    int T;
    cin>>T;
    long A[T];
    for (int i=1;i<=T;i++)
    {
        cin>>A[i];
    }
    for (int i=1;i<=T;i++)
    {
        input(A[i]);
    }
    return 0;
}