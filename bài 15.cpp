#include <iostream>
#include <iomanip>
using namespace std;

void add(int x, int y)
{
	cout<<"tong x va y la :"<<x+y<<endl;
}
int tong(int a,int b)
{
	int sum;
	sum=a+b;
	return sum;
}
int main ()
{
	cout<<"nhap 2 so nguyen:";
	int z;
	cin>>z;
	int d;
	cin>>d;
	add(z,d);
	tong(z,d);
	return 0;
}