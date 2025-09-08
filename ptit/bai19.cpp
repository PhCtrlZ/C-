#include <iostream>

using namespace std;
struct nhanvien{
    string ten;
    string manv;
    float luong;
};
void nhap(nhanvien a[],int &n){
    cout<<"nhap so nhan vien";
    cin>>n;
    cin.ignore();
    for (int i=0;i<n;i++){
        cout<<"nhan vien thu "<<i+1<<endl;
        cout<<"ten:";
        getline(cin,a[i].ten);
        cout<<"ma nv";
        getline(cin,a[i].manv);
        cout<<"luong";
        cin>>a[i].luong;
        cin.ignore();
    }
}
void xuat(nhanvien a[],int n){
    cout<<"danh sach nhan vien"<<endl;
    for (int i=0;i<n;i++){
        cout<<i+1<<" ."<<a[i].ten<<"| Ma nv:"<<a[i].manv<<" |luong:"<<a[i].luong<<endl;
    }
}
int luongcaonhat(nhanvien a[],int n){
    int b=0;
    for (int i=0;i<n;i++){
        if (a[i].luong>a[b].luong){
            b=i;
        }
    }
    return b;
}
void daomang(nhanvien a[],int n){
    int l=0,r=n-1;
    while (l<r){
        nhanvien t=a[l];
        a[l]=a[r];
        a[r]=t;
        l++;
        r--;
    }
}
int demluong(nhanvien a[],int n){
    int dem=0;
    for (int i=0;i<n;i++){
        if (a[i].luong>5000000){
            dem++;
        }
    }
    return dem;
}
int main(){
    nhanvien a[4];
    int n=0;
    int chon;
    do{
        cout<<"\n=====MENU=====\n";
        cout<<"1.Nhap danh sach nhan vien"<<endl;
        cout<<"2.Xuat danh sach nhan vien"<<endl;
        cout<<"3.Tim nhan vien luong cao nhat"<<endl;
        cout<<"4.Dao mang nhan vien"<<endl;
        cout<<"5.Dem so nhan vien co luong tren 5tr"<<endl;
        cout<<"0.Thoat"<<endl;
        cout<<"chon so:";
        cin>>chon;
        cin.ignore();
        switch (chon){
            case 1:
            nhap(a,n);
            break;
            case 2:
            xuat(a,n);
            break;
            case 3:{
            int b= luongcaonhat(a,n);
            cout<<"nhan vien co luong cao nhat "<<a[b].ten<<"| luong:"<<a[b].luong<<endl;
            break;}
            case 4:{
            daomang(a,n);
            cout<<"Mang da dao la:"<<endl;
            xuat(a,n);
            break;}
            case 5:{
            int dem=demluong(a,n);
            cout<<"nhan vien co luong tren 5tr la:"<<dem<<endl;
            break;
        }
            case 0:
            cout<<"thoat chuong trinh !";
            break;
            default:
                cout<<"nhap sai!";
            break;
        }
    }while(chon!=0);
    return 0;
}