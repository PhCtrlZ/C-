#include <iostream>
using namespace std;

int main()
{
	bool b1(true);
	bool b2(false);
	cout << std::boolalpha;
	// neu khi dat gia tri voi bool >=1 thi ket qua tra ra luon luon la true 
	cout << true << endl;
	cout << false << endl;
	cout << std::noboolalpha;
	cout << true << endl;
	cout << false << endl;	
}