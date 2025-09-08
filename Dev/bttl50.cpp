#include <iostream>

using namespace std;

int main() {
    int a, b;


    cin >> a;
    cin >> b;

    // Khởi tạo mảng hai chiều
    int arr[a][b];

    // Nhập mảng hai chiều
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> arr[i][j];
        }
    }

    // In ra mảng hai chiều
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout<<endl;
    return 0;
}
