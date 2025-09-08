        #include <iostream>
        #include <vector>
        #include <cmath>
        using namespace std;
        void ficcbo(int n){
            const int mod=pow(10,6)+7;
            vector<long long> a(n+1);
            if (n==1) {
                cout<<"1"; return ;
            }
            if (n==0) {
                cout<<"0"; return;
            } 
            a[0]=0;
            a[1]=1;
            if (n>=2){
            for (int i=2;i<=n;i++){
                a[i]=(a[i-1]+a[i-2])%mod;
            }
            cout<<a[n];
        }

        }
        int main(){
            int n;
            cin>>n;
            ficcbo(n);
            cout<<endl;
            return 0;
        }