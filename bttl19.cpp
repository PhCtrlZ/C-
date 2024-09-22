#include <iostream>
#include <iomanip>

using namespace std;

void nhapmang(int a,int b)
{
	int A[a];
	for (int i=1;i<=a;i++)
	{
		cin >>A[i];
	}

	int dem;
	dem=0;
	for (int i=1;i<=a;i++)
	{
	
		if (A[i]==b) 
		{
		dem++;
		}
	}
	cout<<dem;
}
int main()
{
	int n,x;
	cin>>n;
	cin>>x;
	nhapmang(n,x);
}
