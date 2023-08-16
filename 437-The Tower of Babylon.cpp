#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstdlib>
#include<queue>

using namespace std;

struct block{
    int x, y, z;
    block(int x, int y, int z) : x(x), y(y), z(z) {
    }
};

bool cmp(block b1, block b2){
    if(b1.x == b2.x)
        return(b1.y < b2.y);
    return(b1.x < b2.x);
}

int main(){

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int n, Case = 1;
    while (cin>>n && n!=0)
    {
        int x, y, z, ans=0, LIS[200] = {0}, len = 6*n;
        vector<block> vc;
        vc.reserve(200);
        for(int i=1 ; i<=n ; i++){
            cin>>x>>y>>z;
            //考慮所有6種情況
            vc.push_back(block(x,y,z));
            vc.push_back(block(x,z,y));
            vc.push_back(block(y,x,z));
            vc.push_back(block(y,z,x));
            vc.push_back(block(z,x,y));
            vc.push_back(block(z,y,x));
        }

        sort(vc.begin(), vc.end(), cmp);

        // DP -> LIS : 去紀錄vc[i]為底可構築的多大的高度
        for(int i=0 ; i<len ; i++){
            LIS[i] = vc[i].z;
            for(int j=0 ; j<i ; j++){
                if((vc[j].x < vc[i].x) && (vc[j].y < vc[i].y)){
                    LIS[i] = max(LIS[i], vc[i].z + LIS[j]);
                }
            }
            ans = max(ans, LIS[i]);
        }

        cout<<"Case "<<Case<<": maximum height = "<<ans<<"\n";
        Case++;
    }
}

