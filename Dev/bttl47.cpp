#include <iostream>
using namespace std;

int main() { 
    long long n;
cin >> n;


long long l = 0, c = 0;

while (n > 0) {
    int d = n % 10;
    if (d % 2 == 0) {
        l += d;
    } else {
        c += d;
    }
    n /= 10;
}

cout << l << endl;
cout << c << endl;

return 0;
}
