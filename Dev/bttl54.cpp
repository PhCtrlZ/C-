#include <iostream>
#include <cstring>
#include <cctype> 
#include <math.h>

using namespace std;

int main()
{
    string a, e = "";
    char b[100];
    int c = 0, d = 0;
    cin >> a;


    for (int i = 0; i < a.length(); i++) {
        b[c] = a[i];
        c++;
    }


    for (int i = 0; i < a.length(); i++) {
        if (b[i] >= 'A' && b[i] <= 'Z') {
     
            if (b[i] == b[i + 1]) {
                i += 2; d+=1;
            }
            else {
                d += 1; 
            }
        }
        else if (b[i] >= '0' && b[i] <= '9') {
            for (char c : a) {
                if (!isdigit(c)) {
                    e += c; 
                }
            }
        }
    }

    cout << "Chuoi sau khi bien doi la: " << e <<d<< endl;
    return 0;
}
