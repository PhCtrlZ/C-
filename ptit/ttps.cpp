#include <iostream>

using namespace std;

struct phanso{
    int tu,mau;
};
int ucln(int a,int b){
    while (b!=0) {
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
}
phanso rutgon(phanso p){
    int g=ucln(abs(p.tu),abs(p.mau));
    p.tu/=g;p.mau/=g;
    if (p.mau<0){
        p.mau*=-1;p.tu*=-1;
    }
    return p;
}
phanso cong(phanso a,phanso b){
    phanso kq={
        a.tu*b.mau+b.tu*a.mau,a.mau*b.mau
    };
    return rutgon(kq);
}
phanso tru(phanso a,phanso b){
    phanso kq={
        a.tu*b.mau-b.tu*a.mau,a.mau*b.mau
    };
    return rutgon(kq);
}
phanso nhan(phanso a,phanso b){
    phanso kq={
        a.tu*b.tu,a.mau*b.mau
    };
    return rutgon(kq);
}
phanso chia(phanso a,phanso b){
    phanso kq={
        
        a.tu*b.mau,a.mau*b.tu
    };
    return rutgon(kq);
};
int main(){
    phanso a,b;
    cin>>a.tu>>a.mau;
    cin>>b.tu>>b.mau;
    phanso c=cong(a,b),d=tru(a,b),e=nhan(a,b),f=chia(a,b);
    cout<<"phep cong "<<c.tu<<"/"<<c.mau<<endl;
    cout<<"phep tru "<<d.tu<<"/"<<d.mau<<endl;
    cout<<"phep nhan "<<e.tu<<"/"<<e.mau<<endl;
    cout<<"phep chia "<<f.tu<<"/"<<f.mau<<endl;
    return 0;
}