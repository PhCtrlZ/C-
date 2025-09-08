#include <iostream>
using namespace std;

void nhap(int n,int a[]){
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
}

void xuat(int n,int a[]){
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void findmin(int n,int a[]){
    int c=a[0];
    for (int i=1;i<n;i++){
        if (a[i]<c){
            c=a[i];
        }   
    }
    cout<<c<<endl;
}

void findmax(int n,int a[]){
    int c=a[0];
    for (int i=1;i<n;i++){
        if (a[i]>c){
            c=a[i];
        }   
    }
    cout<<c<<endl;
}

void find(int n,int a[]){
    int k;
    cin>>k;
    for (int i=0;i<n;i++){
        if (a[i]==k){
            cout<<i<<endl;
        }
    }
}

void xoak(int &n,int a[]){
    int k;
    cin>>k;
    int x=-1;
    for (int i=0;i<n;i++){
        if (a[i]==k){
            x=i;
            break;
        }
    }
    if (x==-1){
        return;
    }
    for (int i=x;i<n-1;i++){
        a[i]=a[i+1];
    }
    n--;
}

void sapxep(int n,int a[],bool tang){
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            if ((tang && a[i]>a[j]) || (!tang && a[i]<a[j])){
                swap(a[i],a[j]);
            }
        }
    }
}

void chen(int &n,int a[]){
    int k;
    cin>>k;
    int i=n-1;
    while(i>=0 && a[i]>k){
        a[i+1]=a[i];
        i--;
    }
    a[i+1]=k;
    n++;
}

void daomang(int n,int a[]){
    for (int i=0;i<n/2;i++){
        swap(a[i],a[n-1-i]);
    }
}

int main(){
    int n;
    cin>>n;
    int* a=new int[n+100];
    nhap(n,a);
    xuat(n,a);
    findmin(n,a);
    findmax(n,a);
    find(n,a);
    xoak(n,a);
    xuat(n,a);
    sapxep(n,a,true);
    xuat(n,a);
    sapxep(n,a,false);
    xuat(n,a);
    chen(n,a);
    xuat(n,a);
    daomang(n,a);
    xuat(n,a);
    delete[] a;
    return 0;
}
