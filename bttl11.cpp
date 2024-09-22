#include <iostream>
#include <iomanip>

using namespace std;

void socp(int x)
{
	int s;
	for (int i=2;i<=x/2;i++)
	{	
		s=i*i;
		if (x==s) 
		{
			cout<<x<<" la so chinh phuong"<<endl;
		}
	}
}
int main()
{
	int n;
	cout<<"nhap n:";
	cin>>n;
	socp(n);	
}