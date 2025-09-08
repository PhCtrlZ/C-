#include <iostream>

using namespace std;

bool nhuan(int nam) {
    return  (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0);
}
int songay(int &ngay,int &thang, int &nam) {
    int songay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (nhuan(nam)) songay[1] = 29;
    int tong= 0;
    for (int i=0;i<thang-1;i++){
        tong += songay[i];
    }
    return tong + ngay;
}

int chenhlech(int ngay, int thang, int nam) {
    int chenh = 0;
    if (nam>=2025){
        for (int i=2025;i<nam;i++) chenh+= (nhuan(i) ? 366 : 365);
        chenh += songay(ngay, thang, nam)-1;
    }else {
        for (int i=nam;i<2025;i++){
            chenh+= (nhuan(i) ? 366 : 365);
        chenh-= songay(ngay, thang, nam)-1;
        chenh= -chenh;
        }
    }
    return chenh;
}
int main(){
    int nam;
    cout << "Nhap nam: ";
    cin >>nam;
    int batdau=3;
    int dem=0;
    for (int thang=1;thang<=12;thang++){
        int chenh =chenhlech(13,thang,nam);
        int thu=(batdau + chenh) % 7; // %7 la 1 tuần xoay vòng bắt đầu từ ngày 1 1 2025
        if (thu==5) dem++; // vì theo quy ước 5 là thứ 6 
    }
    cout <<"thu 6 ngay 13 trong nam "<<nam<<" la:"<<dem<<endl;
    return 0;
}