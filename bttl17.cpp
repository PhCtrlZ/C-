#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	int n,x;
	int a[n];
	cin>>n;
	int max = a[0];
	for (int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
	for (int i=1;i<=n+1;i++)
	{
		if (a[i]>max) 	max=a[i]; 
		x=i;
	}
	cout<<x;

}
