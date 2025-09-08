#include <iostream>
using namespace std;

int main(){
    string n;
    cin>>n;
    if (n[0]==n[n.length()-1]){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}