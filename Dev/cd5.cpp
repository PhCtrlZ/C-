#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    float a,b,c,d;
    cin>>a;
    cin>>b;
    if (a>b) cout<<"ERROR";
    c=a*b;
    d=((a/2)*(a/2))*M_PI;
    cout<<fixed<<setprecision(2)<<c-d;
}