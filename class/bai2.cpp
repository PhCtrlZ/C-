#include <iostream>
using namespace std;

class QuatDien{
    public:
    string hangSanXuat;
    int tocDo;
    bool trangThai;
    //constructor
    QuatDien(){
        cout<<"Quat moi duoc lap dat!"<<endl;
        hangSanXuat="Chua xac dinh!";
        tocDo=0;
        trangThai=false;
    }
    void batQuat(){
        trangThai=true;
        cout<<"Quat da bat!"<<endl;
    }
    void tatQuat(){
        trangThai=false;
        cout<<"Quat da tat!"<<endl;
    }
    void tangTocDo(int a){
        if (a>3){
            cout<<"Toc do quat oi da la 3"<<endl;
            tocDo = 3;

        }
        else if(a<0){
            cout<<"toc do quat toi thieu la 1"<<endl;
            tocDo=0;
        }
        else if (a=0){
            cout<<"quat van dang tat!"<<endl;
        }
        else {
            tocDo+=a;
            cout<<"Da tang toc do len "<<tocDo<<endl;
        }
    }
    void hienThiThongTin(){
        cout<<"Hang san xuat: "<<hangSanXuat<<endl;
        cout<<"Toc do: "<<tocDo<<endl;
        cout<<"Trang thai: "<<(trangThai ? "Bat" : "Tat")<<endl;
    }
};

int main() {
    QuatDien quat;
    string hang;
    int speed;
    cout<<"Nhap hang san xuat quat: ";
    getline(cin,hang);
    cout<<"Nhap toc do (0-3): ";
    cin>>speed;
    quat.hangSanXuat = hang;
    quat.tocDo = speed;
    quat.hienThiThongTin();
    quat.batQuat();
    quat.tangTocDo(quat.tocDo);
    quat.tatQuat();
    return 0;
}