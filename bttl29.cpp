#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void bdm(int x)
{
    int A[x],left,right,tinhtoan,z;
    for(int i= 1; i<=x;i++){
        cin>>A[i];
    }
    /** biến đổi mảng**/
    for (int i=1 ;i<=x;i++)
    {
        if (A[i]==1) continue; 
        else if (A[i]%2==1)
            {
                left=A[i-1];
                if (i+1>x)
                {
                    right=0;
                }
                else if (i<x-1)
                {
                    right=A[i+1];
                }
                else  right=0;
                tinhtoan=fabs(right-left);
                z=A[i]+tinhtoan;
                A[i]=z;
            }
        
    }
    for (int i=1;i<=x;i++)
    {
        cout<<A[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    bdm(n);
    return 0;
}