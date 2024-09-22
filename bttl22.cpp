
#include <iostream>
using namespace std;
 
//Hàm nhập mảng
void input(int a[], int &n){
    cin>>n;
    for(int i= 0; i<n;i++){
        cin>>a[i];
    }
}
 
//Hàm sắp xếp mảng 1 chiều giảm dần
void InterchangeSort(int a[], int n){   
    for (int i = 0; i < n - 1; i++)
    {
      //j sẽ được duyệt từ vị trí của phân tử chưa sắp xếp tới cuối mảng
        for (int j = i + 1; j < n; j++)
        {
        //Nếu phần tử đang kiểm tra(a[i]) lớn hơn phần tử khi ta duyệt mảng để kiểm tra(a[j])
            if(a[i] < a[j]) 
            {
               //Hoán đổi vị trí 2 phần tử
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
 
//Hàm xuất mảng
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<< arr[i] <<" ";
   cout<<"\n";
}
int main()
{
    int arr[1000];
    int n;
 
    input(arr, n);
    InterchangeSort(arr, n);
    printArray(arr, n);
    return 0;
}