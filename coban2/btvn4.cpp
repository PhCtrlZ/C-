#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"Mang da nhap la "<<endl;;
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int s=0;
    for(int i=0;i<n;i++){
        s+=a[i];
    }
    cout<<s;
    return 0;
}