#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstdlib>
#include<queue>

using namespace std;

void store(string s, int num[]){
    int index = 0;
    for(int i=s.size()-1 ; i>=0 ; i--){
        num[index] =  (s[i] - '0');   //589234
        index++;
    }
}

int main(){

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    while(cin>>s1>>s2){
        int num1[500] = {0}, num2[500] = {0}, ans[800] = {0};

        if(s1 == "0" || s2 == "0"){
            cout<<"0\n";
            continue;
        }

        store(s1, num1);
        store(s2, num2);

        for(int i=0 ; i<s1.size() ; i++){              //123 * 456
            for(int j=0 ; j<s2.size() ; j++){
                ans[i+j] += num1[i] * num2[j] ;
                ans[i+j+1] += ans[i+j]/10;
                ans[i+j]%=10;
            }
        }

        int index;
        for(int i=499 ; i>=0 ; i--){
            if(ans[i] != 0 ){
                index = i;
                break;
            }
        }
        for(int i=index ; i>=0 ; i--)
            cout<<ans[i];
        cout<<"\n";
    }
}