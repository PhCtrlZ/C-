#include <iostream>
using namespace std;

int main()
{	
	int x;
	int y;
	cout<<"nhap vo 1 so nguyen:"<<endl;
	cin>>x;
	cin>>y;
	// tam giac theo hinh kim tu thap
	for (int i=1;i<=x;i++)
	{
		for (int j=i;j<x;j++)
		{
			cout<<" ";
		}
		for (int j=1;j<=(2*i-1);j++ )
		{
			cout <<"*";
		}
		cout<<endl;
	}
	//tam giac nguyen thuy
	cout<<"tam giac binh thuong"<<endl;
	for (int z=0;z<y ; z++ )
	{
		for (int u=0;u<z+1;u++)
		{
			cout<<"*";
	}
	
	cout << endl;
	}
	return 0;
}          