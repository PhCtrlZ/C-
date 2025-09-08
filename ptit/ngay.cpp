#include <iostream>

using namespace std;

struct ngay{
    int ngay,thang,nam;
};
bool namnhuan(int nam){
    return(nam%400==0)||(nam&4==0&&nam%100!=0); 
}
int songaytrongthang(int thang,int nam){
    if(thang==2) return namnhuan(nam)?29:28;
    if (thang==4||thang==6||thang==11||thang==9) return 30;
    return 31;

}

ngay ngayketiep(ngay d){
    d.ngay++;
    if(d.ngay>songaytrongthang(d.thang,d.nam)){
    d.ngay=1;d.thang++;
    if (d.thang>12){
        d.thang=1;d.nam++;
    }
    }
    return d;
}
ngay ngayhomtruoc(ngay d){
    d.ngay--;
    if(d.ngay==0){
        d.thang--;
        if(d.thang==0){
            d.thang=12;d.nam--;
        }
        d.ngay=songaytrongthang(d.thang,d.nam);
    }
    return d;
}
int main(){
    ngay d;
    cin>>d.ngay>>d.thang>>d.nam;
    ngay t=ngayketiep(d);
    ngay h=ngayhomtruoc(d);
    cout<<t.ngay<<"/"<<t.thang<<"/"<<t.nam<<endl;
    cout<<h.ngay<<"/"<<h.thang<<"/"<<h.nam<<endl;
}