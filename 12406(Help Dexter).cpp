#include<iostream>
#include<cmath>
using namespace std;
long long int Floor ,Ceil , divisor;
int p,q,divv[18]={0};

void FindAns(int round, long long int candidate){
    if(round == p){
        if(candidate%divisor==0){
            if(candidate<Floor)
                Floor=candidate;
            else if(candidate>Ceil)
                Ceil=candidate;
        }
        return;
    }
    FindAns(round+1,candidate*10+1);
    FindAns(round+1,candidate*10+2);
}

void ini_divisor(){
    int d=1;
    for(int i=1;i<=17;i++){
        d*=2;
        divv[i]=d;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ini_divisor();
    int t,Case=1;
    cin>>t;
    while(t--){
        cin>>p>>q;
        cout<<"Case "<<Case<<": ";
        Floor=99999999999999999;
        Ceil=0;
        divisor=divv[q];
        FindAns(0,0);
        if(Floor==99999999999999999 && Ceil==0)
            cout<<"impossible\n";
        else if(Floor==99999999999999999)
            cout<<Ceil<<"\n";
        else if(Ceil==0)
            cout<<Floor<<"\n";
        else
            cout<<Floor<<" "<<Ceil<<"\n";
        Case++;
    }
}
