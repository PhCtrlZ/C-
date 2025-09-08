#include <iostream>

using namespace std;
bool nhuan(int &nam){
    return (nam%400==0 || (nam%4==0 && nam%100!=0));
}
int main(){
    int ngay,thang,nam;
    cout<<"nhap ngay thang nam: ";
    cin>>ngay>>thang>>nam;
    int songay[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (nhuan(nam)) songay[1]=29;
    ngay++;
    if (ngay>songay[thang-1])
    {
        ngay=1;
        thang++;
        if(thang>12)
        {
            thang=1;
            nam++;
        }
    }
    cout<<"ngay ke tiep:"<<ngay<<"/"<<thang<<"/"<<nam<<endl;
    return 0;
}