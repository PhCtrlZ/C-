
#include <iostream>
#include <cmath>
using namespace std;
 
//Hàm nhập mảng
void input(int n)
{
	int A[n],z;
    for(int i= 1; i<=n;i++){
        cin>>A[i];
    }
    for (int i=2;i<=n-1;i++)
    for (int j=2;j<=n-1;j++)
    {
    	if (A[i]<A[j])
		{
			z=A[i];
			A[i]=A[j];
			A[j]=z;	
		}
	}
	for (int i=1;i<=n;i++)
	{
		cout<<A[i]<<" ";
	}
}
 
int main()
{
    int n;
    cin>>n;
    if (n<3 && n>pow(10,4)) cout<<"ERROR";
    else    input(n);
    return 0;
}