/** Một người cần có một số tiền T, tích lũy bằng cách gửi tiết kiệm số tiền ban đầu là S với lãi suất có kỳ hạn theo năm là P% 
theo phương thức lũy tiến (lãi của mỗi năm được cộng vào với tiền gốc). Hãy nhập vào các số thực T, S, P 
và xác định số năm cần gửi tiết kiệm.**/
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
void tinhlai (double x ,double y,double z)
{
    float lai,lai1,lai2;
    for (double i=1; ;i++)
    {
        lai=(x*(y/100))*i;
        lai1=x;
        lai2=lai1+lai;
        if (lai2>=z)
        {
            cout<<"ban can it nhat "<<i<<" nam de duoc so tien lai la:"<<z<<endl;
            break;
        }
    }
}
int main()
{
    double s,p,t;
    cout<<"nhap so tien ban dau ban muon gui tiet kiem:"<<endl;
    cin>>s;
    cout<<"Nhap vao lai suat hang nam:"<<endl;
    cin>>p;
    cout<<"nhap vao so tien ban can sau khi gui tiet kiem hang nam:"<<endl;
    cin>>t;
    tinhlai(s,p,t);
}