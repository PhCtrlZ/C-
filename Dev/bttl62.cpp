#include <iostream>
#include <string>
using namespace std;
void khoangtrang(string n){
    int a;
    for (int i=0;i<n.length();i++){
        if (n[i]==' '){
            a++;
            for (int j=0;j<n.length();j++)
            {
                if (n[i+j]==' '){
                    i++;
                }
            }
        }
    }
    cout<<a<<endl;
}
int main(){
    string n;
    getline(cin,n);
    khoangtrang(n);
}