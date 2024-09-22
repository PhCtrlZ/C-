#include <iostream>
#include <iomanip>

using namespace std;

void nhapmang(int x)
{
	int A[x];
	for (int i=0;i<=x;i++)
	{
		cout<<"a["<<A[i]<<"]=";
		cin >>A[i];
	}
	cout <<"mang vua nhap :"<<endl;
	for (int i=0;i<=x;i++)
	{
		cout<<A[i]<<" ";
	}
		
	}


int main()
{
	int n;
	cout<<"nhap n:"<<endl;
	cin>>n;
	nhapmang(n);
}