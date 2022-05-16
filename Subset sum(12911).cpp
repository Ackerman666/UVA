#include<iostream>
#include<map>
using namespace std;

void dfs(int index , int ended , map<long long int,long long int> &mp , int arr[] , long long int sum){
    if(index==ended){
        mp[sum]++;
        return;
    }
    dfs(index+1, ended, mp, arr, sum+arr[index]);    //�l���X��arr[index]
    dfs(index+1, ended, mp, arr, sum);              //�l���X�S��arr[index]
}


int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    int n , target;
    while(cin>>n>>target){
        //�s�Y�@�ȹ����쪺�l���X�Ӽ� e.g. ml[5]=6 �N���b���@��6�Ӥl���X�[�`���X��5
        map<long long int, long long int> mleft , mright;
        map<long long int, long long int>:: iterator  iter;
        int arr[50]={0} ;
        long long int ans=0;

        for(int i=0 ; i<n ;i++)
            cin>>arr[i];

        if(n==1){
            if(arr[0]==target)
                ans++;
        }
        else{
            //�]���D�ت�n�̤j��40 �p�G�����h�a�|�����i�� �����׬�2^40 =>�Ӥj �]���N���X�����k�b���B�z
            int mid = n/2;
            //�a�|���b��
            dfs(0, mid, mleft, arr, 0);
            //�a�|�k�b��
            dfs(mid, n, mright, arr, 0);

            //e.g. ���]target=10  , mleft[4]=3 , mright[6]=4 �h�N��3*4=12�ؤl���X���X��10
            //�Φ��޿�j��[�`�����i��զX�Y�o��
            for(iter = mleft.begin() ; iter!=mleft.end() ;iter++){
                long long int valA = iter->first , valB = target - valA;
                if(mright.count(valB)){
                    ans+=mleft[valA]*mright[valB];
                }
            }
        }
        //target=0 ���׷|���Ŷ��X�ҥH�n�
        if(target==0)
            ans--;
        cout<<ans<<"\n";
    }
}
