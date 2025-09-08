#include <iostream>
using namespace std;

class Diem{
    public:
    double x,y;
    Diem(double x=0,double y=0){
        this->x=x;
        this->y=y;
    }
    void nhap(){
        cout<<"Nhap toa do x,y"<<endl;
        cin>>x>>y;
    }
    void xuat(){
        cout<<"("<<x<<","<<y<<")";
    }
};
class TamGiac{
    private:
    Diem A,B,C;
    public:
    TamGiac(){}
    TamGiac(Diem a,Diem b,Diem c){
        A=a;B=b;C=c;
    }
    ~TamGiac(){}
    void nhap(){
        cout<<"nhap dinh a"<<endl;A.nhap();
        cout<<"nhap dinh b"<<endl;B.nhap();
        cout<<"nhap dinh c"<<endl;C.nhap();
    }
    void xuat(){
        cout<<"Cac dinh cua tam giac:"<<endl;
        A.xuat();cout<<" ";
        B.xuat();cout<<" ";
        C.xuat();cout<<endl;
    }
    void tinhTien(double dx,double dy){
        A.x+=dx;A.y+=dy;
        B.x+=dx;B.y+=dy;
        C.x+=dx;C.y+=dy;
    }
    Diem trongTam(){
        double gx=(A.x+B.x+C.x)/3.0;
        double gy=(A.y+B.y+C.y)/3.0;
        return Diem(gx,gy);
    }
};
int main() {
    TamGiac tg;
    tg.nhap();
    tg.xuat();

    double dx, dy;
    cout << "Nhap vector tinh tien dx dy: ";
    cin >> dx >> dy;
    tg.tinhTien(dx, dy);
    cout << "Sau khi tinh tien: ";
    tg.xuat();

    Diem G = tg.trongTam();
    cout << "Trong tam tam giac: ";
    G.xuat();
    cout << endl;

    return 0;
}
