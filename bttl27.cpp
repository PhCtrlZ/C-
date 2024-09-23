#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float sum,n;
	cin>>n;
	sum=0;
	if (n<5 && n>pow(10,9)) cout<<"ERROR";
	for (int i=1;i<=n;i++)
	{
		sum+=i*(i+1)/2;
		if (sum>=n)
		{
			cout<<i;
			break;
		}
	}
}
