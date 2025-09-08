#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, b,t;
    int dem=0;
    cin>>t;
    if (t<pow(10,5)){
    while(t--){
    cin >> b;
    cin >> n;
    if (b>1&&n<=pow(10,7)){
    for (int i = b; i <= n; i++) {
         int a=i%10;
         if (a == 2 || a == 3 || a == 9) {
            dem++;  
        }
    }
}
    cout << dem << endl;
    
        }
    }
    return 0;
}