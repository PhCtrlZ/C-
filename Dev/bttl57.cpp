#include <iostream>

using namespace std;

int ficcbo(int n){
    if (n==0) return 0;
 	if (n==1) return 1;
	return ficcbo(n-1)+ficcbo(n-2);
}
int main(){
    int n,f,b,c;
    n=100;
    cout<<"nhap vao so can tinh tong n:"<<endl;
    cin>>b;
    for (int i=2;i<=n;i++){
	    ficcbo(i);
        f=ficcbo(i)+ficcbo(i+1);
        if (f==b)  {
            c=i;
            for (int i=2;i<=n;i++)
            {
                cout<<ficcbo(c)<<" ";
            }
        }

    }
    return 0;
}