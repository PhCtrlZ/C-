#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
void tinhtoan(float x,float y)
{
    cout<<fixed<<setprecision(3)<<x+y<<endl;
    cout<<fixed<<setprecision(3)<<x-y<<endl;
    cout<<fixed<<setprecision(3)<<x*y<<endl;
    cout<<fixed<<setprecision(3)<<x/y<<endl;
}
int main()
{
    float a,b;
    cin>>a;
    cin>>b;
    tinhtoan(a,b);
}