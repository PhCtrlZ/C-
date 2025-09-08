#include <iostream>
using namespace std;
void analyst(int a);
void input(int x);

void input (int x)
{
    int a[x];
    for (int i=0;i<x;i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<x;i++)
    {
        analyst(a[i]);
    }

}
void analyst(int a)
{
    long long l=0;
    while (a>0){
        int d=a%10;
            l+=d;
        a/=10;
    }
    cout<<l<<endl;
}
int main()
{
    long long n;
    cin>>n;
    input(n);
}