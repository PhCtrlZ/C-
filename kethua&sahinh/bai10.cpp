#include <iostream>
#include <string>
#include <vector>
using namespace std;


class NguoiDung{
    private:
    string ten,loaiKhuyetTat;
    double tocDo;
    int tuoi;
    string soThich;
    public:
    NguoiDung(string t, string kt,double sp,int age,string st){
        ten=t;
        loaiKhuyetTat=kt;
        tocDo=sp;
        tuoi=age;
        soThich=st;
    }
    void hienThiThongTin(){
        cout<<"User"<<ten<<endl;
        cout<<"Tuoi:"<<tuoi<<endl;
        cout<<"Khuyet tat:"<<loaiKhuyetTat<<endl;
        cout<<"Toc do:"<<tocDo<<endl;
        cout<<"So thich:"<<soThich<<endl;
    }
};
class MoiTruong{
    private:
    string banDo;
    vector<string> vatCan;
    vector<string> bienBao;
    vector<string> nguoiXungQuanh;
    public:
    MoiTruong(string bd){
        banDo=bd;
    }
    void themVatCan(string v){
        vatCan.push_back(v);
    }
    void themBienBao(string v){
        bienBao.push_back(v);
    }
    void themNguoiXungQuanh(string v){
        nguoiXungQuanh.push_back(v);
    }
    void hienThiThongTinMoiTruong(){
        cout<<"Ban do:"<<banDo<<endl;
        cout<<"Vat can:"<<endl;
        for (auto &v:vatCan) cout<<v<<" "<<endl;
        for (auto &v:bienBao) cout<<v<<" "<<endl;
        for (auto &v:nguoiXungQuanh) cout<<v<<" "<<endl;
    }
};
class HeThongCamBien{
    public:
    void camera(){
        cout<<"Camera dang nhan dien vat the phia truoc!"<<endl;
    }
    void ultrasonic(){
        cout<<"Ultrasonic do khoang cach vat can!"<<endl;
    }
    void microphone(){
        cout<<"Microphone dang nghe ngong xung quanh!"<<endl;
    }
    void gps(){
        cout<<"GPS dinh vi,vi tri hien tai!"<<endl;
    }
};
class GiaoTiepGiongNoi{
    public:
    void noi(string text){
        cout<<"Robot:"<<text<<endl;
    }
    void nhanLenh(string lenh){
        cout<<"User:"<<lenh<<endl;
    }
};
class AI_HocTapNhuCau{
    public:
    void hocTocDo(double v){
        cout<<"Hoc toc do di chuyen thich hop:"<<v<<endl;
    }
    void hocDuongDi(string duong){
        cout<<"Hoc duong di ua thich :"<<duong<<endl;
    }
    void hocCanhBao(string loai ){
        cout<<"Hoc canh bao:"<<loai<<endl;
    }
};
class RobotHoTro{
    private:
    NguoiDung *nguoiDung;
    string cheDo;
    int mucHoTro;
    HeThongCamBien camBien;
    GiaoTiepGiongNoi giongNoi;
    AI_HocTapNhuCau ai;
    public:
    RobotHoTro(NguoiDung *nd,string mode,int muc){
        nguoiDung=nd;
        cheDo=mode;
        mucHoTro=muc;
    }
    void quetMoiTruong(MoiTruong &mt){
        cout<<"Dang quet moi truong!"<<endl;
        camBien.camera();
        camBien.ultrasonic();
        camBien.gps();
        mt.hienThiThongTinMoiTruong(); 
    }
    void phatHienNguyHiem(string nguyHiem){
        cout<<"Da phat hien nguy hiem!"<<endl;
        giongNoi.noi("Canh bao! Co "+nguyHiem+" o phia truoc.");
    }
    void danDuong(string huong){
        giongNoi.noi("Di "+huong+" de an toan");
    }
    void hocNguoiDung(){
        ai.hocTocDo(1.2);
        ai.hocCanhBao("An toan la tren het!");
        ai.hocDuongDi("Duong den sieu thi");
    }
    void goiTroGiup(string so){
        cout<<"Dang goi tro giup toi so khan cap !"<<so<<endl;
    }
    void noi(string t){
        giongNoi.noi(t);
    }
    void nhanLenh(string l){
        giongNoi.nhanLenh(l);
    }
    void dinhVi(){
        camBien.gps();
    }
};
int main() {
    NguoiDung nd("Nguyen Hoang Phuc","Khiem thi",1.0,19,"Mua do an");
    nd.hienThiThongTin();


    MoiTruong mt("Ban do thanh pho!");
    mt.themVatCan("Bac thang");
    mt.themBienBao("Den do");
    mt.themNguoiXungQuanh("Nguoi di bo");


    RobotHoTro robot(&nd,"Tu dong",3);
    robot.quetMoiTruong(mt);
    robot.phatHienNguyHiem("Bac thang");
    robot.danDuong("Re trai,di thang 5m");
    robot.hocNguoiDung();
    robot.goiTroGiup("113");


    robot.noi("Den do, cho 15 giay");
    robot.noi("Den xanh, an toan de qua duong");


    robot.nhanLenh("Tim sua tuoi");
    robot.noi("Queo trai, di thang 5 met, ke sua ben phai");


    robot.phatHienNguyHiem("Nguoi dung nga");
    robot.goiTroGiup("115");
    robot.dinhVi();


    return 0;
}
