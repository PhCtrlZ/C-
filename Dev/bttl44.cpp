#include <iostream>
#include <cmath>
using namespace std;

// Hàm xử lý input và kiểm tra hoán vị
void input(int n, int c) {
    int a[n + 1];     // Mảng A
    int b[n + 1];     // Mảng B
    bool used[n + 1]; // Mảng đánh dấu phần tử đã sử dụng

    // Khởi tạo mảng đánh dấu
    for (int i = 1; i <= n; i++) {
        used[i] = false;
    }

    // Nhập mảng A
    for (int i = 1; i <= n; i++) {
        a[i] = i; // Theo đề bài, A[i] là từ 1 đến n
    }

    // Xây dựng mảng B
    for (int i = 1; i <= n; i++) {
        int b1 = a[i] + c; // Trường hợp B[i] = A[i] + K
        int b2 = a[i] - c; // Trường hợp B[i] = A[i] - K

        // Ưu tiên chọn b1 nếu hợp lệ
        if (b1 >= 1 && b1 <= n && !used[b1]) {
            b[i] = b1;
            used[b1] = true;
        }
        // Nếu b1 không hợp lệ, thử chọn b2
        else if (b2 >= 1 && b2 <= n && !used[b2]) {
            b[i] = b2;
            used[b2] = true;
        }
        // Nếu không tìm được giá trị hợp lệ
        else {
            cout << -1 << endl;
            return;
        }
    }

    // In ra mảng B nếu hợp lệ
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;
    input(n, k); // Gọi hàm xử lý
    return 0;
}
