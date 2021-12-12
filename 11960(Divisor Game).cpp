#include<iostream>
using namespace std;
int fac_num[1000001]={0};
int ans[1000001];

void ini(){
    int temp=0 , loc;               //loc : 目前因數最多的數
    for(int i=1;i<1000001;i++){         // 2*1 = 2 : 2有2這個因數所以++  2*2 = 4 : 4有2這個因數所以++ 以此類推得出因數個數
        for(int j=i;j<1000001;j+=i){
            fac_num[j]++;
        }
    }
    for(int i=1;i<1000001;i++){
        if(fac_num[i] >= temp){
            temp=fac_num[i];
            loc=i;
            ans[i]=i;
        }
        else
            ans[i]=loc;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ini();
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<ans[n]<<"\n";
    }
}
