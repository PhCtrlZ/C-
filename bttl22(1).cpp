
#include <iostream>
using namespace std;
 
//Hàm nhập mảng
void input(int n)
{
	int A[n],z;
    for(int i= 1; i<=n;i++){
        cin>>A[i];
    }
    for (int i=1;i<=n;i++)
    for (int j=1;j<=i;j++)
    {
    	if (A[i]>A[j])
		{
			z=A[i];
			A[i]=A[j];
			A[j]=z;	
		}
	}
	for (int i=1;i<=n;i++)
	{
		cout<<A[i];
	}
}
 
int main()
{
    int n;
    cin>>n;
    input(n);
    return 0;
}