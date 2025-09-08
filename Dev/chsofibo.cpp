#include <iostream>
#include <cmath>

using namespace std;

int f(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    return f(n-1)+f(n-2);
}
void tach(int n,int d[],int &sum){
    sum=0;
    int dem=0;
    while (n>0){
        d[dem]=n%10;
        sum+=d[dem];
        dem++;
        n/=10;
    }
}
int main(){
    int n,sum;
    int d[100];
    cin>>n;
    tach(n,d,sum);
    for (int i=0;;i++){
        int fi=f(i);
        if (sum==fi){
            cout<<"tong cac chu so n thuoc day fibo voi s="<<sum<<endl;
            break;
        }
        }
    return 0;
}