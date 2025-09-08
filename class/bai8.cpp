#include <iostream>
using namespace std;

class MayBanNuoc {
private:
    int soLuongCocaCola;
    int soLuongPepsi;
    double doanhThu;
    string mkQuanLy;

public:
    string viTriMay;

    // constructor ko tham so
    MayBanNuoc() {
        soLuongCocaCola = 0;
        soLuongPepsi = 0;
        doanhThu = 0;
        mkQuanLy = "chua xac dinh";
        viTriMay = "Chua xac dinh";
    }

    // constructor co tham so
    MayBanNuoc(int coca, int pepsi, string mk, string viTri) {
        soLuongCocaCola = coca;
        soLuongPepsi = pepsi;
        doanhThu = 0;
        mkQuanLy = mk;
        viTriMay = viTri;
    }

    // getter
    double getDoanhThu(string mk) {
        if (mk == mkQuanLy)
            return doanhThu;
        return -1;
    }

    // setter
    void setSoLuongCocaCola(int soLuong) {
        if (soLuong >= 0) {
            soLuongCocaCola = soLuong;
            cout << "Cap nhat so luong Coca Cola thanh cong!" << endl;
        } else {
            cout << "So luong phai >= 0!" << endl;
        }
    }

    void setSoLuongPepsi(int soLuong) {
        if (soLuong >= 0) {
            soLuongPepsi = soLuong;
            cout << "Cap nhat so luong Pepsi thanh cong!" << endl;
        } else {
            cout << "So luong phai >= 0!" << endl;
        }
    }

    void setMatKhauQuanLy(string mk) {
        mkQuanLy = mk;
        cout << "Cap nhat mat khau thanh cong!" << endl;
    }

    void setViTriMay(string viTri) {
        viTriMay = viTri;
        cout << "Cap nhat vi tri may thanh cong!" << endl;
    }
 
    void napHang(int coca, int pepsi) {
        if (coca > 0) soLuongCocaCola += coca;
        if (pepsi > 0) soLuongPepsi += pepsi;
        cout << "Nap hang thanh cong!" << endl;
    }

    void kiemTraTonKho() {
        cout << "Coca Cola: " << soLuongCocaCola << " chai" << endl;
        cout << "Pepsi: " << soLuongPepsi << " chai" << endl;
    }

    void banCocaCola(int soLuong, double gia) {
        if (soLuong > 0) {
            if (soLuong <= soLuongCocaCola) {
                soLuongCocaCola -= soLuong;
                doanhThu += soLuong * gia;
                cout << "Ban Coca Cola thanh cong!" << endl;
            } else
                cout << "Het Coca Cola!" << endl;
        } else {
            cout << "So luong ban ra phai lon hon 0!" << endl;
        }
    }

    void banPepsi(int soLuong, double gia) {
        if (soLuong > 0) {
            if (soLuong <= soLuongPepsi) {
                soLuongPepsi -= soLuong;
                doanhThu += soLuong * gia;
                cout << "Ban Pepsi thanh cong!" << endl;
            } else
                cout << "Het Pepsi!" << endl;
        } else {
            cout << "So luong ban ra phai lon hon 0!" << endl;
        }
    }
};

int main() {
    MayBanNuoc mayBan;
    string vitri, mk;
    int coca, pepsi, napcoca, nappepsi;
    double giacc, giapp;

    cout << "Nhap vi tri may ban nuoc: ";
    getline(cin, vitri);

    cout << "Nhap so luong Coca Cola ban dau: ";
    cin >> coca;
    cout << "Nhap so luong Pepsi ban dau: ";
    cin >> pepsi;

    cout << "Nhap gia Coca Cola: ";
    cin >> giacc;
    cout << "Nhap gia Pepsi: ";
    cin >> giapp;

    cin.ignore(); 
    cout << "Nhap mat khau quan ly: ";
    getline(cin, mk);

    mayBan.setSoLuongCocaCola(coca);
    mayBan.setSoLuongPepsi(pepsi);
    mayBan.setMatKhauQuanLy(mk);
    mayBan.setViTriMay(vitri);

    cout << "Nhap so luong Coca Cola can mua: ";
    cin >> coca;
    mayBan.banCocaCola(coca, giacc);

    cout << "Nhap so luong Pepsi can mua: ";
    cin >> pepsi;
    mayBan.banPepsi(pepsi, giapp);

    cout << "Kiem tra hang ton kho!" << endl;
    mayBan.kiemTraTonKho();

    cout << "Nhap so luong Coca Cola can nap them: ";
    cin >> napcoca;
    cout << "Nhap so luong Pepsi can nap them: ";
    cin >> nappepsi;
    mayBan.napHang(napcoca, nappepsi);

    cout << "Kiem tra hang ton kho sau khi ban ra!" << endl;
    mayBan.kiemTraTonKho();

    cin.ignore();
    cout << "Nhap mat khau quan ly de xem doanh thu: ";
    getline(cin, mk);
    double dt = mayBan.getDoanhThu(mk);
    if (dt != -1) {
        cout << "Doanh thu hien tai: " << dt << endl;
    } else {
        cout << "Mat khau khong dung!" << endl;
    }

    return 0;
}
