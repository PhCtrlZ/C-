#include <iostream>
#include <iomanip>
using namespace std;
void bachuso(int x,int y)
{
	cout<<"mo phong nhan so co 3 chu so"<<endl;
	char dv,chuc,tram;
	dv=y%10;
	chuc=y%100/10;
	tram=y/100;
	cout<<x<<endl;
	cout<<"x"<<endl;
	cout<<y<<endl;
	cout<<"---------"<<endl;
	cout<<"   "<<x*dv<<endl;
	cout<<"  "<<x*chuc<<endl;
	cout<<" "<<x*tram<<endl;
	cout<<x*y<<endl;
}
void bonchuso(int x,int y)
{
	cout<<"mo phong nhan 4 chu so voi nhau"<<endl;
	char dv,chuc,tram,nghin;
	dv=y%10;
	chuc=y%100/10;
	tram=y/1000;
	nghin=y/1000;
	cout<<x<<endl;
	cout<<"x"<<endl;
	cout<<y<<endl;
	cout<<"---------"<<endl;
	cout<<"    "<<y*dv<<endl;
	cout<<"   "<<y*chuc<<endl;
	cout<<"  "<<y*tram<<endl;
	cout<<" "<<y*nghin<<endl;
	cout<<x*y<<endl;
}
int main()
{
	cout<<"Mo phong phep nhan tay"<<endl;
	int a;int b;
	cout<<"vui long nhap 2 so nguyen de thuc hien phep nhan:";
	cin >>a;
	cin >>b;
	if (a>1000 & b>1000)
		{
			bonchuso(a,b);
		}
	else if (a<1000 & b<1000)
	{
		bachuso(a,b);
	}
}