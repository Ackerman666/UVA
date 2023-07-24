#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int main(){

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    while(cin>>n>>m){
        if(m==0 && n==0)
            break;

        int arr[102][102];
        // prefixHeight[i][j] : record counts of continuous zero at <i,j> 
        int prefixHeight[102][102]={0};
        int ans = 0;

        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                cin>>arr[i][j];
                if(arr[i][j] == 0){
                    prefixHeight[i][j] = 1 + prefixHeight[i-1][j];

                    int height = prefixHeight[i][j];
                    //let <i,j> be a lower right of a rectangle and from here to check all possible rectangle area and update ans
                    for(int k=j ; k>=1 ; k--){
                        if(arr[i][k] == 1)
                            break;
                        height = min(height, prefixHeight[i][k]);
                        ans = max(ans, height * (j-k+1));
                    }
                }    
            }      
        }
        cout<<ans<<"\n";
    }
}