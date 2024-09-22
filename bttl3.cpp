#include <iostream>
#include <iomanip>
using namespace std;
void tiente(int t)
{
	int t100, t20, t5;
	t100=t/100;
	t -=100*t100;
	t20=t/20;
	t-=20*t20;
	t5=t/5;
	t-=5*t5;
	cout<<"So to tien menh gia 100 la:"<<t100<<endl;
	cout<<"So to tien menh gia 20 la:"<<t20<<endl;
	cout<<"So to tien menh gia 5 la:"<<t5<<endl;
}
int main()
{
	cout<<"cac menh gia tien dang co la 100 20 5 va 1"<<endl;
	cout<<"vui long nhap so tien ma ban muon rut va phai la 1 so nguyen"<<endl;
	int a;
	cin>>a;
	tiente(a);
}