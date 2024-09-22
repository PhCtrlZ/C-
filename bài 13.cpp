#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// toan tu quan he hay noi cach khac la cac phep so sanh
	// neu ket qua tra ve la 0 la false 1 la true
	cout<<"enter a number=";
	int x;
	cin >>x;
	cout <<"enter a number 2=";
	int y;
	cin >>y;
	if( x==y )
		cout<<"x bang y"<<"\n";
	if (x>y)
		cout<<"x lon hon y"<<"\n";
	if (x<y)
		cout<<"x be hon y"<<"\n";
	if (x!=y)
		cout<<"x khac y"<<"\n";
	if (x>=y)
		cout<<"x lon hon hoac bang y"<<"\n";
	if (x<=y)
		cout<<"x be hon hoac bang y"<<"\n";
	// mot cach nhin khac ve laptrinh trong toan hoc
	double d1(1.0);
	double d2(0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1+0.1);
	if (d2==d1)
		cout << "d2=d1"<< "\n";
	else if (d1>d2)
		cout <<"d1>d2"<<"\n";
	else if (d1<d2)
		cout <<"d1<d2"<<"\n";
		
	cout << std::setprecision(20);
	cout <<"d1="<<d1<<endl;
	cout <<"d2="<<d2<<endl;
	// cac toan tu logic
	// logic not !
	// logic and && va
	// logic or  ||
	
}