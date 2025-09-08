#include <iostream>

using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void input(int x,int y, int z)
{
    int arr[x][y];
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            cin>>arr[i][j];
        }
    }
    z--;
    for (int i=0;i<y-1;i++){
        for (int j=i+1;j<y;j++){
            if (arr[z][i]>arr[z][j])
            {
                swap(arr[z][i],arr[z][j]);
            }
        }
    }
    for (int i=0;i<x;i++){
        for (int j=0;j<y;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    input(a,b,c);
    return 0;
}