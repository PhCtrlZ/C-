#include <iostream>
using namespace std;

// Hàm tìm số nhỏ nhất có thể đạt được trong quá trình biến đổi
int findMinNumber(int n) {
    while (true) {
        int lastDigit = n % 10;  // Tách chữ số hàng đơn vị
        n += lastDigit;          // Cộng chữ số hàng đơn vị vào n
        if (n % 10 == 0)         // Nếu n chia hết cho 10 (chẵn chục), dừng quá trình
            break;
        n /= 10;                 // Chia n cho 10 và gán lại cho n
    }
    return n;  // Trả về kết quả nhỏ nhất tìm được
}

int main() {
    int n;
    cout << "Nhập số nguyên dương n: ";
    cin >> n;

    int minNumber = findMinNumber(n);
    cout << "Số nhỏ nhất nhận được trong quá trình biến đổi là: " << minNumber << endl;

    return 0;
}
