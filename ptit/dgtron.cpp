#include <iostream>
#include <cmath>
using namespace std;
const float pi=3.14;
struct duongtron{
    float x,y;
    float r;
};
float chuvi(duongtron d){
    return 2*pi*d.r;
}
float dientich(duongtron d){
    return pi*pow(2,d.r);
}
int main(){
    duongtron d;
    cin>>d.x>>d.y;//tâm x,y
    cin>>d.r;//bán kính
    cout<<"chu vi="<<chuvi(d)<<endl;
    cout<<"dien tich="<<dientich(d)<<endl;

}