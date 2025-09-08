#include <iostream>

using namespace std;
void tong(int c){
    double d;
    d=0;
    for (int i=0;i<=c;i++)
    {
        d+=i;
    }
    cout<<d<<endl;
}
int main(){
    int a;
    int b[100];
    cin>>a;
    for (int i=0;i<a;i++)
    {
        cin>>b[i];
    }
    for (int i=0;i<a;i++)
    {
        tong(b[i]);
    }
}