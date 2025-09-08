#include <iostream> 
#include <vector>
#include <string>
using namespace std;


class HinhVe {
private:
string loai;
int x, y;
double kichthuoc;
string mausac;
public:
HinhVe(string l, int a, int b, double kt, string m) {
loai = l; x = a; y = b; kichthuoc = kt; mausac = m;
}
string getLoai() { return loai; }
void hienThi() {
cout << "Hinh: " << loai 
<< ", Toa do: (" << x << "," << y << ")"
<< ", Kich thuoc: " << kichthuoc
<< ", Mau: " << mausac << endl;
}
};


class CanhTayRobot {
private:
int x, y, z;
double gocxoay;
double lucnhan;
public:
CanhTayRobot() { x = y = z = 0; gocxoay = 0; lucnhan = 1.0; }


void diChuyenDen(int a, int b, int c) {
x = a; y = b; z = c;
cout << " Di chuyen den vi tri (" << x << "," << y << "," << z << ")\n";
}
void haBut() { cout << " Ha but xuong\n"; }
void nangBut() { cout << " Nang but len\n"; }
void dieuChinhLuc(double l) { 
lucnhan = l; 
cout << " Luc nhan thay doi thanh: " << lucnhan << endl;
}
};


class KeHoachVe {
private:
vector<HinhVe> danhSachHinh;
double tocdo;
public:
KeHoachVe() { tocdo = 1.0; }
void themHinh(HinhVe h) { danhSachHinh.push_back(h); }
void hienThiKeHoach() {
cout << "\n Ke hoach ve gom " << danhSachHinh.size() << " hinh:\n";
for (int i = 0; i < danhSachHinh.size(); i++) {
cout << (i+1) << ". ";
danhSachHinh[i].hienThi();
}
}
vector<HinhVe> getDanhSach() { return danhSachHinh; }


// Gi lp chia hnh phc tp thnh nt n gin
void toiUuHoa() {
cout << " Dang toi uu hoa ke hoach ve...\n";
for (int i = 0; i < danhSachHinh.size(); i++) {
cout << "- Hinh '" << danhSachHinh[i].getLoai() << "' duoc chia thanh cac net don gian.\n";
}
}
};


class RobotVeTranh {
private:
CanhTayRobot canhtay;
public:
void veHinh(HinhVe h) {
cout << "\n Robot bat dau ve: ";
h.hienThi();
canhtay.haBut();
canhtay.diChuyenDen(5, 5, 0);
canhtay.nangBut();
}
void veTuKeHoach(KeHoachVe &kehoach) {
cout << "\n Robot thuc hien ke hoach ve...\n";
vector<HinhVe> ds = kehoach.getDanhSach();
for (auto &h : ds) {
veHinh(h);
}
}
// K nng nng cao
void toMau(string mau) {
cout << " Robot to mau: " << mau << endl;
}
void veChu(string text) {
cout << " Robot viet chu: \"" << text << "\"\n";
}
void copyTranh(string tenMau) {
cout << " Robot copy tranh mau: " << tenMau << endl;
}
};


class HocVeTranh {
private:
int ngay;
public:
HocVeTranh() { ngay = 0; }
void tienBo(int soNgay) {
ngay += soNgay;
cout << " Robot da hoc them " << soNgay << " ngay.\n";
}
void xemTienDo() {
cout << "\n Tien do hoc ve (ngay " << ngay << "):\n";
if (ngay < 1) {
cout << "- Chua bat dau hoc\n";
} else if (ngay < 7) {
cout << "- Ve duoc duong thang nghieng, cong\n";
} else if (ngay < 30) {
cout << "- Ve duoc hinh tron tuong doi\n";
} else if (ngay < 100) {
cout << "- Ve duoc khuon mat don gian\n";
} else {
cout << "- Ve duoc tranh phong canh co ban\n";
}
}
// M phng qu trnh hc t mu
void hocTuMau(string tenMau) {
cout << "\n Qua trinh hoc tu mau: " << tenMau << endl;
cout << "1. Xem mau\n";
cout << "2. Phan tich mau thanh net ve\n";
cout << "3. Thu ve\n";
cout << "4. So sanh voi mau\n";
cout << "5. Dieu chinh va cai thien\n";
}
};


int main() {
RobotVeTranh robot;
HocVeTranh hoc;
KeHoachVe kehoach;


int chon;
do {
cout << "\n=== Bang dieu khien Robot ===\n";
cout << "1. Them hinh ve vao ke hoach\n";
cout << "2. Xem ke hoach ve\n";
cout << "3. Toi uu hoa ke hoach ve\n";
cout << "4. Robot thuc hien ke hoach ve\n";
cout << "5. To mau\n";
cout << "6. Ve chu\n";
cout << "7. Copy tranh mau\n";
cout << "8. Hoc ve (tien bo them X ngay)\n";
cout << "9. Xem tien do hoc\n";
cout << "10. Hoc tu mau\n";
cout << "0. Thoat\n";
cout << "Chon: ";
cin >> chon;


if (chon == 1) {
string loai, mausac;
int x, y; double kt;
cout << "Nhap loai hinh (duong, tron, vuong): "; cin >> loai;
cout << "Nhap toa do (x y): "; cin >> x >> y;
cout << "Nhap kich thuoc: "; cin >> kt;
cout << "Nhap mau sac: "; cin >> mausac;
HinhVe h(loai, x, y, kt, mausac);
kehoach.themHinh(h);
cout << " Da them hinh vao ke hoach\n";
}
else if (chon == 2) kehoach.hienThiKeHoach();
else if (chon == 3) kehoach.toiUuHoa();
else if (chon == 4) robot.veTuKeHoach(kehoach);
else if (chon == 5) {
string mau; cout << "Nhap mau muon to: "; cin >> mau;
robot.toMau(mau);
}
else if (chon == 6) {
string text; cout << "Nhap chu muon ve: ";
cin.ignore();
getline(cin, text);
robot.veChu(text);
}
else if (chon == 7) {
string ten; cout << "Nhap ten tranh mau: ";
cin.ignore();
getline(cin, ten);
robot.copyTranh(ten);
}
else if (chon == 8) {
int n;
cout << "Nhap so ngay hoc them: "; cin >> n;
if (n > 0) hoc.tienBo(n);
else cout << "So ngay phai > 0\n";
}
else if (chon == 9) hoc.xemTienDo();
else if (chon == 10) {
string ten; cout << "Nhap ten mau: ";
cin.ignore();
getline(cin, ten);
hoc.hocTuMau(ten);
}


} while (chon != 0);


cout << "Da thoat\n";
return 0;
}