#include <iostream>
using namespace std;

class CamBienNhietDo{
    private:
    double nhietDo;
    double nguongCao;
    double nguongThap;
    public:
    //contructor ko tham so
    CamBienNhietDo() {
        nhietDo = 0.0;
        nguongCao = 0.0;
        nguongThap = 0.0;
    }
    //contructor co tham so
    CamBienNhietDo(double cao,double thap){
        nguongCao = cao;
        nguongThap = thap;
        nhietDo = 25; 
    }
    //setter
    void setNhietDo(double t){
        if (t>-50 && t<100){
            nhietDo=t;
        }else {
            cout<<"Gia tri nhiet do nam trong khoang -50->100C"<<endl;
        }
    }
    void setNguongCao(double cao){
        if (cao>nguongThap){
            nguongCao = cao;
        }
    }
    void setNguongThap(double thap){
        if (thap<nguongCao){
            nguongThap = thap;
        }
    }
    //getter
    double getNhietDo(){
        return nhietDo;
    }
    double getNguongCao(){
        return nguongCao;
    }
    double getNguongThap(){
        return nguongThap;
    }
    void kiemTraCanhBao(){
        if(nhietDo>nguongCao){
            cout<<"Nhiet do vuot nguong cao!"<<endl;
        }else if(nhietDo<nguongThap){
            cout<<"Nhiet do thap hon nguong thap!"<<endl;
        }
    }
};

int main() {
    CamBienNhietDo camBien1;
    double nhietDo, nguongCao, nguongThap;
    cout<<"Nhap nhiet do muon tang len:";
    cin>>nhietDo;
    cout<<"Nhap nguong cao:";
    cin>>nguongCao;
    cout<<"Nhap nguong thap:";
    cin>>nguongThap;
    camBien1.setNhietDo(nhietDo);
    camBien1.setNguongCao(nguongCao);
    camBien1.setNguongThap(nguongThap);
    camBien1.kiemTraCanhBao();

    cout<<"Thong tin cam bien:"<<endl;
    cout<<"Nhiet do hien tai:"<<camBien1.getNhietDo()<<endl;
    cout<<"Nguong cao:"<<camBien1.getNguongCao()<<endl;
    cout<<"Nguong thap:"<<camBien1.getNguongThap()<<endl;
    return 0;
}