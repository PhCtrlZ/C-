#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int selection;
	do
	{
		cout <<"----------------Menu-----------------"<<endl;
		cout <<"1. Milk tea" << endl;
		cout <<"2.Tea"<<endl;
		cout <<"3.Icecream"<<endl;
		cout <<"4.Ice tea"<<endl;
		cout <<"5.Yomost"<<endl;
		cout<<"Choose:";
		cin>>selection;
		
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
		}
	} while (selection <1 || selection >5);
	cout<<"Selection your choose:"<<selection<<endl;
one:
	cout<<"Milk tea hien dang co gia la 20k"<<endl;
two:
	cout<<"Tea hien dang co gia la 5k"<<endl;
		
three:
	cout<<"Icecream hien dang co gia la 7k"<<endl;
four:
	cout<<"Ice tea hien dang co gia la 10k"<<endl;
five:
	cout<<"Yomost hien dang gia la 4k"<<endl;
if (selection=1)
	{
	goto one;
	}
else if (selection=2)
	{
	goto two;
	}
else if (selection=3)
	{
	goto three;	
	}
else if (selection=4)
	{
	goto four;	
	}		
else if (selection=5)
	{
	goto five;
	}			
	return 0;

}