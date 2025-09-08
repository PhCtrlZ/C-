#include <iostream>
using namespace std;
int main(){
    int n;
    cout << "Nhap n: ";
    cin >> n;
    int sum=0;
    for (int i=1 ;i<=n/2;i++){
        if (n%i==0){
            sum +=i;
        }
    }
    if (sum==n || n!=0){
        cout<<n<<" la so hoan hao";
    }
    else {
        cout<<n<<" khong la so hoan hao";
    }
}