#include <iostream>
using namespace std;

int main ()
{
	bool b1(true);
	bool b2(false);
	// if thieu
	if (b1 == true)
		cout <<"b1 is true" << endl;
	else 
		cout << "b1 is false" << endl;
	// if du ( co else neu cau lenh sai)
	if (b2 == false)
		cout <<"b2 is false" << endl;
	else 
		cout <<"b2 is true" << endl;
	
	return 0;
}