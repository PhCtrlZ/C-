#include <iostream>
using namespace std;
struct pso {
    int tu;
    int mau;
};
int ucln(int a,int b){
    while (b!=0){
        int t=b;
        b=a%b;
        a=t;
    }
    return a; 
}
int main(){
    pso ps;
    cin>>ps.tu;
    cin>>ps.mau;
    int g=ucln(ps.tu,ps.mau);
    ps.tu/=g; 
    ps.mau/=g;
    cout<<"pso sau rut gon"<<ps.tu<<"/"<<ps.mau<<endl;
}