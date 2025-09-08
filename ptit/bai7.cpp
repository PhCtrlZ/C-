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
int main(){
    int ngay, thang, nam;
    cout << "Nhap ngay thang nam: ";
    cin >> ngay >> thang >> nam;
    int batdau=4;
    int chenhlech=0;
    if (nam>=1970){
        for (int y=1970;y<nam;y++) 
            chenhlech+= nhuan(y) ?366 :365;
        chenhlech+=songay(ngay,thang,nam)-1;
        int thu =(batdau + chenhlech) % 7;//%7 la 1 tuần xoay vòng bắt đầu từ ngày 1 1 1970
        string athu[]={"chu nhat","thu hai","thu ba","thu tu","thu nam","thu sau","thu bay"};
        cout<<athu[thu]<<endl;
        
    }
    else {
        for (int y=nam;y<1970;y++)
                chenhlech+= nhuan(y) ?366 :365;
        chenhlech-=songay(ngay,thang,nam)-1;
        int thu =(batdau - chenhlech) % 7;//%7 la 1 tuần xoay vòng bắt đầu từ ngày 1 1 1970
        string athu[]={"chu nhat","thu hai","thu ba","thu tu","thu nam","thu sau","thu bay"};
        cout<<athu[thu]<<endl;
        }
    return 0;
}