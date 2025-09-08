#include <iostream> 
#include <string>
#include <vector>
using namespace std;



// ====== Enum ======
enum Huong { BAC, NAM, DONG, TAY };
enum TrangThai { DANG_DON, DANG_SAC, TAT, CHO };



// ====== Lp BoNhoKinhNghiem ======
class BoNhoKinhNghiem {
    private:
    int banDoNguyHiem[10][10];
    int soLanVaCham;
    vector<pair<int,int>> danhSachVaCham;


    public:
    BoNhoKinhNghiem() {
        for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
        banDoNguyHiem[i][j] = 0;
        soLanVaCham = 0;
    }



    void ghiNhoVaCham(int x, int y) {
        if (x >= 0 && x < 10 && y >= 0 && y < 10) {
            banDoNguyHiem[y][x] += 5;
            soLanVaCham++;
            danhSachVaCham.push_back({x,y});
        }
    }



    int tinhDiemAnToan(int x, int y) {
        if (x < 0 || x >= 10 || y < 0 || y >= 10) return -100;
        return 100 - banDoNguyHiem[y][x];
    }



    void thongKe() {
        cout << "So lan va cham: " << soLanVaCham << endl;
        cout << "Danh sach vi tri va cham: ";
        for (auto &p : danhSachVaCham) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
    cout << endl;
    }
};



// ====== Lp CamBienVaCham ======
class CamBienVaCham {
    public:
    bool phatHienVatCan(int phong[10][10], int x, int y) {
        if (x < 0 || x >= 10 || y < 0 || y >= 10) return true;
        return (phong[y][x] == 2);
    }
};



// ====== Lp cha: Robot ======
class Robot {
    protected:
    int viTriX, viTriY;
    Huong huong;
    float mucPin;
    TrangThai trangThai;
    string tenRobot;



    public:
    Robot(string ten = "Roomba", int x = 0, int y = 0) {
        tenRobot = ten;
        viTriX = x;
        viTriY = y;
        huong = DONG;
        mucPin = 100.0;
        trangThai = TAT;
    }



    void khoiDong() {
        trangThai = DANG_DON;
        cout << tenRobot << " bat dau don." << endl;
    }



    int getX() { 
        return viTriX; 
    }
    int getY() { 
        return viTriY; 
    }
    void setHuong(Huong h) { 
        huong = h; 
    }
    Huong getHuong() { 
        return huong; 
    }
};



// ====== Lp con: RobotHutBui ======
class RobotHutBui : public Robot {
    protected:
    int dungLuongHopBui;
    int buiHienTai;



    public:
    RobotHutBui(string ten, int x, int y) : Robot(ten, x, y) {
        dungLuongHopBui = 100;
        buiHienTai = 0;
    }



    void hutBui(int phong[10][10], int maxX, int maxY) {
        if (viTriX >= 0 && viTriX < maxX && viTriY >= 0 && viTriY < maxY) {
            if (phong[viTriY][viTriX] == 1) {
                phong[viTriY][viTriX] = 0;
                buiHienTai += 10;
                cout << tenRobot << " hut bui tai (" << viTriX << "," << viTriY << ")\n";
            }
        }
    }
};



// ====== Lp RobotHocTap ======
class RobotHocTap : public RobotHutBui {
    private:
    BoNhoKinhNghiem boNho;
    CamBienVaCham camBien;



    public:
    RobotHocTap(string ten, int x, int y) : RobotHutBui(ten, x, y) {}



    void diChuyenThongMinh(int phong[10][10]) {
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {-1, 1, 0, 0};



        int diemMax = -9999;
        int huongChon = -1;



        for (int h = 0; h < 4; h++) {
            int nx = viTriX + dx[h];
            int ny = viTriY + dy[h];



            if (camBien.phatHienVatCan(phong, nx, ny)) {
                boNho.ghiNhoVaCham(nx, ny);
                continue;
            }



            int diem = boNho.tinhDiemAnToan(nx, ny);
            if (diem > diemMax) {
                diemMax = diem;
                huongChon = h;
            }
        }



        if (huongChon != -1) {
            viTriX += dx[huongChon];
            viTriY += dy[huongChon];
            cout << tenRobot << " di chuyen den (" << viTriX << "," << viTriY << ")\n";
        } else {
            cout << tenRobot << " bi ket, khong the di tiep!\n";
        }
    }



    void thongKeKinhNghiem() {
        boNho.thongKe();
    }
};



// ====== Lp Phong ======
class Phong {
    public:
    int chieuDai, chieuRong;
    int maTranO[10][10];



    Phong(int dai, int rong) {
        chieuDai = dai;
        chieuRong = rong;
        for (int i = 0; i < chieuRong; i++) {
            for (int j = 0; j < chieuDai; j++) {
                maTranO[i][j] = 1;
            }
        }
        maTranO[2][2] = 2;
        maTranO[1][4] = 2;
        maTranO[3][3] = 2;
    }



    void hienThiBanDo() {
        for (int i = 0; i < chieuRong; i++) {
            for (int j = 0; j < chieuDai; j++) {
                if (maTranO[i][j] == 0) cout << ". ";
                else if (maTranO[i][j] == 1) cout << "* ";
                else cout << "# ";
            }
            cout << endl;
        }
    }
};



// ====== Main ======
int main() {
    Phong phong(6, 5);
    RobotHocTap robot("RoboHoc", 0, 0);



    robot.khoiDong();
    phong.hienThiBanDo();



    for (int i = 0; i < 10; i++) {
        robot.hutBui(phong.maTranO, phong.chieuDai, phong.chieuRong);
        robot.diChuyenThongMinh(phong.maTranO);
    } 



    cout << "\nSau khi di chuyen:\n";
    phong.hienThiBanDo();
    robot.thongKeKinhNghiem();



    return 0;
}
