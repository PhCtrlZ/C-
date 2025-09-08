#include <iostream>
#include <cmath>

using namespace std;
// input
void input(int x)
{
    int A[x];
    for (int i=1 ;i<=x;i++)
    {
        cin>>A[i];
    }
}
//sort
void sort(int x)
{
    int A[x],z;
    for (int i=1;i<=x;i++)
    for (int j=1;j<=i;i++)
    {
        if (A[i]<A[j])
        {
            z=A[i];
            A[i]=A[j];
            A[j]=z;
        }

    }
}
//check prime number
bool check(int n)
{
    int x,dem;
    dem=0;
    for (int i=1;i<=n;i++)
        if (n%i==0)
        dem++;
        if (dem==2)
            return true;
        return false;
}
//output
void output(int x)
{
    int A[x];
    for (int i=1;i<=x;i++)
    {
        if(check(A[i])==true)
        {
            if (A[i]==A[i+1])
            {
                cout<<A[i]<<" ";
                i=i+1;
            }
            else cout<<A[i]<<" ";
        }
    }
}
int main()
{
    int n;
    cin>>n;
    input(n);
    sort(n);
    output(n);
}