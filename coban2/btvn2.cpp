#include <iostream>
using namespace std;

int main() {
    int n;
    do {
        cin >> n;
    } while (n <= 0);

    int S2 = 0;
    for (int i = 0; i <= n; i++) {
        S2 += 2 * i + 1;
    }
    cout<< S2 << endl;
    return 0;
}