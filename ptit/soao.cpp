#include <iostream>

using namespace std;

struct sophuc{
    float thuc,ao;
};
sophuc cong(sophuc a,sophuc b){
    return {
        a.thuc+b.thuc,a.ao+b.ao
    };
}
sophuc tru(sophuc a,sophuc b){
    return{
        a.thuc-b.thuc,a.ao-b.ao
    };
}
sophuc nhan(sophuc a,sophuc b){
    return{
        a.thuc*b.thuc-a.ao*b.ao,a.thuc*b.ao+a.ao*b.thuc
    };
}
sophuc chia(sophuc a,sophuc b){
        float m=b.thuc*b.thuc+b.ao*b.ao;
        return {
            (a.thuc*b.thuc+a.ao*b.ao)/m,(a.ao*b.thuc-a.thuc*b.ao)/m
        };
}
int main(){
    sophuc a,b;
    cin>>a.thuc>>a.ao;
    cin>>b.thuc>>b.ao;
    sophuc c=cong(a,b),d=tru(a,b),e=nhan(a,b),f=chia(a,b);
    cout<<"a+b="<<c.thuc<<"+"<<c.ao<<"i"<<endl;
    cout<<"a-b="<<d.thuc<<"+"<<d.ao<<"i"<<endl;
    cout<<"a*b="<<e.thuc<<"+"<<e.ao<<"i"<<endl;
    cout<<"a/b="<<f.thuc<<"+"<<f.ao<<"i"<<endl;
    return 0;
}