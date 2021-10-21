#include<iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int left , right;
    while(cin>>left>>right && left!=0){
        long long int a1=left/5 , an=right/5;
        cout<<an-a1+1<<"\n";
    }



}
