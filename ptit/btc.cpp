#include <iostream>
using namespace std;

string hoten;
int toan;
int van;
float dtb;

int main(){
    cout<<"nhap ho ten:"<<endl;
    getline(cin,hoten);
    cout<<"nhap diem toan"<<endl;
    cin>>toan;
    cout<<"nhap diem van"<<endl;
    cin>>van;
    cout<<"ket qua"<<endl;
    cout<<hoten<<endl;
    cout<<toan<<endl;
    cout<<van<<endl;
    dtb=(toan+van)/2;
    cout<<"diem trung binh mon:"<<dtb;
}