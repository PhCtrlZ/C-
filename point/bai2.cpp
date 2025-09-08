#include <iostream>
#include "point.hh"
#include "ridge.hh"
#include "triangle.hh"
using namespace std;
Point::Point() { x = 0; y = 0; }
Point::Point(int xx, int yy) { x = xx; y = yy; }
void Point::nhap() { cout << "Nhap x,y: "; cin >> x >> y; }
void Point::xuat() { cout << "(" << x << "," << y << ")"; }
int Point::getX() const { return x; }
int Point::getY() const { return y; }
Ridge::Ridge(): A(Point()), B(Point()) {}
Ridge::Ridge(Point p1, Point p2): A(p1), B(p2) {}
void Ridge::nhap() {
    cout << "Nhap diem A:\n"; A.nhap();
    cout << "Nhap diem B:\n"; B.nhap();
}
void Ridge::xuat() {
    cout << "Doan thang tu "; A.xuat();
    cout << " den "; B.xuat();
    cout << endl;
}
double Ridge::doDai() {
    double dx = A.getX() - B.getX();
    double dy = A.getY() - B.getY();
    return sqrt(dx*dx + dy*dy);
}
Triangle::Triangle(): a(Ridge()), b(Ridge()), c(Ridge()) {}
Triangle::Triangle(Ridge aa, Ridge bb, Ridge cc): a(aa), b(bb), c(cc) {}
void Triangle::nhap() {
    cout << "Nhap canh a:\n"; a.nhap();
    cout << "Nhap canh b:\n"; b.nhap();
    cout << "Nhap canh c:\n"; c.nhap();
}
void Triangle::xuat() {
    cout << "Tam giac gom: \n";
    a.xuat(); b.xuat(); c.xuat();
}
double Triangle::chuVi() {
    return a.doDai() + b.doDai() + c.doDai();
}
double Triangle::dienTich() {
    double da = a.doDai();
    double db = b.doDai();
    double dc = c.doDai();
    double p = (da + db + dc) / 2.0;
    return sqrt(p * (p - da) * (p - db) * (p - dc));
}
int main() {
    Triangle t;
    t.nhap();
    t.xuat();
    cout << "Chu vi tam giac: " << t.chuVi() << endl;
    cout << "Dien tich tam giac: " << t.dienTich() << endl;
    return 0;
}
