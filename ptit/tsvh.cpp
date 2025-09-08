#include <iostream>
#include <string>

using namespace std;
void nhap(string &ht,int&t,int &v);//tham chiếu
void xuly(int t,int v,float &tb);
void xuat(string ht,int t,int v,float tb);//tham trị
int main(){
    string hoten;
    int toan,van;
    float dtb;
    nhap(hoten,toan,van);
    xuly(toan,van,dtb);
    xuat(hoten,toan,van,dtb);
    return 0;
}
void nhap(string &ht,int&t,int &v){
    cout<<"nhap ho ten";
    getline(cin,ht);
    cout<<"nhap diem toan"<<endl;
    cin>>t;
    cout<<"nhap diem van"<<endl;
    cin>>v;
}
void xuly(int t,int v,float &tb){
    tb=(t+v)/2;
    
}
void xuat(string ht,int t,int v,float tb){
    cout<<ht<<endl;
    cout<<t<<endl;
    cout<<v<<endl;
    cout<<"diem tb:"<<tb<<endl;
}