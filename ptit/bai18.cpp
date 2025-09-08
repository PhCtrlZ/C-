#include <iostream>
using namespace std;

#define MAX 1000

void nhapMang(int a[], int &n) {
    cout << "Nhap so phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void xuatMang(int a[], int n) {
    cout << "Mang: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

int demSoChan(int a[], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) if (a[i] % 2 == 0) dem++;
    return dem;
}

int demPhanTuBangX(int a[], int n, int x) {
    int dem = 0;
    for (int i = 0; i < n; i++) if (a[i] == x) dem++;
    return dem;
}

int timMin(int a[], int n) {
    int mn = a[0];
    for (int i = 1; i < n; i++) if (a[i] < mn) mn = a[i];
    return mn;
}

int timMax(int a[], int n) {
    int mx = a[0];
    for (int i = 1; i < n; i++) if (a[i] > mx) mx = a[i];
    return mx;
}

void timViTriX(int a[], int n, int x) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            cout << "Tim thay x tai vi tri: " << i << endl;
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay x trong mang\n";
}

void xoaPhanTuX(int a[], int &n, int x) {
    int k = 0;
    for (int i = 0; i < n; i++) if (a[i] != x) a[k++] = a[i];
    n = k;
}

void sapXepTang(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) swap(a[i], a[j]);
}

void chenX(int a[], int &n, int x) {
    // đảm bảo mảng đã được sắp xếp trước khi chèn
    int i = n - 1;
    while (i >= 0 && a[i] > x) {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = x;
    n++;
}

void tronMang(int a[], int n, int b[], int m, int c[], int &k) {
    int i = 0, j = 0;
    k = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while (i < n) c[k++] = a[i++];
    while (j < m) c[k++] = b[j++];
}

void daoMang(int a[], int n) {
    for (int i = 0; i < n / 2; i++) swap(a[i], a[n - 1 - i]);
}

bool kiemTraDoiXung(int a[], int n) {
    for (int i = 0; i < n / 2; i++)
        if (a[i] != a[n - 1 - i]) return false;
    return true;
}

int timLonThu2(int a[], int n) {
    int max1 = timMax(a, n), max2 = -1e9;
    for (int i = 0; i < n; i++)
        if (a[i] != max1 && a[i] > max2) max2 = a[i];
    return max2;
}

int timNhoThu2(int a[], int n) {
    int min1 = timMin(a, n), min2 = 1e9;
    for (int i = 0; i < n; i++)
        if (a[i] != min1 && a[i] < min2) min2 = a[i];
    return min2;
}

int main() {
    int a[MAX], b[MAX], c[MAX];
    int n = 0, m = 0, k = 0;
    int chon, x;

    do{
        cout<<"========== MENU MANG 1 CHIEU ==========\n";
        cout<<"1.Nhap mang\n";
        cout<<"2.Xuat mang\n";
        cout<<"3.Dem so chan\n";
        cout<<"4.Dem phan tu bang x\n";
        cout<<"5.Tim min\n";
        cout<<"6.Tim max\n";
        cout<<"7.Tim vi tri cua phan tu x\n";
        cout<<"8.Xoa phan tu x\n";
        cout<<"9.Sap xep tang dan\n";
        cout<<"10.Chen x vao mang da sap xep\n";
        cout<<"11.Tron 2 mang tang dan\n";
        cout<<"12.Dao mang\n";
        cout<<"13.Kiem tra doi xung\n";
        cout<<"14.Tim phan tu lon thu 2\n";
        cout<<"15.Tim phan tu be thu 2\n";
        cout<<"16.Thoat\n";
        cin>>chon;
        switch (chon)
        {
            case 1: nhapMang(a,n);
            break;
            case 2: xuatMang(a,n);
            break;
            case 3: cout<<"so chan "<<demSoChan(a,n)<<endl;
            break;
            case 4: cout<<"nhap x:";
            cin>>x;
            cout<<"so lan xuat hien"<<demPhanTuBangX(a,n,x)<<endl;
            break;
            case 5:cout<<"Min="<<timMin(a,n)<<endl;
            break;
            case 6:cout<<"Max="<<timMax(a,n)<<endl;
            break;
            case 7:
            cout<<"nhap x:"; cin>>x;
            timViTriX(a,n,x);
            break;
            case 8: cout<<"nhap x:";cin>>x;
            xoaPhanTuX(a,n,x); xuatMang(a,n);
            break;
            case 9:
            sapXepTang(a,n);
            cout<<"mang sau khi sap xep:"<<endl;
            xuatMang(a,n);
            break;
            case 10:{
                cout<<"nhap x:";cin>>x;
                sapXepTang(a,n);
                chenX(a,n,x);
                cout<<"mang sau khi chen";xuatMang(a,n);
                break;
            }
            case 11:{
                cout<<"nhap mang B"<<endl;
                nhapMang(b,m);
                sapXepTang(a,n);sapXepTang(b,m);
                tronMang(a,n,b,m,c,k);
                cout<<"mang tron:";xuatMang(a,n);
                break;
            }
            case 12:{
                daoMang(a,n);
                cout<<"mang sau khi dao";xuatMang(a,n);
                break;
            }
            case 13:{
                if (n==0){
                    cout<<"Mang rong"<<endl;
                }
                else{
                    if(kiemTraDoiXung(a,n)){
                        cout<<"mang doi xung";
                    }
                    else {
                        cout<<"mang khong doi xung"<<endl;
                    }
                }
                break;
            }
            case 14:{
                cout<<"lon thu 2="<<timLonThu2(a,n)<<endl;
                break;
            }
            case 15:{
                cout<<"nho thu 2="<<timNhoThu2(a,n)<<endl;
                break;
            }
            case 0: cout<<"thoat!"<<endl; break;
        
        default:
            cout<<"nhap sai!";
            break;
        }
    }while (chon!=0);

    return 0;
}
