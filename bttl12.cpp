#include <iostream>
#include <iomanip>

using namespace std;

void giaipt(float x,float y)
{
	float s1,s2;
	s1=(-y);
	s2=s1/x;
	cout<<"bat phuong trinh ax+b="<<s2<<endl;
}

int main()
{ 
	float a,b;
	cout<<" giai bat phuong trinh ax+b"<<endl;
	cout<<"nhap a:"<<endl;
	cin>>a;
	cout<<"nhap b:"<<endl;
	cin>>b;
	giaipt(a,b);
}