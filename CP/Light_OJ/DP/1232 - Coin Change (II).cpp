#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int n,k;
int coin[110],way[10100];

int main(){
    int t,no=0;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>coin[i];
        memset(way,0,sizeof way);
        way[0]=1;

        for(int j=0;j<n;j++){
            for(int i=1;i<=k;i++){
                if(i>=coin[j]){
                    way[i]=(way[i]+way[i-coin[j]])%mod;
                }
            }
        }
        cout<<"Case "<<++no<<": "<<way[k]<<endl;
    }
}
