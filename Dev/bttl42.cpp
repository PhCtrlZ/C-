#include <iostream>
using namespace std;
void input(int x)
{
	int a[x],z;
	for (int i=1;i<=x;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=x;i++)
	for (int j=1;j<=x;j++)
	{
		if (a[j]<a[j+1])
		{
			z=a[j];
			a[j]=a[j+1];
			a[j+1]=z;
		}
	}
	for (int i=1;i<=x;i++){
		cout<<a[i]<<" ";
	}

}
int main()
{
	int n;
	cin>>n;
	input(n);
}