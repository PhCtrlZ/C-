#include <iostream>
#include <iomanip>
using namespace std;
void tinhtong(double x,double y)
{
	cout <<"tong cua 2 so x va y la:" << x+y << endl;
	
}
int main()
{
	cout<<"nhap vao 2 gia tri x va y cach nhau 1 dau cach:";
	double z;
	double d;
	cin>>z;
	cin>>d;
	tinhtong(z,d);
}