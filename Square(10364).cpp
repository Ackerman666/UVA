#include<iostream>
#include<algorithm>
using namespace std;

bool dfs(int m , int ini ,int sidelen , int sidenum , int curlen , bool instack[] , int stick[]){  //ini : 從第stick[ini]開始找組合
    if(curlen==sidelen){
        curlen=0;
        sidenum++;
        ini=1;
        if(sidenum==3)
            return(1);
    }
    for(int i=ini;i<=m;i++){
        if( curlen+stick[i]<=sidelen && !instack[i]){    //加進組合不會爆
            instack[i]=1;
            if( dfs(m,i+1,sidelen,sidenum,curlen+stick[i],instack,stick) )  //有搜尋到解
                return(1);
            instack[i]=0;
        }
    }
    return(0);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,stick[21];
    cin>>n;
    while(n--){
        int perimeter=0;
        cin>>m;
        for(int i=1;i<=m;i++){
            cin>>stick[i];
            perimeter+=stick[i];
        }
        if(perimeter%4)
            cout<<"no\n";
        else{
            int sidelen=perimeter/4;
            sort(stick+1,stick+m+1,greater<int>()); //大排到小->減少運算量(避免搜尋到太深層,發現不適合時所造成的運算浪費)
            if(stick[1]>sidelen)                 //有棍子大於邊長->無法組出正方形
                cout<<"no\n";
            else{
                bool instack[21]={0};
                if(dfs(m,1,sidelen,0,0,instack,stick))  //可組正方形
                    cout<<"yes\n";
                else
                    cout<<"no\n";
            }
        }
    }
}
