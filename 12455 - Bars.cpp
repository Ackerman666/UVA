#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    while(n--){
        int target, nums;
        vector<int> bars(20);
        vector<int> DP(1001, 0);   //DP[i] 代表可以組出長度為i的bar
        
        DP[0] = 1;

        cin>>target>>nums;
        for(int i=0 ; i<nums; i++)
            cin>>bars[i];

        sort(bars.begin(), bars.end(), greater<int>());

        for(int i=0 ; i<nums; i++){
            int cur_bar_len = bars[i];
            for(int j=target ; j>cur_bar_len ; j--){
                if(DP[j] && j+cur_bar_len <= target)
                    DP[j+cur_bar_len] = 1;
            }
            DP[cur_bar_len] = 1;
        }

        if(DP[target])
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }

}