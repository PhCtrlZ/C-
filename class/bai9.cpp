#include <iostream>
using namespace std;

class HeThongTuoi{
    private:
    int doAmDat;
    int nguongTuoi;
    bool vanNuoc;
    int soLanTuoi;
    public:
    //costructor ko tham so
    HeThongTuoi(){
        doAmDat=30;
        nguongTuoi=0;
        vanNuoc=false;
        soLanTuoi=0;
    }
    HeThongTuoi(int nguong){
        if (nguong <0|| nguong>100){
            cout<<"Nguong tuoi khong hop le!"<<endl;
        }else {
            nguongTuoi=nguong;
        }
        vanNuoc=false;
        soLanTuoi=0;
    }
    //getter
    int getdoAmDat(){
        return doAmDat;
    }
    int getnguonTuoi(){
        return nguongTuoi;
    }
    bool getvanNuoc(){
        return vanNuoc;
    }
    int getsoLanTuoi(){
        return soLanTuoi;
    }
    //setter
    void setdoAmDat(int doAm){
        if (doAm <0 || doAm>100){
            cout<<"Do am k hop le!"<<endl;
        }
        doAmDat=doAm;
    }
    void setnguongTuoi(int nguong){
        if(nguong<0||nguong>100){
            cout<<"Nguong tuoi k hop le nguong tuoi phai nam trong khoang (0->100)"<<endl;
            return;
        }
        nguongTuoi=nguong;
    }
    void setvanNuoc(bool nuoc){
        vanNuoc=nuoc;
    }
    void capNhatDoAm(int doAm){
        setdoAmDat(doAm);
        cout<<"Do am dat da dduoc cap nhat:"<<doAmDat<<"%"<<endl;
    }
    void kiemTraVaTuoi(){
        cout<<"Hien thi thong tin he thong !"<<endl;
        cout<<"Do am:"<<doAmDat<<"%"<<endl;
        cout<<"Nguong tuoi:"<<nguongTuoi<<"%"<<endl;
        if (doAmDat<nguongTuoi){
            vanNuoc=true;
            soLanTuoi++;
            doAmDat+=20;//khi nào cần tưới thì độ ẩm sẽ tăng thêm 20%
            if (doAmDat>100 ) doAmDat=100;
            cout<<"Do am sau khi tuoi cay:"<<doAmDat<<endl;
        }else {
            vanNuoc=false;
            cout<<"Do am dat da du!"<<endl;
        }
    }
    void dungTuoi(){
        vanNuoc=false;
        cout<<"Van nuoc da dong";
    }
    void caiDatNguong(int nguong){
        setnguongTuoi(nguong);
        cout<<"Nguong tuoi da duoc cai dat:"<<nguongTuoi<<"%"<<endl;
    }
};

int main() {
    HeThongTuoi hethong;
    cout<<"thong tin he thong"<<endl;
    hethong.capNhatDoAm(40);
    hethong.caiDatNguong(60);
    hethong.kiemTraVaTuoi();
    hethong.dungTuoi();
    return 0;
}