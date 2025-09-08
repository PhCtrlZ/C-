#include <iostream>

using namespace std;

class MayLanh{
    public:
    string hangSanXuat;
    int nhietDoMongMuon;
    double congSuat;
    //constructor ko tham số
    MayLanh(){
        hangSanXuat = "Chua xac dinh!";
        nhietDoMongMuon =0;
        congSuat =0;
    }
    //contructor co tham so
    MayLanh(string hang,int nhietDo,double power){
        hangSanXuat=hang;
        nhietDoMongMuon=nhietDo;
        congSuat=power;
    }
    void batMayLanh(){
        cout<<"May lanh da bat!"<<endl;
    }
    void tatMayLanh(){
        cout<<"May lanh da tat!"<<endl;
    }
    void hienThi(){
        cout<<"Hang san xuat: "<<hangSanXuat<<endl;
        cout<<"Nhiet do mong muon: "<<nhietDoMongMuon<<" do C"<<endl;
        cout<<"Cong suat: "<<congSuat<<"HP"<<endl;
    }
    void caiDatNhietDo(int nhietDo){
        nhietDoMongMuon+=nhietDo;
        if(nhietDoMongMuon>30){
            nhietDoMongMuon=30;
            cout<<"da dat nhiet do toi da!"<<endl;
    }else if(nhietDoMongMuon<16){
            nhietDoMongMuon=16;
            cout<<"nhiet do da dat muc toi thieu!"<<endl;
    }else{
        cout<<"Nhiet do hien tai:"<<nhietDoMongMuon<<" C"<<endl;
    }
    }

};
int main(){
    MayLanh maylanh;
    string hang;
    int nhietDo;
    double congSuat;
    cout<<"Nhap hang san xuat may lanh: ";
    getline(cin, hang);
    cout<<"Nhap nhiet do mong muon (16-30): ";
    cin>>nhietDo;
    cout<<"Nhap cong suat (HP): ";
    cin>>congSuat;
    maylanh.hangSanXuat = hang;
    maylanh.nhietDoMongMuon = nhietDo;
    maylanh.congSuat = congSuat;
    maylanh.hienThi();
    maylanh.batMayLanh();
    maylanh.tatMayLanh();
    return 0;
}