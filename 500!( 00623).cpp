#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string fac[1001];
    fac[0]="1";
    fac[1]="1";
    fac[2]="2";
    fac[3]="6";
    for(int i=4;i<=1000;i++){
        int cur=i,result[4000]={0},times=0;
        string pre=fac[i-1],s="";
        while(cur){
            int mod=cur%10,index=times;
            for(int j=pre.size()-1;j>=0;j--){
                result[index]+=(fac[i-1][j]-'0')*mod;
                result[index+1]+=result[index]/10;
                result[index]=result[index]%10;
                index++;
            }
            cur/=10;
            times+=1;
        }
        bool t=0;
        for(int i=3000;i>=0;i--){
            if(result[i])
                t=1;
            if(t)
                s+=result[i]+'0';
        }
        fac[i]=s;
    }
    int n;
    while(cin>>n){
        cout<<n<<"!\n";
        cout<<fac[n]<<"\n";
    }
}
