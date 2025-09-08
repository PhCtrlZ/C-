#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float a,b,c,r,s,ht,z;
    cin>>a>>b>>c;
    z=sqrt(c*c-((b-a)*(b-a))/4);
    s=(a+b)*z/2;
    r=z/4;
    ht=r*r*3.14; 
    cout<<fixed<<setprecision(2)<<s-ht;
}