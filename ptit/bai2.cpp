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
int sosanh(int &a,int &b,int &c,int &d){
    if (a*d>b*c) return 1;
    if (a*d<b*c) return -1;
    return 0;
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
    else {
        rutgon(a,b);
        rutgon(c,d);
        sosanh(a, b, c, d);
        if (sosanh(a,b,c,d)==1){
            cout<<"phan so thu nhat lon hon phan so thu 2"<<endl;
        }
        else if(sosanh(a,b,c,d)==-1){
            cout<<"phan so thu hai lon hon phan so thu nhat"<<endl;
        }
        else { cout<<"2 phan so bang nhau"<<endl; }
    }

}