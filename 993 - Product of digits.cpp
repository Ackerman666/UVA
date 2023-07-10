#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main(){

    cin.tie(0);
    std::ios::sync_with_stdio(0);

    int n;
    cin>>n;
    while(n--){
        int num, base=9;
        vector<int> factor;
        cin>>num;

        while(base > 1){
            if(num <= 9){
                factor.push_back(num);
                num = 1;
                break;
            }
            else if(num % base == 0){
                factor.push_back(base);
                num = num / base;
            }
            else
                base--;
        }
        int len = factor.size();

        if(num!=1)
            cout<<"-1\n";
        else{
            for(int i=len-1 ; i>=0 ; i--)
                cout<<factor[i];
            cout<<"\n";
        }
    }
}
