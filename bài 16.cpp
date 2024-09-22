#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
tryAgain:
	int n;
	cout<<"nhap so duong:";
	cin >>n;
	
	if (n<0)
	{
		goto tryAgain;
	}
	cout <<n << " la so nguyen duong"<<endl;
}