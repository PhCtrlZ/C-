/** định nghĩa số nguyên tố là số chia cho 1 và chính nó **/
#include <iostream>
#include <iomanip>

using namespace std;

void sont(int x)
{
	int y,dem;
	y=x;
	if (x<2) 
	cout << " ko co so nguyen to nao be hon 2";
	for (int i=1;i<=x;i++)
		if(x%i==0 && x>0)
			dem++;	
	if (dem==2)
		cout<<" la so nguyen to";
	else cout << " ko la so nguyen to";
	}
int main()
{
	int n;
	cout<<"nhap n:"<<endl;
	cin>>n;
	sont(n);
}