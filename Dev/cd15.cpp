#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b,c,x,y,z;
    cin>>a>>b>>c;
    x=sqrt(a*b/c)*4;
    y=sqrt(a*c/b)*4;
    z=sqrt(b*c/a)*4;
    cout<<x+y+z;
}