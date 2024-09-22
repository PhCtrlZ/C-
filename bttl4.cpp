#include <iostream>
#include <iomanip>
using namespace std;

void chuyendoi(int x)
{
	int dv,chuc,tram,nghin;
	dv=x%10;
	chuc=x/10;
	tram=x/100;
	nghin=x%100;
	switch (dv)
	{
		case 1:
			cout << "I";
			break;
		case 2:
			cout << "II";
			break;
		case 3:
			cout << "III";
			break;
		case 4:
			cout << "IV";
			break;
		case 5:
			cout << "V";
			break;
		case 6:
			cout << "VI";
			break;
		case 7:
			cout << "VII";
			break;
		case 8:
			cout << "VIII";
			break;
		case 9:
			cout << "IX";
			break;
	}
	switch (tram)
	{
		case 1:
			cout << "C";
			break;
		case 2:
			cout << "CC";
			break;
		case 3:
			cout << "CCC";
			break;
		case 4:
			cout << "CD";
			break;
		case 5:
			cout << "D";
			break;
		case 6:
			cout << "DC";
			break;
		case 7:
			cout << "DCC";
			break;
		case 8:
			cout << "DCCC";
			break;
		case 9:
			cout << "CM";
			break;
	}
	switch (chuc)
	{
		case 1:
			cout << "X";
			break;
		case 2:
			cout << "XX";
			break;
		case 3:
			cout << "XXX";
			break;
		case 4:
			cout << "XL";
			break;
		case 5:
			cout << "L";
			break;
		case 6:
			cout << "LX";
			break;
		case 7:
			cout << "LXX";
			break;
		case 8:
			cout << "LXXX";
			break;
		case 9:	
		cout << "XC";
			break;	
	}
	/**
	if (x==1)
	{
		cout<<"So la ma la:I"<<endl;
	}
	else if (x==2)
	{
		cout<<"So la ma la:II"<<endl;
	}
	else if (x==3)
	{
		cout<<"So la ma la:III"<<endl;
	}
	else if (x==4)
	{
		cout<<"So la ma la:IV"<<endl;
	}
	else if (x==5)
	{
		cout<<"So la ma la:V"<<endl;
	}
	else if (x==6)
	{
		cout<<"So la ma la:VI"<<endl;
	}
	else if (x==7)
	{
		cout<<"So la ma la:VII"<<endl;
	}
	else if (x==8)
	{
		cout<<"So la ma la:VIII"<<endl;
	}
	else if (x==9)
	{
		cout<<"So la ma la:IX"<<endl;
	}
	else if (x==10)
	{
		cout<<"So la ma la:X"<<endl;
	}
	**/
	
}

int main()
{
	cout<<"nhap vao 1 so nguyen nho hon 10:"<<endl;
	int a;
	cin>>a;
	chuyendoi(a);
	return 0;
}