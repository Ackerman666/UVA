#include<iostream>
#include<map>
using namespace std;

void dfs(int index , int ended , map<long long int,long long int> &mp , int arr[] , long long int sum){
    if(index==ended){
        mp[sum]++;
        return;
    }
    dfs(index+1, ended, mp, arr, sum+arr[index]);    //子集合有arr[index]
    dfs(index+1, ended, mp, arr, sum);              //子集合沒有arr[index]
}


int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    int n , target;
    while(cin>>n>>target){
        //存某一值對應到的子集合個數 e.g. ml[5]=6 代表左半部共有6個子集合加總的合為5
        map<long long int, long long int> mleft , mright;
        map<long long int, long long int>:: iterator  iter;
        int arr[50]={0} ;
        long long int ans=0;

        for(int i=0 ; i<n ;i++)
            cin>>arr[i];

        if(n==1){
            if(arr[0]==target)
                ans++;
        }
        else{
            //因為題目的n最大到40 如果直接去窮舉全部可能 複雜度為2^40 =>太大 因此將集合分左右半部處理
            int mid = n/2;
            //窮舉左半部
            dfs(0, mid, mleft, arr, 0);
            //窮舉右半部
            dfs(mid, n, mright, arr, 0);

            //e.g. 假設target=10  , mleft[4]=3 , mright[6]=4 則代表有3*4=12種子集合的合為10
            //用此邏輯迴圈加總全部可能組合即得解
            for(iter = mleft.begin() ; iter!=mleft.end() ;iter++){
                long long int valA = iter->first , valB = target - valA;
                if(mright.count(valB)){
                    ans+=mleft[valA]*mright[valB];
                }
            }
        }
        //target=0 答案會有空集合所以要減掉
        if(target==0)
            ans--;
        cout<<ans<<"\n";
    }
}
