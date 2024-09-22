#include <iostream>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void rutGonPhanSo(int& tu, int& mau) {
    int uocChung = gcd(tu, mau);
    tu /= uocChung;
    mau /= uocChung;
}
int main() {
	int a,b;
	cin>>a;
	cin>>b;
	if (a==0 &&b==0) cout<<"INVALID";
	else if (b==0) cout<<"INVALID";
    else {
    	
	rutGonPhanSo(a, b);
    cout << a << " " << b <<endl;
}
	
    return 0;
}