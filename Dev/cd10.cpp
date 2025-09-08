#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()

{
    float a;
    float s,r,ht;
    cin>>a;
    s=(pow(a,2)*(sqrt(3))/4);
    r=a*(sqrt(3)/6);
    ht=pow(r,2)*3.14;
    cout<<fixed<<setprecision(2)<<s-ht;

}