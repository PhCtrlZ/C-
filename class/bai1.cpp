#include <iostream>
using namespace std;

class DenLed{
    // thuộc tính public
    public:
    string viTri;
    string mauSac;
    int doSang;
    //phương thức public
    void batDen(){
        cout<<"den da bat!"<<endl;
    }
    void tatDen(){
        cout<<"den da tat!"<<endl;
    }
    void tangDoSang(int a){
        a+=10;
        if(a>100){
            cout<<"Do sang da dat toi da!"<<endl;

        }
        else if(a<0){
            cout<<"do sang da dat toi thieu!"<<endl;
        }
        else{
            cout<<"do sang da tang len "<<a<<"%"<<endl;
        }
    }
    void giamDoSang(int a){
        a-=10;
        if(a<0){
            cout<<"do sang da dat toi thieu!"<<endl;
        }
        else{
            cout<<"do sang da giam xuong: "<<a<<"%"<<endl;
        }
    }
    

};
int main(){
    DenLed den;
    string vt,mau;
    int light;
    cout<<"nhap vi tri den:";
    getline(cin,vt);
    cout<<"nhap mau sac den:";
    getline(cin,mau);
    cout<<"nhap do sang tu 0->100:";
    cin>>light;
    den.viTri = vt;
    den.mauSac = mau;
    den.doSang = light;
    cout<<"Vi tri: "<<den.viTri<<endl;
    cout<<"Mau sac: "<<den.mauSac<<endl;
    cout<<"Do sang: "<<den.doSang<<endl;
    den.batDen();
    den.tangDoSang(den.doSang);
    den.giamDoSang(den.doSang);
    den.tatDen();
    return 0;
}