#include<iostream>
using namespace std;
int main(){

    long long int n;
    while(cin>>n && n!=0){
        long long int ans = 0;
        long long int l=1, r;
        while(l<=n){
            long long int times = n/l;
            r = n/times;

            ans += ((l+r)*(r-l+1))/2*times;
            l = r+1;
        }
        cout<<ans-1<<endl;
    }
}
