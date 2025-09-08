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
int main(){
    int a,b;
    cout<<"nhap vao tu va mau: "<<endl; 
    cin >> a >> b;
    if (b==0) {
        cout<<"error!";
    }  
    else if (b>0) {
        rutgon(a, b);
        cout << "Phan so rut gon la: " << a << "/" << b <<endl;
    }
    return 0;
}