#include<iostream>
#include<cmath>
#include <climits>

using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    ++n;
    
    while(--n){
        double min_diff = INT_MAX;
        double pool_v, target_t, c, v, t, first, last;
        long long prefix_jars[4001][2] = {0};

        cin >> pool_v >> target_t;
        cin >> c;
        for(int i=1 ; i<=c ; ++i){
            cin >> v >> t;
            prefix_jars[i][1] = prefix_jars[i-1][1] + v;
            prefix_jars[i][2] = prefix_jars[i-1][2] + t*v;
        }

        for(int i=1 ; i<=c ; ++i){
            for(int j=i ; j<=c ; ++j){
                double tot = prefix_jars[j][1] - prefix_jars[i-1][1], pool_half = pool_v/2;
                if(tot <= pool_v && tot >= pool_half){
                    double mix_t = (prefix_jars[j][2] - prefix_jars[i-1][2])/tot;
                    double t_diff = abs(mix_t - target_t); 
                    if(min_diff > t_diff && t_diff <= 5){
                            first = i-1;
                            last = j-1;
                            min_diff = t_diff;
                    }
                }
            }
        }
        if(min_diff == INT_MAX){
            cout << "Not possible\n";
        }
        else{
            cout << first << " " << last << "\n";
        }
    }
    return 0;
}