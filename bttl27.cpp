#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,sum;
	cin>>n;
	sum=0;
	if (n<5 && n>pow(10,9)) cout<<"ERROR";
	for (int i=1;i<=n;i++)
	{
		sum+=i;
		if (sum==n)
		{
			cout<<i;
		} 
	}
}