#include <iostream>
using namespace std;

int main() {
    string s1, s2, result;
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s1.length(); ) {
        // Kiểm tra nếu từ vị trí i có chuỗi con bằng s2
        if (s1.substr(i, s2.length()) == s2) {
            i += s2.length(); // Bỏ qua chuỗi con này
        } else {
            result += s1[i];
            i++;
        }
    }
    cout << result << endl;
    return 0;
}