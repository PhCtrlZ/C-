#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <ctime>
#include <iomanip>
using namespace std;


struct HoatDong {
    string moTa;
    string thoiGian;
    int gio, phut;
    string ngayTrongTuan;


    HoatDong(string md, string tg) {
        moTa = md;
        thoiGian = tg;
        if (tg.length() >= 4) {
            gio = stoi(tg.substr(0, 2));
            phut = stoi(tg.substr(2, 2));
        } else {
            gio = phut = 0;
        }
        time_t now = time(0);
        tm* ltm = localtime(&now);
        int ngay = ltm->tm_wday;
        string ngayTuan[] = {"Chu nhat", "Thu 2", "Thu 3", "Thu 4", "Thu 5", "Thu 6", "Thu 7"};
        ngayTrongTuan = ngayTuan[ngay];
    }
};


class ThietBiNha {
    private:
    string ten;
    string vitri;
    bool trangthai;
    public:
    ThietBiNha(string t, string v) {
        ten = t;
        vitri = v;
        trangthai = false;
    }
    void bat() {
        trangthai = true;
        cout << ten << " tai " << vitri << " da duoc bat\n";
    }
    void tat() {
        trangthai = false;
        cout << ten << " tai " << vitri << " da duoc tat\n";
    }
    string getTen() { return ten; }
    bool getTrangThai() { return trangthai; }
};


class ThoiQuen {
    private:
    string thoigian;
    string hanhdong;
    string tansuatsu;
    double dotincay;
    int soLanXuatHien;
    vector<string> ngayTrongTuan;
    public:
    ThoiQuen(string tg, string hd, string ts, double dtc) {
        thoigian = tg;
        hanhdong = hd;
        tansuatsu = ts;
        dotincay = dtc;
        soLanXuatHien = 1;
    }


    void tangTanSuat() {
        soLanXuatHien++;
        dotincay = min(1.0, 0.5 + (soLanXuatHien * 0.1));
    }


    void themNgayTrongTuan(string ngay) {
        if (find(ngayTrongTuan.begin(), ngayTrongTuan.end(), ngay) == ngayTrongTuan.end()) {
            ngayTrongTuan.push_back(ngay);
        }
    }


    void hienThi() {
        cout << "Thoi quen: " << hanhdong 
        << " vao luc " << thoigian 
        << " (" << tansuatsu << "), do tin cay: " 
    << fixed << setprecision(2) << dotincay 
<< " (xuat hien " << soLanXuatHien << " lan)\n";
if (!ngayTrongTuan.empty()) {
    cout << "  - Cac ngay: ";
    for (string ngay : ngayTrongTuan) {
        cout << ngay << " ";
    }
    cout << "\n";
}
    }


    string getThoiGian() const { return thoigian; }
    string getHanhDong() const { return hanhdong; }
    double getDoTinCay() const { return dotincay; }
    int getSoLanXuatHien() const { return soLanXuatHien; }
};


class HocThoiQuen {
    private:
    vector<HoatDong> lichsu;
    vector<ThoiQuen> dsThoiQuen;
    map<string, int> tanSuatHoatDong;
    map<string, vector<pair<int, int>>> thoiGianHoatDong;


