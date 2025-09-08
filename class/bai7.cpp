#include <iostream>
using namespace std;

class CongTuDong{
    private:
    bool trangThai;
    string matKhau;
    int soLuotRaVao;
    public:
    string viTriCong;
    //constructor ko tham so
    CongTuDong(){
        trangThai = false;
        matKhau = "Chua xac dinh";
        soLuotRaVao = 0;
        viTriCong = "Chua xac dinh";
    }
    //constructor co tham so
    CongTuDong(string viTri, string mk) {
        trangThai = false;
        matKhau = mk;
        soLuotRaVao = 0;
        viTriCong = viTri;
    }
    //getter
    int getSoLuotRaVao(){
        return soLuotRaVao;
    }
    bool getTrangThai(){
        return trangThai;
    }
    string getMatKhau(){
        return matKhau;
    }
    //setter
    void setMatKhau(string mk){
        matKhau = mk;
    }
    void setViTriCong(string viTri){
        viTriCong = viTri;
    }
    void setTrangThai(bool tt){
        trangThai = tt;
    }
    void moCong(string mk){
        if(mk==matKhau){
            trangThai=true;
            soLuotRaVao++;
            cout<<"Cong tu dong da mo!"<<endl;
        }else {
            cout<<"Mat khau khong dung! Khong the mo cong."<<endl;
        }
    }
    void dongCong(string mk){
        if(mk==matKhau){
            trangThai=false;
            cout<<"Cong tu dong da dong!"<<endl;
        }else {
            cout<<"Mat khau khong dung! Khong the dong cong."<<endl;
        }
    }
    void doiMatKhau(string mkCu, string mkMoi){
        if(mkCu==matKhau){
            matKhau=mkMoi;
            cout<<"Doi mat khau thanh cong!"<<endl;
        }else {
            cout<<"Mat khau cu khong dung! Khong the doi mat khau."<<endl;
        }
    }
    void xemThongKe(string mk){
        if(mk==matKhau){
            cout<<"Vi tri cong: "<<viTriCong<<endl;
            cout<<"Trang thai: "<<(trangThai?"Mo":"Dong")<<endl;
            cout<<"So luot ra vao: "<<soLuotRaVao<<endl;
        }else {
            cout<<"Mat khau khong dung! Khong the xem thong ke."<<endl;
        }
    }
};

int main() {
    CongTuDong cong1;
    string viTri,mk,mkmoi; 
    cout<<"Nhap vi tri cong: ";
    getline(cin,viTri);
    cout<<"Cai dat mat khau: ";
    getline(cin,mk);
    cout<<"Nhap mat khau de mo cong: ";
    getline(cin,mk);
    cong1.setViTriCong(viTri);
    cong1.setMatKhau(mk);
    cong1.moCong(mk);
    cong1.dongCong(mk);
    cout<<"Nhap mat khau moi: ";
    getline(cin,mkmoi);
    cong1.doiMatKhau(mk,mkmoi);
    cout<<"Nhap mat khau de xem thong ke:";
    getline(cin,mk);
    cong1.xemThongKe(mk);
    return 0;
}