#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
    int n, m, k, q;
    float res;

    cin >> n >> m;
    if (n >= 1 && m < pow(10, 9))
    {
        k = n / m;
        res = n / m;
        q = n % m;
        cout << k << endl;
        cout << q << endl;
        cout << fixed << setprecision(2) << res;
    }
    else
        cout << "error code";
}
