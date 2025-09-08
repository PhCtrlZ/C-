#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
    char a,b;
    cin>>a>>b;
    for (char i=a;i<=b;i++)
    {
    putchar(toupper(i));
    cout<<" ";
    }

}