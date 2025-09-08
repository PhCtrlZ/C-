
#include <iostream>
using namespace std;
 
//Hàm nhập mảng
void input(int n)
{
	int A[n],dem;
    for(int i= 1; i<=n;i++){
        cin>>A[i];
    }
    for (int i=1;i<=n;i++)
    {
	if(n%i==0 && n>0)
		dem++;	
    if (dem==2)
		cout<<A[i]<<" ";
    }
}



 
int main()
{
    int n;
    cin>>n;
    input(n);
    if (n<2) cout<<"ERROR";
    return 0;
}