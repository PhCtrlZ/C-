#include <iostream>

using namespace std;

int main(){
    int n,a[100];
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n-1;i++){
        bool error=false;
        for (int j=0;j<n-i-1;j++){
        if (a[j]>a[j+1]){
            int x=a[j];
            a[j]=a[j+1];
            a[j+1]=x;                 
        }
    }
    if (!error) break;
    }
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}