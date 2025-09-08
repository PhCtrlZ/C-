#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cout<<"nhap n:"; 
    cin>>n;
    double sum=0;
    double ps=1.0;
    for (int i=1;i<=2*n-1;i+=2){// 2*n-1 là số lẻ bước nhảy 2 để 1->3 cũng là số lẻ
        sum+=ps*(4.0/i);
        ps*=-1.0;

    }
    cout<<setprecision(8)<<"so pi la:"<<sum<<endl;
    return 0;
}