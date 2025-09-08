#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
void input(int x)
{
    int A[x],z,tich;
    for (int i=1;i<=x;i++)
    {
        cin>>A[i];
    }
    for (int i=1;i<=x;i++)
    for (int j=1;j<=i;j++)
    {
        if (A[i]>A[j])
        {
            z=A[i];
            A[i]=A[j];
            A[j]=z;
        }
    }
    tich=A[1]*A[2];
    cout<<tich<<endl;

}
int main()
{
    int n;
    cin>>n;
    if (n<2 && n>pow(10,4)) cout<<"ERROR";
    else
        input(n);
    return 0;
}