#include <iostream>
using namespace std;
 
bool nhap(int a[], int &n){
    cin>>n;
    for(int i= 0; i<n;i++){
        cin>>a[i];
        if (a[i]==11) {
        	return true;
		}
    }
    return false;
}
 
void Sort(int a[], int n){   
	
    for (int i = 0; i < n - 1; i++)
    {
        	for (int j = i + 1; j < n; j++)
        	{
            	if(a[i] > a[j]) 
            	{
               	 	int temp = a[i];
               	 	a[i] = a[j];
                	a[j] = temp;
            	}
        	}
    	
    }
}
 
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
	if (nhap(arr, n)==true) cout<<"-1";
	else
	{
	Sort(arr, n);
    printArray(arr, n);
	}
    return 0;
    
}