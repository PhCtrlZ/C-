#include <iostream>
#include <cmath>
using namespace std;
struct diem{
    int x,y;
};
float khoangcach(diem a,diem b){
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)); //nên dùng pow
}
int main(){
    diem a,b;
    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    cout<<"khoang cac ab="<<khoangcach(a,b)<<endl;
    return 0;
}