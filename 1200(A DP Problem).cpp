#include<iostream>
#include<cctype>
using namespace std;

void constant(int &c , bool positive , int num){
    if(positive){
        c+=num;
    }
    else{
        c-=num;
    }
}

void var(int &v , bool positive , int num){
    if(positive){
        v+=num;
    }
    else{
        v-=num;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool positive=true;
        bool right=false;      //等號右邊
        int lefc=0,lefx=0,rightc=0,rightx=0,slen=s.size(),num=0; //紀錄等號左右邊的變數和常數
        for(int i=0;i<slen;i++){
            if(s[i]=='-'){
                if(right)
                    constant(rightc,positive,num);
                else
                    constant(lefc,positive,num);
                positive=false;
                num=0;
            }
            else if(s[i]=='+'){
                if(right)
                    constant(rightc,positive,num);
                else
                    constant(lefc,positive,num);
                positive=true;
                num=0;
            }
            else if(s[i]=='x'){
                if(i==0 || !isdigit(s[i-1]))  //處理類似5+x=2 or x+1=2 的情況
                    num=1;
                if(right)
                    var(rightx,positive,num);
                else
                    var(lefx,positive,num);
                positive=true;
                num=0;
            }
            else if(s[i]=='='){
                constant(lefc,positive,num);
                positive=true;
                right=true;
                num=0;
            }
            else
                num=num*10+(s[i]-'0');
        }
        if(num)
            constant(rightc,positive,num);

        int top=rightc-lefc ,base=lefx-rightx;
        if(top==0 && base==0)
            cout<<"IDENTITY\n";
        else if(top!=0 && base==0)
            cout<<"IMPOSSIBLE\n";
        else{
            int ans=top/base;
            if(ans*base==top || ans>=0)
                cout<<ans<<"\n";
            else
                cout<<ans-1<<"\n";
        }
    }
}
