#include <iostream>
#include <cmath>
#include "phanso.hh"
using namespace std;
phanso::phanso() {
    a = 0; 
    b = 1;
}
phanso::phanso(int aa,int bb){
    if (bb == 0){
        cout << "Mau so khong the = 0, tu dong gan = 1" << endl;
        a = aa;
        b = 1;
    } else {
        a = aa;
        b = bb;
    }
    rutgon();
}
void phanso::nhap(){
    cout << "Nhap tu: ";
    cin >> a;
    cout << "Nhap mau: ";
    cin >> b;
    if (b == 0) {
        cout << "Mau so khong the = 0, tu dong gan = 1" << endl;
        b = 1;
    }
    rutgon();
}
void phanso::xuat() const {
    if (b == 1) cout << a;
    else cout << a << "/" << b;
}
int phanso::UCLN(int x, int y){
    if (y == 0) return x;
    return UCLN(y, x % y);
}
void phanso::rutgon(){
    int g = UCLN(abs(a), abs(b));
    if (g != 0) {
        a /= g;
        b /= g;
    }
    if (b < 0) {
        a = -a;
        b = -b;
    }
}
phanso phanso::cong(const phanso &p){
    return phanso(a * p.b + p.a * b, b * p.b);
}
phanso phanso::tru(const phanso &p){
    return phanso(a * p.b - p.a * b, b * p.b);
}
phanso phanso::nhan(const phanso &p){
    return phanso(a * p.a, b * p.b);
}
phanso phanso::chia(const phanso &p){
    return phanso(a * p.b, b * p.a);
}
int main(){
    phanso p1, p2;
    cout << "Nhap phan so thu nhat:\n"; p1.nhap();
    cout << "Nhap phan so thu hai:\n"; p2.nhap();
    cout << "Phan so 1: "; p1.xuat(); cout << endl;
    cout << "Phan so 2: "; p2.xuat(); cout << endl;
    cout << "Cong: "; p1.cong(p2).xuat(); cout << endl;
    cout << "Tru: "; p1.tru(p2).xuat(); cout << endl;
    cout << "Nhan: "; p1.nhan(p2).xuat(); cout << endl;
    cout << "Chia: "; p1.chia(p2).xuat(); cout << endl;
    return 0;
}
