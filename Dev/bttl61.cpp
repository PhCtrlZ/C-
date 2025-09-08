#include <iostream>
#include <sstream>
#include <cctype>
using namespace std;


void xoa(string n, string &b){
    string c;
    stringstream ss(n);
    bool d = true;
    while (ss >> c){
        if (!d) b += " ";
        b += c;
        d = false;
    }
}

void hoa(string &b) {
    bool c = true;
    for (int i = 0; i < b.length(); i++) {
        if (c && isalpha(b[i])) {
            b[i] = toupper(b[i]);
            c = false;
        } else if (b[i] == ' ') {
            c = true;
        }
    }
}

int main(){
    string n;
    string b = "";
    getline(cin, n);
    xoa(n, b);
    hoa(b);
    cout << b << endl;
    return 0;
}
