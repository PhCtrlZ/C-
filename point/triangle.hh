#ifndef TRIANGLE_HH
#define TRIANGLE_HH
#include <iostream>
#include <cmath>
#include "ridge.hh"
using namespace std;

class Triangle {
private:
    Ridge a, b, c; 
public:
    Triangle();
    Triangle(Ridge aa, Ridge bb, Ridge cc);

    void nhap();
    void xuat();
    double chuVi();
    double dienTich();
};
#endif
