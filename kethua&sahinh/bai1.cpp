#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;


enum Huong { BAC, NAM, DONG, TAY };
enum TrangThai { DANG_DON, DANG_SAC, TAT, CHO };
enum CheDo { ECO, NORMAL, TURBO };


class Phong {
    public:
    int chieuDai, chieuRong;
    vector<vector<char>> maTranO;
    pair<int,int> viTriTramSac;
    int soOBan;
    int soVatCan;


    Phong(int dai, int rong) {
        chieuDai = dai;
        chieuRong = rong;
        maTranO.assign(dai, vector<char>(rong, '.'));
        soOBan = 0;
        soVatCan = 0;
        viTriTramSac = {-1, -1}; 
    }


    void datVatCan(int x, int y) {
        if (kiemTraHopLe(x,y) && maTranO[x][y] == '.') {
            maTranO[x][y] = '#';
            soVatCan++;
        }
    }


    void datBui(int x, int y) {
        if (kiemTraHopLe(x,y) && maTranO[x][y]=='.') {
            maTranO[x][y] = '*';
            soOBan++;
        }
    }


    void datTramSac(int x, int y) {
        if (kiemTraHopLe(x,y)) { 
            viTriTramSac = {x,y};
            maTranO[x][y] = 'S';
        }
    }


    bool kiemTraHopLe(int x, int y) {
        return (x>=0 && x<chieuDai && y>=0 && y<chieuRong);
    }


    void lamSachO(int x, int y) {
        if (kiemTraHopLe(x,y) && maTranO[x][y] == '*') { 
            maTranO[x][y] = '.';
            soOBan--;
        }
    }


    void hienThiBanDo(pair<int,int> robotPos) {


        cout << "\033[2J\033[H"; 
    for (int i=0;i<chieuDai;i++) {
        for (int j=0;j<chieuRong;j++) {
            if (i==robotPos.first && j==robotPos.second) cout << "R ";
            else cout << maTranO[i][j] << " ";
        }
        cout << endl;
    }
    cout << "So o ban con lai: " << soOBan << endl;
    cout << endl;
}
};


class TramSac {
    public:
    int viTriX, viTriY;
    bool dangSac;
    float tocDoSac;


    TramSac(int x, int y) {
        viTriX = x; viTriY = y;
        dangSac = false;
        tocDoSac = 1.0;
    }


    void batDauSac(float &pin) {
        dangSac = true;
        cout << "Dang sac pin...\n";
        while (pin < 100) {
            pin += tocDoSac;
            if (pin > 100) pin = 100; 
            this_thread::sleep_for(chrono::milliseconds(50));
        }
        dangSac = false;
        cout << "Sac pin hoan thanh!\n";
    }
};


class Robot {
    public:
    int viTriX, viTriY;
    Huong huong;
    float mucPin;
    TrangThai trangThai;
    int tocDoDiChuyen;
    string tenRobot;
    vector<pair<int,int>> lichSuDiChuyen;


    Robot(string ten, int x, int y) {
        tenRobot = ten;
        viTriX = x; viTriY = y;
        huong = BAC;
        mucPin = 100;
        trangThai = CHO;
        tocDoDiChuyen = 1;
    }


    virtual void diChuyenToi(int x, int y, Phong &p) {
        if (p.kiemTraHopLe(x,y) && p.maTranO[x][y] != '#') {
            viTriX = x; viTriY = y;
            lichSuDiChuyen.push_back({x,y});
            mucPin -= 0.2;
            if (mucPin < 0) mucPin = 0; 
        }
    }


    void tiepTuc(Phong &p) {
        int nx=viTriX, ny=viTriY;
        if (huong==BAC) nx--;
        else if (huong==NAM) nx++;
        else if (huong==DONG) ny++;
        else ny--;
        if (p.kiemTraHopLe(nx,ny) && p.maTranO[nx][ny] != '#') {
            diChuyenToi(nx,ny,p);
        }
    }
    void quayTrai() { huong = (Huong)((huong+3)%4); }
    void quayPhai() { huong = (Huong)((huong+1)%4); }
    void quay180() { huong = (Huong)((huong+2)%4); }


