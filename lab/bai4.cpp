#include <iostream>
using namespace std;

class NgayThangNam {
private:
    int ngay, thang, nam;
public:
    NgayThangNam() {
        ngay = 0;
        thang = 0;
        nam = 0;
    }
    NgayThangNam(int n, int t, int y) {
        ngay = n;
        thang = t;
        nam = y;
    }
    void setNgay(int n) { ngay = n; }
    void setThang(int t) { thang = t; }
    void setNam(int y) { nam = y; }
    string tinhThu() {
        int d = ngay;
        int m = thang;
        int y = nam;
        if (m < 3) {
            m += 12;
            y -= 1;
        }
        int k = y % 100;
        int j = y / 100;
        int h = (d + (13*(m + 1))/5 + k + k/4 + j/4 + 5*j) % 7;
        string thu[] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
        return thu[h];
    }
    void xuat() {
        cout << "Ngay " << ngay << " Thang " << thang << " Nam " << nam 
             << " la " << tinhThu() << endl;
    }
};
int main() {
    NgayThangNam n1(30, 3, 2006);
    n1.xuat();
    return 0;
}
