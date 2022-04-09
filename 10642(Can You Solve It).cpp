#include<iostream>
#include<map>
using namespace std;
int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    map<char , string> mp;
    mp['M']="100";             //ÃC¦â½s¸¹MYC
    mp['Y']="010";
    mp['C']="001";
    mp['R']="110";
    mp['B']="111";
    mp['G']="011";
    mp['V']="101";
    mp['W']="000";
    int n;
    cin>>n;
    while(n--){
        int M_count , Y_count , C_count;
        string  sequence;
        cin>>M_count>>Y_count>>C_count>>sequence;
        int  sequence_size =  sequence.size();
        for(int i=0 ; i< sequence_size ;i++){
            char color =  sequence[i];
            if( color=='W')
                continue;
            else{
                M_count-=mp[color][0]-'0';
                Y_count-=mp[color][1]-'0';
                C_count-=mp[color][2]-'0';
            }
        }
        if(M_count<0 || Y_count<0 || C_count<0 )
            cout<<"NO\n";
        else
            cout<<"YES "<<M_count<<" "<<Y_count<<" "<<C_count<<"\n";
    }
}
