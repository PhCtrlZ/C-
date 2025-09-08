#include <iostream>
using namespace std;

bool nhuan(int nam){
    return (nam%400==0 || (nam%4==0 && nam%100!=0));
}

int main(){
    int ngay,thang,nam;
    cout<<"nhap ngay thang nam: ";
    cin>>ngay>>thang>>nam;

    int songay[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (nhuan(nam)) songay[1]=29;

    if (ngay > 1){
        ngay--;
    } else {
        thang--;
        if(thang < 1){
            thang = 12;
            nam--;
            if(nhuan(nam)) songay[1]=29;
            else songay[1]=28;
        }
        ngay = songay[thang-1]; // Gán ngày cuối cùng của tháng trước
    }

    cout<<"ngay truoc do: "<<ngay<<"/"<<thang<<"/"<<nam<<endl;
    return 0;
}
