#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void analyst(int x);
void input(int x);
void input (int x)
{
	int a[x];
	for (int i=0;i<x;i++)
	{
		cin>>a[i];
		if (a[i]<1 && a[i]>pow(10,4))
		{
		
		cout<<"ERROR!";
		}
	}
	for (int i=0;i<x;i++)
	{
		analyst (a[i]);
	}
}
void analyst(int x)
{
	float s;
	{	
		s=0;
		for (int i=0;i<x;i++)
		{
			s=sqrt(2+s);
		}
		cout<<fixed<<setprecision(5)<<s<<endl;
	}
}

int main()
{
	int t;
	cin>>t;
	
		input(t);

}
