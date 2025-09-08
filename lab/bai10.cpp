#include <iostream>
using namespace std;

class LopHoc{
    public:
    int n;
    string ten[100];
    int dtb[100];
    string id[100];
    double tb;
    LopHoc(){
        n=0;
        tb=0.0;
    }
    LopHoc(int a,double dtb)
    {
        n=a;
        tb=dtb;
    }
    void nhap(int n){
        for (int i=0;i<n;i++)
        {
            cout<<"Nhap ma so sinh vien thu "<<i<<":";
            cin>>id[i];
            cout<<"Nhap ten sinh vien thu "<<i<<":";
            cin>>ten[i];
            cout<<"Nhap diem trung binh cua sinh vien thu "<<i<<":";
            cin>>dtb[i];
        }
    }
    void findDTB(int n,int dtb[],string ten[]){
        int c=dtb[0];
        string d=ten[0];
        for (int i=0;i<n;i++){
            if(c<dtb[i]){
                c=dtb[i];
                d=ten[i];
            }
        }
        cout<<"Hoc sinh "<<d<<" co diem trung binh "<<c<<" cao nhat lop!"<<endl;
    }
    void findHS(int n,string ten[]){
        string k;
        cout<<"nhap ten sinh vien can tim:";
        cin>>k;
        for (int i=0;i<n;i++){
            if (ten[i]==k){
                cout<<"Da tim thay sinh vien "<<k<<" o vi tri so "<<i<<endl;
            }
        }
    }
    void sapXep(int n,string ten[],int dtb[],string id[],bool tang){
        for (int i=0;i<n-1;i++){
            for (int j=i+1;j<n;j++){
                if ((tang && dtb[i]>dtb[j]) || (!tang && dtb[i]<dtb[j])){
                    swap(dtb[i],dtb[j]);
                    swap(ten[i],ten[j]);
                    swap(id[i],id[j]);
                }
            }
        }
    }
    void chen(int &n,string ten[],int dtb[],string id[]) {
        string k,m;
        int c;
        cout << "Nhap ma so sinh vien can chen: ";
        cin >> m;
        cout << "Nhap ten sinh vien can chen: ";
        cin >> k;
        cout << "Nhap diem trung binh cua sinh vien: ";
        cin >> c;
        int pos = 0;
        while (pos < n && dtb[pos] < c) {
            pos++;
        }
        for (int i = n; i > pos; i--) {
            ten[i] = ten[i - 1];
            dtb[i] = dtb[i - 1];
            id[i] = id[i - 1];
        }
        ten[pos] = k;
        dtb[pos] = c;
        id[pos] = m;
        n++;
        cout << "Danh sach sau khi chen:"<<endl;
        for (int i = 0; i < n; i++) {
            cout << id[i] << " - " << ten[i] << " - " << dtb[i] << endl;
        }
    }
    void xoa(int &n,string id[]){
        string x;
        cout<<"Nhap ma so sinh vien can xoa: ";
        cin>>x;
        int pos=-1;
        for(int i=0;i<n;i++){
            if(id[i]==x){
                pos=i;
                break;
            }
        }
        if(pos!=-1){
            for(int i=pos;i<n-1;i++){
                id[i]=id[i+1];
                ten[i]=ten[i+1];
                dtb[i]=dtb[i+1];
            }
            n--;
        }
    }
    void xuat(int n,string ten[],int dtb[],string id[]){
        for (int i=0;i<n;i++){
            cout<<id[i]<<" - "<<ten[i]<<" - "<<dtb[i]<<endl;
        }
    }
};

int main() {
    LopHoc l;
    int n;
    cout<<"Nhap si so lop: ";
    cin>>n;
    l.nhap(n);
    l.sapXep(n,l.ten,l.dtb,l.id,true);
    l.chen(n,l.ten,l.dtb,l.id);
    l.xuat(n,l.ten,l.dtb,l.id);
    l.xoa(n,l.id);
    l.xuat(n,l.ten,l.dtb,l.id);
    return 0;
}
