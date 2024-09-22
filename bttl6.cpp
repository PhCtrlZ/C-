#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

void giai(int x,int y,int z)
{
    float denta,x1,x2,x3;
    denta=(y*y)-4*x*z;
    if (denta<0)
    {
        cout<<"Phuong trinh nay vo nghiem"<<endl;
        cout<<"Va chi vo nghiem voi so trong pham vi nho hon so thuc"<<endl;
        cout<<"nghiem phuc:(-y+-sqrt(abs(denta))/2x)"<<endl;
    }
    if (denta>0)
    {
        cout<<"Phuong trinh co hai nghiem phan biet"<<endl;
        x1=((-y)+sqrt(denta))/2*x;
        x2=((-y)-sqrt(denta))/2*x;
        cout<<"Nghiem thu nhat la :"<<x1<<endl;
        cout<<"Nghiem thu hai la:"<<x2<<endl;
    }
    if (denta=0)
    {
        cout<<"Phuong trinh co nghiem kep"<<endl;
        x3=(-y)/2*x;
        cout<<"x1=x2="<<x3<<endl;
    }
}
int main()
{
    cout<<"giai phuong trinh bac 2"<<endl;
    int a,b,c;
    cout<<"nhap vao 3 so nguyen a b c de giai:";
    cin>>a;
    cin>>b;
    cin>>c;
    giai(a,b,c);

}