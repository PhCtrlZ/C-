#include <iostream>

using namespace std;
int gt(int n){
    int s=1;
    for (int i=1;i<=n;i++){
        s*=i;
    }
    return s;
}
int strong(int n){
    int a=n;
    int sum=0;
    while(n>0){
        int d=n%10;
        sum+=gt(d);
        n/=10;
    }
    return sum==a;
}
int main(){
    int n;
    cout<<"nhap n:";
    cin>>n;
    if(strong(n)){
        cout<<n<<" la so strong";
    }
    else {
        cout<<n<<" ko la so strong";
    }
}