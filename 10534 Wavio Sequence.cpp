#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> build_LIS(vector<int> &nums){
    int array_length = nums.size();
    vector<int> t;             //record current increasing sequence
    vector<int> LIS;

    if(array_length != 0){
        t.push_back(nums[0]);
        LIS.push_back(1);

        for(int i=1 ; i<array_length ; i++){
            //directly add to current increasing sequence
            if(nums[i] > t.back()){
                t.push_back(nums[i]);
                LIS.push_back(t.size());
            }
            else{
                int index = lower_bound(t.begin(), t.end(), nums[i]) - t.begin();
                t[index] = nums[i];
                LIS.push_back(index+1);
            }
        }
    }
    return(LIS);
}



int main(){

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin>>n){
        vector<int> nums;
        vector<int> LIS;            //LIS[i] : 紀錄以第i個元素結尾的LIS長度
        vector<int> LDS;
        int ans = 1;
        for(int i=0 ; i<n ; i++){
            int t;
            cin>>t;
            nums.push_back(t);
        }

        LIS = build_LIS(nums);
        reverse(nums.begin(), nums.end());
        LDS = build_LIS(nums);;
        reverse(LDS.begin(), LDS.end());

        for(int i=1 ; i<nums.size()-1 ; i++){
            //let i is Wavio Sequence mid point
            ans = max(ans, min(LIS[i], LDS[i])*2-1);
        }
        cout<<ans<<"\n";
    }
}
