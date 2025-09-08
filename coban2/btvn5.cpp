#include <iostream>

using namespace std;
int tong(int *p1, int *p2){
    return *p1 + *p2;
}
int hieu(int *p1, int *p2){
    return *p1 - *p2;
}
int main(){
    int a,b;
    cin>>a>>b;
    int *p1 = &a;
    int *p2 = &b;
    cout<<"gia tri a: "<<a<<" dia chi cua a: "<<&a<<endl;
    cout<<"gia tri b: "<<b<<" dia chi cua b: "<<&b<<endl;
    cout<<"dia chi cua p1: "<<p1<<endl;
    cout<<"dia chi cua p2: "<<p2<<endl;
    cout<<"gia tri cua p1: "<<*p1<<endl;
    cout<<"gia tri cua p2: "<<*p2<<endl;
    cout<<tong(p1,p2)<<endl;
    cout<<hieu(p1,p2)<<endl;
}
