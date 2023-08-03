#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstdlib>
#include<queue>

using namespace std;

int LIS(vector<int> &vc){

    int len = vc.size();
    vector<int> LIS;
    vector<int>::iterator it;

    if(len == 0)
        return(0);

    LIS.push_back(vc[0]);
    for(int i=1 ; i<len ; i++){
        if(vc[i] > LIS.back() ){
            LIS.push_back(vc[i]);
        }

        else{
            it = lower_bound(LIS.begin(), LIS.end(), vc[i]);
            *it = vc[i];
        }
    }
    return(LIS.size());
}

int main(){
    int n,m,t=1;

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    while(cin>>n>>m && n!=0 && m!=0){

        int arr1[101], arr2[101];
        vector<vector<int> > record(1000);
        vector<int> vc;
        vc.reserve(1000);

        for(int i=0 ; i<n ; i++){
            cin>>arr1[i];
            record[arr1[i]].push_back(i);
        }

        for(int i=0 ; i<m ; i++){
            cin>>arr2[i];
            int len = record[arr2[i]].size();
            for(int j=len-1 ; j>=0 ; j--){
                vc.push_back(record[arr2[i]][j]);
            }
        }
        cout<<"Twin Towers #"<<t<<"\n";
        cout<<"Number of Tiles : "<<LIS(vc)<<"\n\n";
        t++;
    }
}


