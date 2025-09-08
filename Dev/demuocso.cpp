#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,x;
    cin>>a;
    x=fabs(a);
    if (fabs(a)>1000) cout<<"ERROR";
    else 
    {   
        int dem;
        dem=0;
        for (int i=1;i<=x;i++)
        {
            if (x%i==0) dem++;
        }
         cout<<dem;
    }
}
