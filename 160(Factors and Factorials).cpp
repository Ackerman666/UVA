#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

void factor(map<int, int> &mp, int num){
    int f = 2;
    while(num > 1){
        if(num%f==0){
            mp[f]++;
            num = num / f;
        }
        else
            f++;
    }
}



int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin>>n && n!=0){
        map<int, int>::iterator iter;
        map<int, int> mp;
        vector<int> vc;
        for(int i=1 ; i<=n ; i++){
            factor(mp, i);
        }
        for(iter = mp.begin(); iter!=mp.end(); iter++){
            vc.push_back(iter->second);
        }

        sort(vc.begin(), vc.end(), greater<int>());

        int steps = 0, index = 0, amount = vc.size();
        cout<<setw(3)<<n<<"! =";
        while(amount--){
            if(steps>0 && steps%15==0)
                cout<<"\n      ";
            cout<<setw(3)<<vc[index];
            index++;
            steps++;
        }
        cout<<"\n";
    }
}
