#include<iostream>
#include<climits>
using namespace std;
int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, fred[30002]={0}, ans = 0;
        bool flag = 1;
        cin>>n;
        for(int i=1 ; i<=n ; i++){
            cin>>fred[i];
            if((flag && fred[i] > fred[i-1]) || (!flag && fred[i] < fred[i-1])){
                ans++;
                flag = !flag;
            }
        }
        cout<<ans<<"\n";
    }
}
