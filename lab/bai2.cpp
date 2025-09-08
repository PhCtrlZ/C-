#include <iostream>
using namespace std;

class TaiKhoan {
private:
    string tenTaiKhoan;
    int soTaiKhoan;
    double soDu;
public:
    TaiKhoan() {
        tenTaiKhoan = "Chua xac dinh";
        soTaiKhoan = 0;
        soDu = 0;
    }
    TaiKhoan(string ten, int stk, double sd) {
        tenTaiKhoan = ten;
        soTaiKhoan = stk;
        soDu = sd;
    }
    int getsoTaiKhoan() {
        return soTaiKhoan;
    }
    double getSoDu() {
        return soDu;
    }
    string getTenTaiKhoan() {
        return tenTaiKhoan;
    }
    void setStk(int stk) {
        soTaiKhoan = stk;
    }
    void setSd(double sd) {
        if (sd < 0) {
            cout << "So du khong the be hon 0!" << endl;
        } else {
            soDu = sd;
        }
    }
    void setTen(string ten) {
        tenTaiKhoan = ten;
    }
    void napTien(double nap) {
        if (nap > 0) {
            soDu += nap;
            cout << "So du sau khi nap la: " << soDu << endl;
        }
    }
    void rutTien(double rut) {
        if (rut + 2000 > soDu) {
            cout << "Khong du tien de rut!" << endl;
        } else {
            soDu -= (rut + 2000);
            cout << "So du con lai: " << soDu << endl;
        }
    }
    void chuyenKhoan(int soTien, int taikhoan) {
        if (soTien > soDu) {
            cout << "Khong du tien de chuyen khoan!" << endl;
        } else {
            soDu -= soTien;
            cout << "Da chuyen " << soTien << " cho so tai khoan " << taikhoan << endl;
            cout << "So du con lai: " << soDu << endl;
        }
    }
};

int main() {
    TaiKhoan tk("Phuc", 12345, 10000);
    tk.napTien(5000);
    tk.rutTien(2000);
    tk.chuyenKhoan(3000, 67890);
    return 0;
}
