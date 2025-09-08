#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cout<<"nhap bien so xe:";
    getline(cin,s);

    int tong=0;
    for (int i=0;i< s.length();i++){
        if (s[i]>='0' && s[i]<='9'){
            tong+=s[i]-'0';// chuyển ký tự chuỗi về số nguyên
        }
    }
    int a=tong%10;
    cout<<"so nut cua bien so la :"<<a<<endl;
    return 0;
}