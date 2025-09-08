#include <iostream>

using namespace std;

struct sinhvien{
    string hoten;
    float tbhk1;
    float tbhk2;
};
int main(){
    sinhvien sv;
    getline(cin, sv.hoten);
    cin>>sv.tbhk1>>sv.tbhk2;
    float tb=(sv.tbhk1+(sv.tbhk2*2))/3;
    cout<<sv.hoten<<endl;
    cout<<tb<<endl;
    return 0;
}