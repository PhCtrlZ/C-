/** Nhập 3 số thực a, b, c và kiểm tra 3 số đó có phải là 3 cạnh của 1 tam giác không? 
Nếu là 3 cạnh tam giác thì cho biết là tam giác nào trong các loại tam giác sau: đều, vuông cân, vuông, cân, thường và tính chu vi, 
diện tích của tam giác đó. In kết quả ra màn hình.**/
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void tamgiacdeu(int x,int y,int z)
{
    cout<<"chu vi tam giac deu:"<<3*x<<endl;
    cout<<"dien tich tam giac deu:"<<((x*x)*sqrt(3))/4<<endl;
}
void tamgiacvuong(int x,int y,int z)
{
    cout<<"chu vi tam giac vuong:"<<x+y+z<<endl;
    cout<<"dien tich tam giac vuong:"<<1/2*x*y<<endl;
}
void tamgiacvuongcan(int x,int y,int z)
{
    cout<<"dien tich tam giac vuong can:"<<1/2*(x*x)<<endl;
    cout<<"chu vi tam giac vuong can:"<<2*x+z<<endl;
}
void tamgiaccan(int x,int y,int z)
{
    cout<<"chu vi tam giac can:"<<2*x+y<<endl;
    cout<<"dien tich tam giac can:"<<1/2*(x*x)<<endl;
}
int main()
{
    int a,b,c;
    cout<<"nhap vao 3 canh cua tam giac:"<<endl;
    cin>>a;
    cin>>b;
    cin>>c;
    if (abs(b-c)<a<b+c)
    {
        cout<<"day la 1 tam giac thuong"<<endl;
    }
    else if (a==b || b==c ||a==c)
    {
        cout<<"day la tam giac can"<<endl;
        tamgiaccan(a,b,c);
    }
    else if (a==b || b==c )
    {
        cout<<"day la tam giac deu"<<endl;
        tamgiacdeu(a,b,c);
    }
    else if ((a *a + b *b == c *c) || (a *a + c *c == b *b) || (b *b + c *c == a *a) )
    {
        cout<<"day la tam giac vuong";
        tamgiacvuong(a,b,c);
    }
    else
    {
        cout<<"day la tam giac vuong can"<<endl;
        tamgiacvuongcan(a,b,c);
    }
    return 0;}