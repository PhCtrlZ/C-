#include <iostream>
using namespace std;

class ThangMay{
    private:
    int tangHienTai;
    int soNguoi;
    bool cuaMo;
    int tongLuotPhucVu;
    public:
    //constructor ko tham so
    ThangMay(){
        tangHienTai=1;
        soNguoi=0;
        cuaMo=false;
        tongLuotPhucVu=0;
    }
    //constructor co tham so
    ThangMay(int tang,int sn,bool cua,int phucvu){
        tang=tangHienTai;
        sn=soNguoi;
        cua=cuaMo;
        phucvu=tongLuotPhucVu;
    }
    //getter (goi len cac gia tri trong private)
    int getTangHienTai(){
        return tangHienTai;
    }
    int getSoNguoi(){
        return soNguoi;
    }
    bool getCuaMo(){
        return cuaMo;
    }

    //phuong thuc
    void goiThang(int tang){
        if(tang<1||tang>10){
            cout<<"Tang ko hop le tang phai nam trong (1-10)"<<endl;
            return;
        }
        tangHienTai=tang;
        cout<<"Thang may da di chuyen den tang:"<<tang<<endl;
    }
    void moCua(){
        cuaMo=true;
        cout<<"cua thang may da mo"<<endl;
    }
    void dongCua(){
        cuaMo=false;
        cout<<"cua thang may da dong"<<endl;
    }
    void vaoThang(int soNguoiVao){
        if (soNguoiVao<0){
            cout<<"so nguoi phai lon hon 0"<<endl;
        }
        if (soNguoi+soNguoiVao>8){
            cout<<"Thang may co trong tai toi da la 8 nguoi"<<endl;
        }
        soNguoi+=soNguoiVao;
        tongLuotPhucVu++;
        cout<<soNguoiVao<<" nguoi da vao thang may .Tong la:"<<soNguoi<<"/8 nguoi"<<endl;
    }
    void raThang(int soNguoiRa){
        if (soNguoiRa<0){
            cout<<"so nguoi ra phai lon hon 0"<<endl;
        }
        if (soNguoiRa>soNguoi){
            cout<<"so nguoi ra ko the lon hon so nguoi o trong thang may"<<endl;
        }
        soNguoi-=soNguoiRa;
        cout<<soNguoiRa<<" nguoi da ra thang may.Con lai:"<<soNguoi<<"/8 nguoi"<<endl;
    }
};

int main() {
    ThangMay thangmay1;
    int tang;
    cout<<"Nhap so tang can di toi de don nguoi!"<<endl;
    cin>>tang;
    thangmay1.goiThang(tang);
    thangmay1.moCua();
    int songuoi;
    cout<<"nhap so nguoi vao thang may (max 8)"<<endl;
    cin>>songuoi;
    thangmay1.vaoThang(songuoi);
    thangmay1.dongCua();
    cout<<"Nhap so tang can di toi!"<<endl;
    cin>>tang;
    thangmay1.goiThang(tang);
    thangmay1.moCua();
    int songuoira;
    cout<<"Nhap so nguoi can ra thang may!"<<endl;
    cin>>songuoira;
    thangmay1.raThang(songuoira);
    thangmay1.dongCua();
    return 0;
}