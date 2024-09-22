#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main()
{
	int a,b,c,d,e,f;
	float x,y,z,g,k;
	cin>> a;
	cin>>b;
	cin>>c;
	cin>>d;
	cin>>e;
	cin>>f;
	x=a*e-d*b;
	y=c*e-f*b;
	z=a*f-d*c;
	if (x==0){
		if (y+z==0)
		cout<<"VOSONGHIEM";
		else
		cout<<"VONGHIEM";
	}
	else {
		g=y/x;
		k=z/x;
		cout<<fixed<<setprecision(2)<<g<<" ";
		cout<<fixed<<setprecision(2)<<k;
	}
	
}