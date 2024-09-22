#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
	cout << "Phctrlz" << endl << endl;
	cout << setw(5) << left <<"ID";
	cout << setw(30) << left <<"Name";
	cout << setw(20) << right <<"Address" << endl;
	cout<< setfill('.');
	cout<< setw(55)<<"."<<endl;
	cout<< setfill(' ');
	cout << setw(5)<<left <<1;
	cout<< setw(30)<<left<<"Nguyen Hoang Phuc";
	cout << setw(20)<<right<<"Sai Gon" <<endl;
	cout << setw(5)<<left <<2;
	cout<< setw(30)<<left<<"Nguyen Phuc Khanh";
	cout << setw(20)<<right<<"Sai Gon" <<endl;
	cout << setw(5)<<left <<3;
	cout<< setw(30)<<left<<"Nguyen Phuc Huy";
	cout << setw(20)<<right<<"Sai Gon" <<endl;
}
