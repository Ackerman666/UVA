#include<iostream>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        bool IsInqueue[100001]={0};
        queue<int> q;
        int ans=0 , element;
        for(int i=1;i<=n;i++){
            cin>>element;
            if(!IsInqueue[element]){
                q.push(element);
                IsInqueue[element]=true;
            }
            else{
                int QueueMember;
                while(q.size()){
                    QueueMember=q.front();
                    IsInqueue[QueueMember]=false;
                    q.pop();
                }
                q.push(element);
                IsInqueue[element]=true;
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}
