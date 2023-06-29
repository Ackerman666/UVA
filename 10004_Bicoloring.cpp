#include<iostream>
using namespace std;

bool BICOLORABLE(int cur_node, int label, int road[][201], int visit[], int color[]){
    color[cur_node] = label;
    visit[cur_node] = 1;
    for(int i=0 ; i<201 ; i++){
        if( i!=cur_node ){
            if(road[cur_node][i]){
                if(color[i] == color[cur_node])
                    return(false);
                else if(!visit[i]){
                    if(label == 1)
                        return(BICOLORABLE(i, 2, road, visit, color));
                    else
                        return(BICOLORABLE(i, 1, road, visit, color));

                }
            }
        }
    }
    cout<<cur_node<<endl;
    return(true);
}



int main(){
    int n;
    while(cin>>n && n!=0){
        int l, road[201][201]={0}, a, b, visit[201]={0}, color[201]={0};
        cin>>l;
        for(int i=0 ; i<l ; i++){
            cin>>a>>b;
            road[a][b] = road[b][a] = 1;
        }
        
        if(BICOLORABLE(0, 1, road, visit, color))
            cout<<"BICOLORABLE.\n";
        else
            cout<<"NOT BICOLORABLE.\n";
    }
}