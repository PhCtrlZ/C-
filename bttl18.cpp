#include <iostream>
#include <iomanip>

using namespace std;

bool nhapmang(int a,int b)
{
	int A[a];
	for (int i=1;i<=a;i++)
	{
		cin >>A[i];
	}

	int z;
	for (int i=1;i<=a;i++)
	{
	
		if (A[i]==b) 
		{
		return true;
		}
	}
	return false;
}
int main()
{
	int n,x;
	cin>>n;
	cin>>x;
	if (nhapmang(n,x)==true) cout<<"YES";
	else cout<<"NO";
}
