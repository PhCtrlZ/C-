#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void nhapmang(int a)
{
	int A[a],dem,z;
	float tbc;
	for (int i=1;i<=a;i++)
	{
		cin >>A[i];
		if (A[i]>pow(10,6)) 
		{
			cout<<"ERROR";
			break;
		}
	}
	dem=0;
	z=0;
	for (int i=1;i<=a;i++)
	{
		if (A[i]%2!=0)	
		{
		dem+=A[i];
		z++;
	}
		
	}
	tbc=dem/z;
	cout<<fixed<<setprecision(4)<<tbc;
}
int main()
{
	int n;
	cin>>n;
	if (n<1 && n>pow(10,3)) cout<<"ERROR";
	else
	nhapmang(n);
}
