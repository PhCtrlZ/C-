#include <iostream>

using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n],z,d;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	d=0;
	z=a[1];
	for (int i=2;i<=n;i++)
	{
		if (z<a[i])
		{
			z=a[i];
			d+=1;
		} 
		else if (z>a[i]){
			cout<<i;
		} 
	}
	cout<<d;
	return 0;
}