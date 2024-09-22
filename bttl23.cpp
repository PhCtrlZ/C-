#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void nhapmang(int a)
{
	int A[a];
	for (int i=1;i<=a;i++)
	{
		cin >>A[i];
	}
	for (int i=1;i<=a;i++)
	
		if (A[i]<0) 
		cout<<A[i]<<" ";
		else if (A[i]>0) 
		cout<<"NOT FOUND"<<endl;
	
}
int main()
{
	int n;
	cin>>n;

	nhapmang(n);
}
