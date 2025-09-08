#include <iostream>

using namespace std;
int ficcbo(int n){
    if (n==0) return 0;
 	if (n==1) return 1;
	return ficcbo(n-1)+ficcbo(n-2);
}
int main(){
    int n;
    cin>>n;
    cout<<"1"<<" ";
    for (int i=2;i<=n;i++){
	       cout<<ficcbo(i)<<" ";
    }
    return 0;
}