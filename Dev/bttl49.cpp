#include <iostream>
#include <vector> // Dùng std::vector

using namespace std;

void input(int a, int b);

void input(int a, int b) {
    vector<int> d(b); // Sử dụng vector để lưu mảng
    int z, e = 0;

    // Nhập các phần tử của mảng
    for (int i = 0; i < b; i++) {
        cin >> d[i];
        e += d[i];
    }

    z = d[0];
    if (e > a) {
        // Tìm giá trị bé nhất trong mảng
        for (int i = 1; i < b; i++) {
            if (z > d[i]) {
                z = d[i];
            }
        }
        cout << e - z << endl;
    } else {
        cout << e;
    }
}

int main() {
    int c, n;
    cin >> n >> c;

    // Kiểm tra điều kiện đầu vào
    if (n < 1 || n > 20 || c < 1 || c > 50000) {
        cout << "ERROR";
    } else {
        input(c, n);
    }

    return 0;
}
