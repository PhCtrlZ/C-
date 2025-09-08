#include <iostream>

using namespace std;
//khai báo
void convert(long long n);
void input(int x);
void input(int x)
{
	int a[x];
	for (int i=1;i<=x;i++)
	{
		cin>>a[i];
	}
	for (int i=1 ;i<=x;i++)
	{
		convert(a[i]);
	}
}
void convert(long long n)
{
	int b=0;
	int bit[32];
	do {
		bit[b]=n%2;
		n/=2;
		b++;
	}while (n>0);
	for (int i=b-1;i>=0;i--)
	{
		cout<<bit[i];
	}	
	cout<<endl;
}
int main()
{
	long long a ;
	cin>>a;
	input(a);
	return 0;
}