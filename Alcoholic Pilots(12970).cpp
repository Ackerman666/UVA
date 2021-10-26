#include<iostream>
using namespace std;

long long gcd(long long int a , long long int b){   //輾轉相除求最大公因數
    if(a<b)
        swap(a,b);
    while(1){
        a=a%b;
        if(a==0)
            return(b);
        b=b%a;
        if(b==0)
            return(a);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long a,b,c,d;
    int Case=0;
    while(cin>>a>>b>>c>>d && a!=0){
        Case++;
        bool t=0;
        if(b*c < a*d)
            t=1;
        cout<<"Case #"<<Case;
        if(t)
            cout<<": You owe me a beer!\n";
        else
            cout<<": No beer for the captain.\n";
        cout<<"Avg. arrival time: ";
        long long int top,base;
        top=b*c+a*d;
        base=a*c*2;
        if(top%base==0)
            cout<<top/base<<"\n";
        else{
            long long int div=gcd(top,base);
            cout<<top/div<<"/"<<base/div<<"\n";
        }
    }
}
