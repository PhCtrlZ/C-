#include <iostream>
#include "point.hh"
using namespace std;

point ::point()
{
    x=0;y=0;
}
point :: point(int aa,int bb){
    this->x=aa;
    this->y=bb;
}
void point::nhap()
{
    cout<<"Nhap toa do diem"<<endl;
    cin>>this->x>>this->y;
}
void point::xuat()
{
    cout<<"Gia tri cua toa do diem la:"<<this->x<<","<<this->y<<endl;
}
int main(){
    point p;
    p.xuat();
    point p1(2,5);
    p1.xuat();
    return 0;
}