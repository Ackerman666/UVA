#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<utility>

using namespace std;

int main(){

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    int mov[8][2] = {{-1,-2}, {-2,-1}, {-2,1}, {-1,2}, {1,2}, {2,1}, {2,-1}, {1,-2}};

    char a,b;
    int  c,d;


    while(cin>>a>>c>>b>>d){
        bool visit[9][9] = {0};         //紀錄有沒有被騎士走過
        bool find = false;
        int tx = a-'a'+1, ty = c;
        int x = b-'a' + 1, y = d;
        int step = 0;
        queue<pair<int, int> > coordinate;
        coordinate.push(make_pair(x,y));
        while(1){

            int len = coordinate.size();
            for(int i=1 ; i<=len ; i++){

                x = coordinate.front().first;
                y = coordinate.front().second;
                coordinate.pop();

                visit[x][y] = true;
                if(x == tx && y == ty){
                    find = true;
                    break;
                }

                for(int i=0 ; i<8 ; i++){
                    int nx = x+mov[i][0];
                    int ny = y+mov[i][1];
                    if(nx > 0 && nx <= 8 && ny > 0 && ny <=8 && !visit[nx][ny]){
                        coordinate.push(make_pair(nx,ny));
                    }
                }
            }
            if(find)
                break;
            step++;  
        }
        cout<<"To get from "<<a<<c<<" to "<<b<<d<<" takes "<<step<<" knight moves.\n";
    } 
}