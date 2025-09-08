#include <iostream>
#include <string>
using namespace std;

struct hocsinh {
    string ten;
    float toan;
    float van;
    float tb;
};

int main(){
    hocsinh hs;
    cout << "Nhap ten hoc sinh: "<<endl;;
    getline(cin, hs.ten);
    cout << "Nhap diem toan: "<<endl;;
    cin>>hs.toan;
    cout<<"nhap diem van:"<<endl;
    cin>>hs.van;
    hs.tb=(hs.toan+hs.van)/2;
    cout<<"ho ten hoc sinh:"<<hs.ten<<endl;
    cout<<"diem toan"<<hs.toan<<endl;
    cout<<"diem van:"<<hs.van<<endl;
    cout<<"diem trung binh:"<<hs.tb<<endl;
    return 0;

}