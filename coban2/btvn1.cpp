#include <iostream>
using namespace std;

int main(){
    char n;
    cin>>n;
    switch(n){
        case 'A':
            cout<<"Sinh vien xuat sac"<<endl;
            break;
        case 'B':
            cout<<"Sinh vien loai gioi"<<endl;
            break;
        case 'C':
            cout<<"Sinh vien loai kha"<<endl;
            break;
        case 'D':
            cout<<"Sinh vien loai trung binh"<<endl;
            break;
        case 'F':
            cout<<"Sinh vien loai kem"<<endl;
            break;
    }
    return 0;
}