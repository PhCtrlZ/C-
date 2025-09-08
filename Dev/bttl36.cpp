#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


void tinhTongSn(int n) {
    double S = 1.0;
    double tong = 1.0;  

    for (int i = 2; i <= n; i++) {
        tong += i;        
        S += 1.0 / tong;   
    }

    cout << fixed << setprecision(8) << S << endl;
}

int main() {
    int T;
    cin >> T;

    if (T <= 0 || T > pow(10, 5)) {
        cout << "ERROR" << endl;
        return 0;
    }

    int* A = new int[T];  
    for (int i = 0; i < T; i++) {
        cin >> A[i];
        if (A[i] < 1 || A[i] > 1000000) {  
            cout << "ERROR" << endl;
            delete[] A;
            return 0;
        }
    }

    for (int i = 0; i < T; i++) {
        tinhTongSn(A[i]);  
    }

    delete[] A;  
    return 0;
}
