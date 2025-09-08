#include <iostream>
#include <cmath>

using namespace std;
//Input and output code
void input(int x)
{
    int A[x];
    for (int i=1;i<=x;i++)
    {
        cin>>A[i];
    }
}
//find prime number
bool ktr(int x)
{
	int dem=0;
	for(int i=1; i<=x; i++)
		if (x % i == 0)
			dem++;
	if (dem==2)
		return true;
	return false;
}
//sort from a to z
void sort(int x)
{
    int A[x],z;
    for (int i=1;i<=x;i++)
    for (int j=1;j<=i;j++)
    {
    	if (A[i]<A[j])
		{
			z=A[i];
			A[i]=A[j];
			A[j]=z;	
		}
	}
}
//output
void xuat(int n)
{
    int A[n];
    for (int i=1;i<=n;i++)
    {
        if(ktr(A[i])==true)
        {
        	if (A[i]==A[i+1]) 
        	{
        		cout<<A[i]<<" ";
        		i=i+1;
			}
			else 
			{
			cout<<A[i]<<" ";
		    }
		}
    }
}




int main()
{
    int n;
    cin>>n;
    input(n);
    sort(n);
    xuat(n);
}