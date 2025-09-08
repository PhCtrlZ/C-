#include <iostream>
int fibo(int n){
    if(n==0) return 1;
    if(n==1) return 1;
    return fibo(n-1)+fibo(n-2);
}
using namespace std;
int main(){
    int n;
    cin>>n;
    fibo(n);
    for (int i=0; i<n; i++){
        cout<<fibo(i)<<endl;
    }
    return 0;
}