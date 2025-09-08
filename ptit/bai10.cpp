#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cout<<"nhap n: ";
    cin>>n;
    double a=1.0;
    double sum=1.0;
    for (int i=1;i<=n;i++){
        a*=i;
        sum+=1.0/a;
    }
    cout<<setprecision(2)<<"tong hang so e la:"<<sum<<endl;

}