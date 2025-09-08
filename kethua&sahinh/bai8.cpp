#include <iostream>
using namespace std;


class SanPham{
    protected:
    string maSP,kichThuoc,mauSac;
    char chatluong;
    double trongLuong;
    public:
    SanPham(string ma,string kt,string mau,char cl,double tl){
        maSP=ma;
        kichThuoc=kt;
        mauSac=mau;
        chatluong=cl;
        trongLuong=tl;
    }
    string getMaSP(){
        return maSP;
    }
    string getKichThuoc(){
        return kichThuoc;
    }
    string getMauSac(){
        return mauSac;
    }
    char getChatLuong(){
        return chatluong;
    }
    double getTrongLuong(){
        return trongLuong;
    }
};


class TieuChiPhanLoai: public SanPham {
    public:
    TieuChiPhanLoai(string ma,double tl,string kt,string mau,char cl):SanPham(ma,kt,mau,cl,tl){}
    string phanLoaiTheoTrongLuong(){
        if (trongLuong<1.0) return "Nhe";
        if (trongLuong<5.0) return "Vua";
        return "Nang";
    }
    string phanLoaiTheoKichThuoc(){
        return kichThuoc;
    }
    string phanLoaiTheoChatLuong(){
        if (chatluong=='A') return "ChatluongA";
        if (chatluong=='B') return "ChatluongB";
        return "ChatluongC";
    }
    string phanLoaiTheoMauSac(){
        return mauSac;
    }
};


class thungChua{
    private:
    string nhanThung;
    int sucChuaToiDa;
    int soLuongHienTai;
    public:
    thungChua(){}
    thungChua(string nhan,int max):nhanThung(nhan),sucChuaToiDa(max),soLuongHienTai(0){}
    string getNhan(){
        return nhanThung;
    }
    bool themSanPham(){
        if (soLuongHienTai<sucChuaToiDa){
            soLuongHienTai++;
            return true;
        }
        return false;
    }
    void hienThi(){
        cout<<nhanThung<<": "<<soLuongHienTai<<"/ "<<sucChuaToiDa<<endl;
    }
};


class HeThongPhanLoai{
    protected:
    thungChua dsthung[10];
    int soLuongThung=0;
    public:
    void themThung(const thungChua& t){
        if (soLuongThung<10){
            dsthung[soLuongThung++]=t;
        }
    }
    bool phanLoaiSanPham(TieuChiPhanLoai& sp){
        string loai=sp.phanLoaiTheoChatLuong();
        for (int i=0;i<soLuongThung;i++){
            if (loai==dsthung[i].getNhan()){
                if (!dsthung[i].themSanPham()){
                    cout<<"Thung:"<<loai<<" da day!"<<endl;
                    return false;
                }
                return true;
            }
        }
        cout<<"Khong tim thay thung phu hop!"<<endl;
        return false;
    }
    void thongKe(){
        for (int i=0;i<soLuongThung;i++){
            dsthung[i].hienThi();
        }
    }
    };


    class RobotPhanLoai: public HeThongPhanLoai{
        public:
        void laySanPham(){
            cout<<"Dang lay san pham!"<<endl;
        }
        void kiemTra(TieuChiPhanLoai& sp){
            cout<<"Ma:"<<sp.getMaSP()<<endl;
            cout<<"Trong Luong :"<<sp.getTrongLuong()<<endl;
            cout<<"Kich Thuoc:"<<sp.getKichThuoc()<<endl;
            cout<<"Mau:"<<sp.getMauSac()<<endl;
            cout<<"Chat Luong:"<<sp.getChatLuong()<<endl;
        }
        void datVaoThung(TieuChiPhanLoai& sp){
            cout<<"Da dat sp vao thung!"<<endl;
            phanLoaiSanPham(sp);
        }
    };


    int main() {
        RobotPhanLoai robot;
        robot.themThung(thungChua("ChatluongA",3));
        robot.themThung(thungChua("ChatluongB",3));
        robot.themThung(thungChua("ChatluongC",3));


        TieuChiPhanLoai sp1("SP001",0.5,"S","Do",'A');
        TieuChiPhanLoai sp2("SP002",2.5,"M","Do",'C');
        TieuChiPhanLoai sp3("SP003",3.5,"L","Do",'B');
        TieuChiPhanLoai sp4("SP004",1.5,"M","Do",'A');


        robot.laySanPham();robot.kiemTra(sp1);robot.datVaoThung(sp1);
        robot.laySanPham();robot.kiemTra(sp2);robot.datVaoThung(sp2);
        robot.laySanPham();robot.kiemTra(sp3);robot.datVaoThung(sp3);
        robot.laySanPham();robot.kiemTra(sp4);robot.datVaoThung(sp4);


        cout<<"\nThong ke:\n";
        robot.thongKe();
        return 0;
}
