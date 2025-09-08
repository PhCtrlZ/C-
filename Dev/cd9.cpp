#include <iostream>

using namespace std;

int main()
{
    int n,dem,dem2;
    cin>>n;
    dem=0;
    if (n<0) cout <<"ERROR";
    else
    {
        for (int i=1;i<=n;i++)
        {
            if (i<=n && i>=(n-1)/2) dem++;

            
        }
        dem2=(n*n)-n;
        cout<<dem<<endl;
        cout<<dem2;    
    }
}