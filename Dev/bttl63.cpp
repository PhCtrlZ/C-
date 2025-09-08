#include <iostream>

using namespace std;
int  tach(int n) {
    int dem=0;
        int a = n % 10;
        if (a==2 || a==3 ||a==9){
        return true;
    }
    return false;
    }

int main() {
    int n,b;
    int dem=0;
    cout<<"nhap diem ban dau"<<endl;
    
    cin>>b;
    cout<<"nhap diem ket thuc"<<endl;
    cin >> n;
    for (int i = b; i <= n; i++) {
        if(tach(i)==true){
            dem++;
        }
        
    }
    cout<<dem<<endl;
    return 0;
}