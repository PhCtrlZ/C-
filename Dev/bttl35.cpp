#include <iostream>

using namespace std;


void tinhTongChuSo(int n) {
    int tong = 0;
    while (n > 0) {
        tong += n % 10;  
        n /= 10;         
    }
    cout << tong << endl;  
}

int main() {
    int n;
    cin >> n;

    int A[n];  
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < n; i++) {
        tinhTongChuSo(A[i]);  
    }

    return 0;
}
