#include <iostream>
#include <iostream>
using namespace std;

string hoten;
int toan;
int van;
float dtb;

void nhap();
void xuat();
void xuly();

void nhap(){
    cout<<"nhap ho ten";
    getline(cin,hoten);
    cout<<"nhap diem toan"<<endl;
    cin>>toan;
    cout<<"nhap diem van"<<endl;
    cin>>van;
}
void xuly(){
    dtb=(toan+van)/2;
    
}
void xuat(){
    cout<<"diem tb:"<<dtb<<endl;
}
int main(){
    nhap();
    xuly();
    xuat();
    return 0;
}
