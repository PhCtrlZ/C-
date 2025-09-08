#include <iostream>
#include <cmath>
using namespace std;

struct diem{
    float x,y;
};

float kc(diem a,diem b){
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
float chuvi(diem a,diem b,diem c){
    return kc(a,b)+kc(b,c)+kc(c,a);
}
float dientich(diem a,diem b,diem c){
    float d=kc(b,c),e=kc(a,c),f=kc(a,b);
    float p=(d+e+f)/2;
    return sqrt(p*(p-d)*(p-e)*(p-f));
}
diem trongtam(diem a,diem b,diem c){
    return {

        (a.x+b.x+c.x)/3,(a.y+b.y+c.y)/3
    };
}
int main(){
    diem a,b,c;
    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    cin>>c.x>>c.y;
    cout<<"cv "<<chuvi(a,b,c)<<endl;
    cout<<"dt "<<dientich(a,b,c)<<endl;
    diem g=trongtam(a,b,c);
    cout<<"trong tam "<<g.x<<","<<g.y<<endl;
    return 0;
}