#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f,sum;
    cin>>a>>b>>c>>d;
    sum=a+b+c+d;
    cout<<sum<<endl;
    e=sum%10;
    f=sum%100/10;
    cout<<f<<" "<<e;
}