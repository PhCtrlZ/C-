#ifndef RIDGE_HH
#define RIDGE_HH

#include "point.hh"

class Ridge {
private:
    Point A, B;   // 2 điểm
public:
    Ridge();                      // constructor mặc định
    Ridge(Point p1, Point p2);    // constructor tham số
    void nhap();                  // nhập 2 điểm
    void xuat();                  // xuất 2 điểm
    double doDai();         // tính độ dài đoạn thẳng
};

#endif
