#include <iostream>
using namespace std;
void inp(int n,int a[]){
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
}
int in(int n)
{
    if (n<=1) return 0;
    for (int i=2;i*i<=n;i++)
    {
        if (n%2==0) return 0;
        
    }
    return 1;
}
void found(int n,int a[])
{
    int c=0;
    for (int i=0;i<n;i++){
        if (in(a[i])){
            cout<<a[i]<<" ";
        }
    }
}
int main(){
    int n,a[100];
    cin>>n;
    inp(n,a);
    found(n,a);

}