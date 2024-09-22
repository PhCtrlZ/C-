#include <iostream>
#include <iomanip>

using namespace std;

void nhapmang(int x)
{
	int A[x],z,y;
	for (int i=1;i<=x;i++)
	{
		cout<<"a["<<A[i]<<"]=";
		cin >>A[i];
	}
	cout <<"mang vua nhap :"<<endl;
	for (int i=1;i<=x;i++)
	{
		cout<<A[i]<<" ";
	}
	//replace
	cout<<"nhap vao vi tri ma ban muon thay the:"<<endl;
	cin>>z;
	cout<<"nhap vao so ma ban muon thay the:"<<endl;
	cin>>y;
	for (int i=1;i<=x;i++)
	{
		if (A[i]==A[z]) A[i]=y;	
	}
	cout<<"so ban vua thay the la:"<<A[z]<<endl;
	
}
int main()
{
	int n;
	cout<<"nhap n:"<<endl;
	cin>>n;
	nhapmang(n);
}