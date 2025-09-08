#include <iostream>
#include <cmath>
#include "point.hh"
#include "ridge.hh"
using namespace std;
Point::Point() {
    x = 0;
    y = 0;
}
Point::Point(int xx, int yy) {
    x = xx;
    y = yy;
}
void Point::nhap() {
    cout << "Nhap x, y: ";
    cin >> x >> y;
}
void Point::xuat() {
    cout << "(" << x << "," << y << ")";
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}
Ridge::Ridge() : A(Point()), B(Point()) {}
Ridge::Ridge(Point p1, Point p2) : A(p1), B(p2) {}
void Ridge::nhap() {
    cout << "Nhap diem A:" << endl;
    A.nhap();
    cout << "Nhap diem B:" << endl;
    B.nhap();
}
void Ridge::xuat() {
    cout << "Doan thang tu ";
    A.xuat();
    cout << " den ";
    B.xuat();
    cout << endl;
}
double Ridge::doDai() {
    int dx = A.getX() - B.getX();
    int dy = A.getY() - B.getY();
    return sqrt(dx * dx + dy * dy);
}
int main() {
    Ridge r;
    r.nhap();
    r.xuat();
    cout << "Do dai doan thang: " << r.doDai() << endl;
    return 0;
}
