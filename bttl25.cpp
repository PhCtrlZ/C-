#include <iostream>


using namespace std;

int main()

{

    char N;

    while (cin >> N) {

        if (N[0] == N[N.length() - 1]) cout << "YES" << endl;

        else cout << "NO" << endl;

    }

    return 0;
}