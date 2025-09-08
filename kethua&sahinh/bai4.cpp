#include <iostream>
#include <string>
using namespace std;


class CauHoi{
    public:
    string noiDung,phanLoai;
    string tuKhoa[10];
    int soTuKhoa;
    CauHoi(string nd="",string l="Gi"){
        noiDung=nd;
        phanLoai=l;
        soTuKhoa=0;
    }
    void themTuKhoa(string keyWord){
        if (soTuKhoa<5){
            tuKhoa[soTuKhoa++]=keyWord;
        }
    }
};
class CauTraLoi{
    public:
    string noiDung,nguonTL;
    double tinCay;
    string nguon;
    CauTraLoi(string nd="Khong co du lieu",double tc=1.0,string n ="He thong"){
        noiDung=nd;
        tinCay=tc;
        nguon=n;
    }
};
class KhoKienThuc{
    private:
    string chuDe;
    string dsTuKhoa[20];
    CauTraLoi dsCauTraLoi[20];
    int soLuong;
    public:
    KhoKienThuc(string cd="Chung"){
        chuDe=cd;
        soLuong=0;
    }
    void themKienThuc(string tuKhoa,CauTraLoi ctl){
        if(soLuong<20){
            dsTuKhoa[soLuong]=tuKhoa;
            dsCauTraLoi[soLuong]=ctl;
            soLuong++;
        }
    }
    CauTraLoi timCauTraLoi(CauHoi cauHoi){
        for (int i=0;i<cauHoi.soTuKhoa;i++){
            for (int j=0;j<soLuong;j++){
                if(cauHoi.tuKhoa[i]==dsTuKhoa[j]){
                    return dsCauTraLoi[j];
                }
            }
        }
        return CauTraLoi("Chua co thong tin ve cau hoi nay!");
    }
};
class ChatBot{
    private:
    string tenBot;
    KhoKienThuc *kho;
    public:
    ChatBot(string ten,KhoKienThuc *k){
        tenBot=ten;
        kho=k;
    }
    CauHoi phanTichCauHoi(string text){
        CauHoi ch(text,"Gi");
        string lower=text;
        for (int i=0;i<(int)lower.size();i++){
            lower[i]=tolower(lower[i]);
        }
        if (lower.find("thoi tiet")!=string::npos) ch.themTuKhoa("Thoi tiet");
        if (lower.find("hom nay")!=string::npos) ch.themTuKhoa("Hom nay");
        if (lower.find("ten")!=string::npos) ch.themTuKhoa("Ten");
        return ch;
    }
    string traLoi(string text){
        CauHoi cauHoi=phanTichCauHoi(text);
        CauTraLoi ctl=kho->timCauTraLoi(cauHoi);
        return ctl.noiDung;
    }
};
int main(){
    KhoKienThuc kho("Chung");
    kho.themKienThuc("Thoi tiet",CauTraLoi("Hom nay troi nang ,nhiet do la 21 do",0.9,"Du bao thoi tiet"));
    kho.themKienThuc("Ten",CauTraLoi("Toi la Chatbot hoi dap don gian!"));
    ChatBot bot("AI Bot",&kho);
    cout<<"User:Thoi tiet hom nay"<<endl;
    cout<<"Chatbot:"<<bot.traLoi("Thoi tiet hom nay nhu the nao?")<<endl;
    cout<<"User:Ban ten la gi"<<endl;
    cout<<"Chatbot:"<<bot.traLoi("Ban ten gi!")<<endl;
    cout<<"User:Khi nao troi mua?"<<endl;
    cout<<"Chatbot:"<<bot.traLoi("Khi nao co mua?")<<endl;
    return 0;
}
