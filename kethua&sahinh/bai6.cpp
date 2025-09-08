#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

enum Huong{Len, Xuong, Trai, Phai};

class GameState{
    public:
    int toadoX, toadoY;
    int dotX[100], dotY[100];
    int taX, taY; 
    int dauX, dauY; 
    double Diem;
    int hang, cot;
    int length; 
    
    GameState(int hangx=10, int coty=10){
        hang = hangx;
        cot = coty;
        length = 1;
        Diem = 0;
        dauX = hang / 2;
        dauY = cot / 2;
        dotX[0] = dauX;
        dotY[0] = dauY;
        taoThucAn();
    }

    void taoThucAn(){
        do {
            taX = rand() % hang;
            taY = rand() % cot;
        } while (cham(taX, taY)); 
    }
    
    bool cham(int x, int y){
        if (x < 0 || x >= hang || y < 0 || y >= cot) return true;
        for (int i = 0; i < length; i++)
            if (dotX[i] == x && dotY[i] == y) return true;
        return false;
    }
    
    void diChuyen(Huong huong){

        for (int i = length; i > 0; i--){
            dotX[i] = dotX[i-1];
            dotY[i] = dotY[i-1];
        }
        

        if(huong == Len) dauY--;
        if(huong == Xuong) dauY++;
        if(huong == Trai) dauX--;
        if(huong == Phai) dauX++;
        
        dotX[0] = dauX;
        dotY[0] = dauY;
        

        if (dauX == taX && dauY == taY){
            Diem++;
            length++;
            taoThucAn();
        }
    }
    
    void inBanCo(){
        cout << "\n=== BAN CO ===" << endl;
        for (int i = 0; i < hang; i++){
            for (int j = 0; j < cot; j++){
                bool isSnake = false;
                bool isHead = false;
                

                if (i == dauX && j == dauY){
                    cout << "O "; 
                    isSnake = true;
                    isHead = true;
                }
                

                if (!isHead){
                    for (int k = 0; k < length; k++){
                        if (dotX[k] == i && dotY[k] == j){
                            cout << "o "; 
                            isSnake = true;
                            break;
                        }
                    }
                }
                

                if (!isSnake && i == taX && j == taY){
                    cout << "* "; 
                }
                else if (!isSnake){
                    cout << ". "; 
                }
            }
            cout << endl;
        }
        cout << "Diem: " << Diem << " | Do dai: " << length << endl;
    }
    
    string tenHuong(Huong h){
        switch(h){
            case Len: return "LEN";
            case Xuong: return "XUONG";
            case Trai: return "TRAI";
            case Phai: return "PHAI";
            default: return "KHONG XAC DINH";
        }
    }
};

class ChienLuoc{
    public:
    virtual Huong chonHuong(GameState &state) = 0;
};

class ChienLuocRandom : public ChienLuoc{
    public:
    Huong chonHuong(GameState &state){
        return (Huong)(rand() % 4);
    }
};

class ChienLuocThamLam : public ChienLuoc{
    public:
    Huong chonHuong(GameState &state){
        if (abs(state.dauX - state.taX) > abs(state.dauY - state.taY)){
            return (state.dauX > state.taX) ? Trai : Phai;
        } else {
            return (state.dauY > state.taY) ? Len : Xuong;
        }
    }
};

class DanhGiaNuocDi{
    public:
    int danhGia(GameState &state, Huong huong){
        int nx = state.dauX, ny = state.dauY;
        if (huong == Len) ny--;
        if (huong == Xuong) ny++;
        if (huong == Trai) nx--;
        if (huong == Phai) nx++;
        
        if (state.cham(nx, ny)) return -1000;
        
        int kc = abs(nx - state.taX) + abs(ny - state.taY);
        return -kc;
    }
    
    Huong huongChonThongMinh(GameState &state){
        int totNhat = -9999;
        Huong huongTot = Len;
        
        for (int d = 0; d < 4; d++){
            int diem = danhGia(state, (Huong)d);
            if (diem > totNhat){
                totNhat = diem;
                huongTot = (Huong)d;
            }
        }
        return huongTot; 
    }
};

class RobotChoiGame{
    public:
    ChienLuoc *chienLuoc;
    int diemCao;
    
    RobotChoiGame(ChienLuoc *c){
        chienLuoc = c;
        diemCao = 0;
    }
    
    void choi(GameState &state){
        Huong huong = chienLuoc->chonHuong(state);
        state.diChuyen(huong);
        if (state.Diem > diemCao) diemCao = state.Diem;
    }
};

int main() {
    srand(time(0));
    GameState game(10, 10); 
    DanhGiaNuocDi danhgia;
    
    cout << "=== GAME RAN - IN TUNG BUOC DI CHUYEN ===" << endl;
    cout << "Trang thai ban dau:" << endl;
    game.inBanCo();
    
    for (int buoc = 1; buoc <= 20; buoc++){
        cout << "\n" << string(50, '=') << endl;
        cout << "BUOC " << buoc << ":" << endl;

        if (game.cham(game.dauX, game.dauY)){
            cout << "GAME OVER! Ran da cham vao tuong hoac than minh!" << endl;
            break;
        }
        

        Huong huong = danhgia.huongChonThongMinh(game);
        
        cout << "Vi tri hien tai: Dau(" << game.dauX << "," << game.dauY << ")" << endl;
        cout << "Thuc an tai: (" << game.taX << "," << game.taY << ")" << endl;
        cout << "Huong di chuyen: " << game.tenHuong(huong) << endl;
        
        // Di chuyển
        game.diChuyen(huong);
        
        cout << "Vi tri moi: Dau(" << game.dauX << "," << game.dauY << ")" << endl;
        cout << "Diem: " << game.Diem << " | Do dai ran: " << game.length << endl;
        

        game.inBanCo();
        

        if (game.cham(game.dauX, game.dauY)){
            cout << "\nGAME OVER! Ran da cham vao tuong hoac than minh!" << endl;
            break;
        }
        

    }
    
    cout << "\n=== KET THUC GAME ===" << endl;
    cout << "Diem cuoi cung: " << game.Diem << endl;
    cout << "Do dai ran cuoi cung: " << game.length << endl;
    
    return 0;
}