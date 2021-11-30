#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
string cur;
int cur_size;
bool used[12];
map<string , bool> mp;


void permutation(int n , string s){
    if(n==cur_size && !mp.count(s)){   //透過map去避免重複的組合
        cout<<s<<"\n";
        mp[s]=true;
        return;
    }
    for(int i=0;i<cur_size;i++){
        if(!used[i]){
            used[i]=true;              //用過的字元設true
            permutation(n+1,s+cur[i]);
            used[i]=false;
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        cin>>cur;
        for(int i=0;i<cur.size();i++)
            used[i]=false;
        cur_size=cur.size();
        mp.clear();
        sort(cur.begin(),cur.end());
        permutation(0,"");
        cout<<"\n";
    }
}
