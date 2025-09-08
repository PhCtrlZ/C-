#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if (n>pow(10,4)&&n<0) cout<<"ERROR";
    else if (n==0) cout<<"INF";
    else 
	{
		for (int i=n;i>=1;i--)
		{
			if (n%i==0)
			{
				cout<<i<<" ";
			}
		}
	}
	return 0;
}