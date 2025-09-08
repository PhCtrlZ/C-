#ifndef PHANSO_HH
#define PHANSO_HH

class phanso {
private:
    int a, b;   
public:
    phanso();                     
    phanso(int aa, int bb);    
    void nhap();                 
    void xuat() const;                  
    int UCLN(int x, int y);
    void rutgon();
    phanso cong(const phanso &p);
    phanso tru(const phanso &p);
    phanso nhan(const phanso &p);
    phanso chia(const phanso &p);
};
#endif
