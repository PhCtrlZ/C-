#include <iostream>
using namespace std;

int main()
{
    int a,b,c,t,n,m;
    int x,y,z;
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>t;
    cin>>n;
    cin>>m;
    if (t>0)
    {
        x=(t*a);
    }
    if (n>0)
    {
        y=(n*b);
    }
    if (m>0)
    {
        z=(m*c);
    }
    cout<<x+y+z;
}