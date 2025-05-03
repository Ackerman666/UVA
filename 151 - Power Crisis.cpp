#include<iostream>

using namespace std;

int Josephus(int n, int k){
    int label = 0;
    for(int i=2 ; i<=n-1 ; ++i){
        label = (label + k) % i;
    }
    return (label + 2);
}


int main(){
    int n;
    while(cin>>n && n){
        for(int m=1 ; ; ++m){
            if(Josephus(n, m) == 13){
                cout << m << endl;
                break;
            }
        } 
    }
}
