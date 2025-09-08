#include <iostream>

using namespace std;
void input(int x)
{
    for (int i=0;i<x;i++){
        for (int j=0;j<x;j++)
    
    {
        cout<<"*";
    }
    cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    input(n);
}