    public:
    void ghiNhanHoatDong(string hd, string tg) {
        HoatDong hdMoi(hd, tg);
        lichsu.push_back(hdMoi);
        tanSuatHoatDong[hd]++;
        thoiGianHoatDong[hd].push_back({hdMoi.gio, hdMoi.phut});
        cout << "Da ghi nhan: " << hd << " luc " << tg << " (" << hdMoi.ngayTrongTuan << ")\n";
    phanTichThoiQuen();
    }


pair<int, int> tinhTrungBinhThoiGian(const vector<pair<int, int>>& thoiGianList) {
    if (thoiGianList.empty()) return {0, 0};


    int tongGio = 0, tongPhut = 0;
    for (const auto& tg : thoiGianList) {
        tongGio += tg.first;
        tongPhut += tg.second;
    }


    int trungBinhGio = tongGio / thoiGianList.size();
    int trungBinhPhut = tongPhut / thoiGianList.size();
    if (trungBinhPhut >= 60) {
        trungBinhGio += trungBinhPhut / 60;
        trungBinhPhut %= 60;
    }


    return {trungBinhGio, trungBinhPhut};
}


void phanTichThoiQuen() {
    cout << "\n=== PHAN TICH THOI QUEN ===\n";
    if (!lichsu.empty()) {
        const HoatDong& hdMoiNhat = lichsu.back();
        string hoatDong = hdMoiNhat.moTa;
        if (thoiGianHoatDong[hoatDong].size() >= 2) {
            auto trungBinh = tinhTrungBinhThoiGian(thoiGianHoatDong[hoatDong]);
            string thoiGianFormatted = to_string(trungBinh.first) + "h" + 
                                    (trungBinh.second < 10 ? "0" : "") + to_string(trungBinh.second);


                                    int soLan = thoiGianHoatDong[hoatDong].size();
                                    double doTinCay = min(1.0, 0.3 + (soLan * 0.2));
                                    bool daTonTai = false;
                                    for (ThoiQuen& tq : dsThoiQuen) {
                                        if (tq.getHanhDong() == hoatDong) {
                                                tq.tangTanSuat();
                                                    daTonTai = true;
                                                        cout << ">> Cap nhat thoi quen: " << hoatDong << " luc " << thoiGianFormatted 
                                                                    << " (trung binh tu " << soLan << " lan)\n";
                                                                    break;
                                        }
                                    }
                                if (!daTonTai) {
                                    string tanSuat = (soLan >= 3) ? "Hang ngay" : "Thuong xuyen";
                                    ThoiQuen tq(thoiGianFormatted, hoatDong, tanSuat, doTinCay);
                                    dsThoiQuen.push_back(tq);
                                    cout << ">> Phat hien thoi quen moi: " << hoatDong << " luc " << thoiGianFormatted 
                                            << " (trung binh tu " << soLan << " lan)\n";
                                }
        }
    }


cout << "Hoan thanh phan tich!\n";
}


void hienThiThoiQuen() {
    if (dsThoiQuen.empty()) {
        cout << "Chua hoc duoc thoi quen nao!\n";
    } else {
        cout << "--- Danh sach thoi quen robot hoc duoc (" << dsThoiQuen.size() << " thoi quen) ---\n";
    for (int i = 0; i < dsThoiQuen.size(); i++) {
        cout << (i+1) << ". ";
        dsThoiQuen[i].hienThi();
    }
}
}


void thongKeHoatDong() {
    cout << "\n=== THONG KE HOAT DONG ===\n";
    cout << "Tong so hoat dong da ghi nhan: " << lichsu.size() << "\n";
    cout << "So thoi quen da hoc: " << dsThoiQuen.size() << "\n";


    if (!tanSuatHoatDong.empty()) {
        cout << "Top hoat dong pho bien:\n";
        vector<pair<string, int>> sortedHoatDong;
        for (const auto& pair : tanSuatHoatDong) {
            sortedHoatDong.push_back(pair);
        }


        sort(sortedHoatDong.begin(), sortedHoatDong.end(), 
    [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
    });


    for (int i = 0; i < min(5, (int)sortedHoatDong.size()); i++) {
        cout << (i+1) << ". " << sortedHoatDong[i].first 
            << " (" << sortedHoatDong[i].second << " lan)\n";
    }
    }
}
};


class RobotQuanGia {
    private:
    vector<ThietBiNha> dsThietBi;
    HocThoiQuen hoc;
    public:
    void themThietBi(ThietBiNha tb) {
        dsThietBi.push_back(tb);
    }


    void giamSat(string hd, string tg) {
        cout << "Robot giam sat: " << hd << " luc " << tg << "\n";
        hoc.ghiNhanHoatDong(hd, tg);
    }


    void hienThiThoiQuen() {
        hoc.hienThiThoiQuen();
    }


    void thongKe() {
        hoc.thongKeHoatDong();
    }
};


int main() {
    RobotQuanGia robot1;
    ThietBiNha den("Den", "Phong khach");
    robot1.themThietBi(den);


    int chon;
    string hd, tg;


    do {
        cout << "\n=== MENU ROBOT QUAN GIA ===\n";
        cout << "1. Nhap hoat dong\n";
        cout << "2. Hien thi thoi quen\n";
        cout << "3. Thong ke hoat dong\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> chon;
        cin.ignore();


        switch (chon) {
            case 1:
            cout << "Nhap hoat dong (vd: 'Chu bat den'): ";
            getline(cin, hd);
            cout << "Nhap thoi gian (vd: 0635): ";
            getline(cin, tg);
            robot1.giamSat(hd, tg);
            break;
            case 2:
            robot1.hienThiThoiQuen();
            break;
            case 3:
            robot1.thongKe();
            break;
            case 0:
            cout << "Thoat chuong trinh\n";
            break;
            default:
            cout << "Lua chon khong hop le\n";
        }
    } while (chon != 0);


    return 0;
}
