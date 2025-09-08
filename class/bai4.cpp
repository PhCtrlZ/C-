#include <iostream>
using namespace std;

class BomNuoc
{
    private:
    double apSuat;
    int soGioChay;
    string maBaoMat;
    public:
    string tenBom;
    //contructor k tham so
    BomNuoc() {
        apSuat = 0.0;
        soGioChay = 0;
        maBaoMat = "chua co!";
        tenBom = "Chua xac dinh!";
    }
    //constructor co tham so
    BomNuoc(double ap,int time,string key,string name){
        apSuat = ap;
        maBaoMat = key;
        soGioChay = time;
        tenBom = name;
    }
    //setter
    void datApSuat(double ap,string key){
        if(key== maBaoMat){
            apSuat=ap;
        }
    }
    void datSoGioChay(int time,string key){
        if(key==maBaoMat){
            soGioChay=time;
        }
    }
    void datMaBaoMat(string key){
        maBaoMat = key;
    }
    //getter
    double layApSuat(){
        return apSuat;
    }
    int laySoGioChay(){
        return soGioChay;
    }
    string layMaBaoMat() {
        return maBaoMat;
    }
    void batBom(string key){
        if (key==maBaoMat){
            cout<<"Bat bom nuoc thanh cong!"<<endl;
        }else {
            cout<<"ma bao mat khong dung!"<<endl;
        }
    }
    void tatBom(string key){
        if (key==maBaoMat){
            cout<<"Tat bom nuoc thanh cong!"<<endl;
        }else {
            cout<<"ma bao mat khong dung!"<<endl;
        }
    }
    void xemApSuat(string key){
        if (key==maBaoMat){
            cout<<"Ap suat cua bom nuoc la: "<<apSuat<<endl;
        }else {
            cout<<"ma bao mat khong dung!"<<endl;
        }
    }
    void xemGioChay(string key) {
        if (key == maBaoMat) {
            cout << "So gio bom nuoc chay la: " << soGioChay << endl;
        } else {
            cout << "Ma bao mat khong dung!" << endl;
        }
    }
};
int main() {
    BomNuoc bom1;
    string ten;
    double apSuat;
    int soGio;
    string maBaoMat,pass;
    cout << "Nhap ten bom nuoc: ";
    getline(cin,ten);
    cout<<"Nhap ma bao mat:";
    getline(cin,maBaoMat); 
    cout << "Nhap ap suat : ";
    cin>>apSuat;
    cout<<"Nhap so gio chay:";
    cin >> soGio;
    cin.ignore();
    cout<<"Nhap ma bao mat de bat bom va coi thong tin"<<endl;
    getline(cin,pass);
    bom1.tenBom=ten;
    bom1.datMaBaoMat(maBaoMat);
    bom1.datApSuat(apSuat, maBaoMat);
    bom1.datSoGioChay(soGio, maBaoMat);
    //in ra thoong tin
    cout<<"Ten bom:"<< bom1.tenBom << endl;
    cout<<"Ap suat:"<<bom1.layApSuat()<<endl;
    cout<<"So gio chay:"<<bom1.laySoGioChay()<<endl;
    cout<<"Ma bao mat:"<<bom1.layMaBaoMat()<<endl;
    bom1.batBom(pass);
    bom1.tatBom(pass);
    cin>>pass;
    return 0;
}