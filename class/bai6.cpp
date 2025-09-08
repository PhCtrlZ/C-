#include <iostream>
using namespace std;

class Robot {
private:
    int toaDoX;
    int toaDoY;
    int pin;
public:
    string tenRobot;
    // constructor ko tham so
    Robot() {
        toaDoX = 0;
        toaDoY = 0;
        pin = 0;
        tenRobot = "Ten robot khong xac dinh!";
    }
    // constructor co tham so
    Robot(int x, int y, int p, string ten) {
        toaDoX = x;
        toaDoY = y;
        pin = p;
        tenRobot = ten;
    }
    // getter
    int getX() const   { 
        return toaDoX;
    }
    int getY() const { 
        return toaDoY; 
    }
    int getPin() const { 
        return this->pin; 
    }
    // setter
    void setX(int x) { 
        if (x>=0&&x<=100){
            toaDoX = x; 
        }else{
            cout<<"Gia tri toa do X khong hop le!"<<endl;
        }
    }
    void setY(int y) { 
        if (y>=0 && y<=100){
            toaDoY = y; 
        }else{
            cout<<"Gia tri toa do Y khong hop le!"<<endl;
        }
    }
    void setPin(int p) {
        if (p >= 0 && p <= 100) {
            pin = p;
        } else {
            cout << "Gia tri pin khong hop le!" << endl;
        }
    }

    void diChuyenLen(int buoc) {
        if (pin > 0) {
            toaDoY += buoc;
            pin--;
            cout << "Robot da di chuyen len den toa do: " << toaDoX << "," << toaDoY << endl;
        } else {
            cout << "Khong du pin de di chuyen!" << endl;
        }
    }

    void diChuyenXuong(int buoc) {
        if (pin > 0) {
            toaDoY -= buoc;
            pin--;
            cout << "Robot da di chuyen xuong den toa do: " << toaDoX << "," << toaDoY << endl;
        } else {
            cout << "Khong du pin de di chuyen!" << endl;
        }
    }

    void diChuyenTrai(int buoc) {
        if (pin > 0) {
            toaDoX -= buoc;
            pin--;
            cout << "Robot da di chuyen trai den toa do: " << toaDoX << "," << toaDoY << endl;
        } else {
            cout << "Khong du pin de di chuyen!" << endl;
        }
    }

    void diChuyenPhai(int buoc) {
        if (pin > 0) {
            toaDoX += buoc;
            pin--;
            cout << "Robot da di chuyen phai den toa do: " << toaDoX << "," << toaDoY << endl;
        } else {
            cout << "Khong du pin de di chuyen!" << endl;
        }
    }

    void sacPin(int luongPin) {
        if (luongPin > 0 && luongPin <= 100) {
            pin = 100;
            cout << "Pin da duoc sac den: " << pin << "%" << endl;
        }
    }
};

int main() {
    Robot robot1;
    string ten;
    int x, y, p;
    cout << "Nhap ten robot: ";
    getline(cin, ten);
    cout << "Nhap toa do X: ";
    cin >> x;
    cout << "Nhap toa do Y: ";
    cin >> y;
    cout << "Nhap luong pin (0-100): ";
    cin >> p;

    robot1.tenRobot = ten;
    robot1.setX(x);
    robot1.setY(y);
    robot1.setPin(p);

    cout << "\nThong tin robot" << endl;
    cout << "Ten robot: " << robot1.tenRobot << endl;
    cout << "Toa do X: " << robot1.getX() << endl;
    cout << "Toa do Y: " << robot1.getY() << endl;
    cout << "Pin: " << robot1.getPin() << "%" << endl;

    robot1.diChuyenLen(x);
    robot1.diChuyenPhai(y);

    cout << "\nThong tin robot sau khi chuyen" << endl;
    cout << "Ten robot: " << robot1.tenRobot << endl;
    cout << "Toa do X: " << robot1.getX() << endl;
    cout << "Toa do Y: " << robot1.getY() << endl;
    cout << "Pin: " << robot1.getPin() << "%" << endl;

    robot1.sacPin(100);
    cout << "Pin sau khi sac: " << robot1.getPin() << "%" << endl;
    return 0;
}
