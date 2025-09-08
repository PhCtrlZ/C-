#include <iostream>
#include <string>
using namespace std;

int main(){
    string hoten;
    int toan;
    int van;
    float dtb;
    getline(cin,hoten);
    cin>>toan;
    cin>>van;
    cout<<"ho ten "<<hoten<<endl;
    cout<<"diem toan"<<toan<<endl;
    cout<<"diem van"<<van<<endl;
    dtb=(van+toan)/2;
    cout<<"diem tb:"<<dtb<<endl;

}
