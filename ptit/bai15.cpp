#include <iostream>
#include <cmath>

using namespace std;
bool kiemtra(int n){
    int a=n;
    int sum=0;
    while(n>0){
        int d=n%10;
        sum+=pow(d,3);
        n/=10;
    }
    return sum==a;
}
int main(){
    int n;
    cout<<"nhap n:";
    cin>>n;
    if(kiemtra(n)){
        cout<<n<<" la so armstrong";
    }
    else {
        cout<<n<<" khong la so armtrong";
    }
    return 0;
}