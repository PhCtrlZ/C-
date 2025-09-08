#include <iostream>
using namespace std;
void input(int x)
{
  int a[x],b[x],dem,z,d,e;
  for (int i=1;i<=x;i++)
  {
    cin>>a[i];
  }
  dem=0;
  for (int i=1;i<=x;i++)
  {
    d=1;
    z=a[d];
    if (z==a[i+1])
    {
      dem+=1;
    }
    if (i<=x)
    {
      b[i]=dem;
      e=1;
      d+=1;
      e++;
      i=e;
      dem=0;

    }
  }
  for (int i=1;i<=x;i++)
  {
    cout <<a[i]<<" " << b[i]<<endl;
  }
}
int main() {
  int n;
  cin>>n;
  input(n);
  return 0;
}