    float kiemTraPin() { return mucPin; }
    pair<int,int> layViTri() { return {viTriX,viTriY}; }
};


class RobotHutBui : public Robot {
    public:
    int dungLuongHopBui;
    int buiHienTai;
    int soODaDon;
    int congSuatHut;
    CheDo cheDoLamViec;
    bool coSensorBui;
    int thoiGianDon;


    RobotHutBui(string ten, int x, int y)
    : Robot(ten,x,y) {
        dungLuongHopBui = 100;
        buiHienTai = 0;
        soODaDon = 0;
        congSuatHut = 20;
        cheDoLamViec = NORMAL;
        coSensorBui = true;
        thoiGianDon = 0;
    }


    void hutBui(Phong &p) {
        if (p.maTranO[viTriX][viTriY] == '*') {
            buiHienTai += 10;
            soODaDon++;
            p.lamSachO(viTriX,viTriY);
            thoiGianDon++; 
        }
    }


    void baoCaoDonDep() {
        cout << "===== Bang bao cao =====\n";
        cout << "Ten robot: " << tenRobot << endl;
        cout << "So o bui da don: " << soODaDon << endl;
        cout << "Tong thoi gian: " << thoiGianDon << " giay\n";
        cout << "Pin con lai: " << mucPin << "%\n";
        cout << "Bui trong hop: " << buiHienTai << "/" << dungLuongHopBui << endl;
        cout << "==========================\n";
    }
};


int main() {
    srand(time(0));
    Phong phong(10,10);
    phong.datTramSac(0,0);


    // To vt cn v bi mt cch an ton hn
    int vatCanDaDat = 0, buiDaDat = 0;
    int dem = 0;


    // t vt cn
    while (vatCanDaDat < 15 && dem < 100) {
        int x = rand() % 10, y = rand() % 10;
        if (phong.maTranO[x][y] == '.') {
            phong.datVatCan(x, y);
            vatCanDaDat++;
        }
        dem++;
    }


    // t bi
    dem = 0;
    while (buiDaDat < 25 && dem < 100) {
        int x = rand() % 10, y = rand() % 10;
        if (phong.maTranO[x][y] == '.') {
            phong.datBui(x, y);
            buiDaDat++;
        }
        dem++;
    }


    RobotHutBui robot("Roomba", 0, 0);


    cout << "Bat dau don dep...\n";
    this_thread::sleep_for(chrono::milliseconds(1000));


    // Thut ton dn dp theo mu zigzag
    for (int i = 0; i < phong.chieuDai; i++) {
        if (robot.kiemTraPin() <= 10) {
            cout << "Pin yeu, dung lai!\n";
            break;
        }


        if (i % 2 == 0) {
            // Di chuyn t tri qua phi
            for (int j = 0; j < phong.chieuRong; j++) {
                if (phong.kiemTraHopLe(i, j) && phong.maTranO[i][j] != '#') {
                    robot.diChuyenToi(i, j, phong);
                    robot.hutBui(phong);
                    phong.hienThiBanDo(robot.layViTri());


                    cout << "Pin: " << robot.kiemTraPin() << "% | ";
                    cout << "Bui da don: " << robot.soODaDon << endl;


                    this_thread::sleep_for(chrono::milliseconds(150));
                }
            }
        } else {
            // Di chuyn t phi qua tri
            for (int j = phong.chieuRong - 1; j >= 0; j--) {
                if (phong.kiemTraHopLe(i, j) && phong.maTranO[i][j] != '#') {
                    robot.diChuyenToi(i, j, phong);
                    robot.hutBui(phong);
                    phong.hienThiBanDo(robot.layViTri());


                    cout << "Pin: " << robot.kiemTraPin() << "% | ";
                    cout << "Bui da don: " << robot.soODaDon << endl;


                    this_thread::sleep_for(chrono::milliseconds(150));
                }
            }
        }
    }


    robot.baoCaoDonDep();


    cout << "\nNhan Enter de thoat...";
    cin.get();
    return 0;
}
