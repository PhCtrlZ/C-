#include <iostream>
using namespace std;
void rutgon(int &a,int &b){
    int tu=a,mau=b;
    while (b!=0){
        int t=b;
        b=a%b;
        a=t;
    }
    b=mau/a;
    a=tu/a;
}
void  cong(int &a,int &b,int &c,int &d){
    int tu=a*d+b*c; //quydong
    int mau=b*d;
    rutgon(tu,mau); 
    cout<<"tong hai phan so la: "<<tu<<"/"<<mau<<endl;
}
void tru(int &a,int &b,int &c,int &d){ 
    int tu=a*d-b*c; //quydong
    int mau=b*d;
    rutgon(tu,mau);
    cout<<"hieu hai phan so la: "<<tu<<"/"<<mau<<endl;
}
void chia(int &a,int &b,int &c,int &d){
    int tu=a*d;
    int mau=b*c;
    rutgon(tu,mau);
    cout<<"thuong hai phan so la: "<<tu<<"/"<<mau<<endl;
}
void nhan(int &a,int &b,int &c,int &d){
    int tu=a*c;
    int mau=b*d;
    rutgon(tu,mau);
    cout<<"tich hai phan so la: "<<tu<<"/"<<mau<<endl;
}
int main(){
    int a,b;
    cout<<"nhap vao phan so dau tien: "<<endl;
    cin >> a >> b;
    int c,d;
    cout<< "nhap vao phan so thu hai: " << endl;
    cin >> c >> d;
    if (b == 0 || d == 0) {
        cout << "Phan so khong hop le!" << endl;
        return 1;
    }
    else if (a<0 && b<0) {
        a = -a;
        b = -b;
    }
    else if (c<0 && d<0) {
        c = -c;
        d = -d;

    }
    else if (a>0 &&b>0 && c>0 && d>0){
        rutgon(a,b);
        rutgon(c,d);
        cout<<"phep cong hai phan so:"<<endl;
        cong(a,b,c,d);
        cout<<"phep tru hai phan so:"<<endl;
        tru(a,b,c,d);
        cout<<"phep nhan hai phan so:"<<endl;
        nhan(a,b,c,d);
        cout<<"phep chia hai phan so:"<<endl;
        chia(a,b,c,d);
    }

}