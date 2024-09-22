#include <iostream>
#include <iomanip>

using namespace std;

void giaithua(int x)
{
	int s;
	if (x==0 || x==1)
	{
		cout <<x<<" k ton tai gia thua"<<endl;
	}
	else 
		for (int i=1;i<=x;i++)
    	{
			for (int j=2;j<=i+2;j++)
			{
				s=i*j;
			}
    	
		}
	cout<<"giai thua cua n bang: "<<s<<endl;
}
int main()
{
    int n;
    cout<<"nhap n:"<<endl;
    cin>>n;
    giaithua(n);

}