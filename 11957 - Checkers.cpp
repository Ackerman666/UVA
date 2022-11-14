#include<iostream>
using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    int n, Case=1;
    cin>>n;
    while(n--){
        int  Size, paths=0;
        char board[105][105]={0};
        int  DP[105][105]={0};

        cin>>Size;
        for(int i=1 ; i<=Size ; i++)
            for(int j=1 ; j<=Size ; j++)
                cin>>board[i][j];

        for(int i=Size ; i>=1 ; i--){
            for(int j=1 ; j<=Size ; j++){
                if(board[i][j]=='W') DP[i][j]=1;
                else if(board[i][j]=='.'){
                    char leftdown=board[i+1][j-1], rightdown=board[i+1][j+1];
                    if(leftdown=='B')
                        DP[i][j] += DP[i+2][j-2];
                    else
                        DP[i][j] += DP[i+1][j-1];
                    DP[i][j] = DP[i][j] % 1000007;
                    if(rightdown=='B')
                        DP[i][j] += DP[i+2][j+2];
                    else
                        DP[i][j] += DP[i+1][j+1];
                    DP[i][j] = DP[i][j] % 1000007;
                }

            }
        }

        for(int i=1 ; i<=Size ; i++)
            paths = (paths + DP[1][i]) % 1000007;

        cout<<"Case "<<Case<<": "<<paths<<"\n";
        Case++;
    }
}
