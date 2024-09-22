#include <iostream>
#include <iomanip>

using namespace std;
void hinhtamgiac(int x)
{	
	for (int i=1;i<=x ; i++ )
	{
		for (int j=i;j<x;j++)
		{
			cout<<" ";
	}
	for (int j=1; j<=2*i-1;j++)
		{
		cout<<"*";
	}
	
	cout << endl;
}
}
int main()
{

	int n;
	cout << "nhap vao chieu cao cua tam giac :";
	cin>>n;
	hinhtamgiac(n);
}