#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <limits>

using namespace std;

enum LoaiDoVat { DO_CHOI, DO_AN, RAC, DO_DUNG, KHONG_XAC_DINH };
enum HinhDang { TRON, VUONG, TAM_GIAC, CHU_NHAT, KHAC };
enum ChatLuongAnh { LOW, MEDIUM, HIGH };
enum TrangThaiCamera { SAN_SANG, DANG_CHUP, LOI };
enum CheDoNhanDien { TU_DONG, THU_CONG };
enum ThuatToanSoSanh { EUCLIDEAN, COSINE };

struct RGB {
    int r, g, b;
};
struct KichThuoc {
    float dai, rong, cao;
};

class DoVat {
private:
    string tenDoVat;
    LoaiDoVat loaiDoVat;
    HinhDang hinhDang;
    RGB mauSacChinh;
    KichThuoc kichThuoc;
    float trongLuong;
    float doTinCay;

public:
    DoVat(string ten="???", LoaiDoVat loai=KHONG_XAC_DINH, float tinCay=0.0f)
    : tenDoVat(ten), loaiDoVat(loai), hinhDang(KHAC), trongLuong(0), doTinCay(tinCay) {}
    string getTen() const { return tenDoVat; }
    LoaiDoVat getLoai() const { return loaiDoVat; }
    float getDoTinCay() const { return doTinCay; }
    void layThongTin() {
        cout << "Ten: " << tenDoVat 
        << " - Loai: " << loaiDoVat 
        << " - Do tin cay: " << doTinCay*100 << "%\n";
    }
};

class Camera {
private:
    int doPhanGiaiX, doPhanGiaiY;
    ChatLuongAnh chatLuongAnh;
    TrangThaiCamera trangThai;

public:
    Camera(int x=640, int y=480) 
    : doPhanGiaiX(x), doPhanGiaiY(y), chatLuongAnh(MEDIUM), trangThai(SAN_SANG) {}

    string chupAnh() {
        if (trangThai == SAN_SANG) {
            trangThai = DANG_CHUP;
            cout << "[Camera] Da chup anh.\n";
            trangThai = SAN_SANG;
            return "anh_gia_lap";
        }
        return "";
    }
};

class BoNhanDien {
private:
    vector<DoVat> thuVienMau;
    float doChinhXacYeuCau;

public:
    BoNhanDien() : doChinhXacYeuCau(0.7f) {}

    void themMauMoi(const DoVat &d) { thuVienMau.push_back(d); }

    pair<DoVat,float> duDoan(const string &anh) {
        if (thuVienMau.empty()) {
            cout << "Chua hoc mau nao\n";
            return { DoVat("Khong xac dinh", KHONG_XAC_DINH), 0.0f };
        }
        DoVat d = thuVienMau[0];
        return { d, 0.85f }; 
    }
};

class RobotNhanDien {
private:
    string ten;
    int viTriX, viTriY;
    Camera camera;
    BoNhanDien boNhanDien;
    vector<DoVat> danhSachDoVatTimThay;

public:
    RobotNhanDien(string t="Robot") : ten(t), viTriX(0), viTriY(0) {}

    void diChuyen(int dx, int dy) {
        viTriX += dx; viTriY += dy;
        cout << ten << " da di chuyen toi (" << viTriX << "," << viTriY << ")\n";
    }

    void chupAnhVaNhanDien() {
        string anh = camera.chupAnh();
        if (anh != "") {
            auto ketQua = boNhanDien.duDoan(anh);
            cout << "Phat hien: ";
            ketQua.first.layThongTin();
            danhSachDoVatTimThay.push_back(ketQua.first);
        }
    }

    void hocDoVatMoi() {
        string ten;
        int loai;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
        cout << "Nhap ten do vat: ";
        getline(cin, ten);
        cout << "Chon loai (0:Do choi,1:Do an,2:Rac,3:Do dung): ";
        cin >> loai;
        if (loai < 0 || loai > 3) loai = KHONG_XAC_DINH;
        DoVat d(ten, (LoaiDoVat)loai, 1.0f);
        boNhanDien.themMauMoi(d);
        cout << "Da them mau: " << ten << "\n";
    }

    void baoCaoKetQua() {
        cout << "\n- Bao cao:\n";
        for (auto &d : danhSachDoVatTimThay) {
            d.layThongTin();
        }
        cout << "===================\n";
    }
};

int main() {
    RobotNhanDien robot("Robo");
    int choice;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Di chuyen robot\n";
        cout << "2. Chup anh va nhan dien\n";
        cout << "3. Day robot do vat moi\n";
        cout << "4. Bao cao ket qua\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        if(cin.fail()){ // xử lý nhập sai kiểu
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Nhap khong hop le!\n";
            continue;
        }

        switch(choice) {
            case 1: {
                int dx, dy;
                cout << "Nhap x, y: ";
                cin >> dx >> dy;
                robot.diChuyen(dx,dy);
                break;
            }
            case 2:
                robot.chupAnhVaNhanDien();
                break;
            case 3:
                robot.hocDoVatMoi();
                break;
            case 4:
                robot.baoCaoKetQua();
                break;
            case 0:
                cout << "Da dong\n";
                break;
            default:
                cout << "Lua chon khong hop le\n";
        }
    } while (choice != 0);

    return 0;
}
