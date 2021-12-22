#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 110
 
int arr[sz][sz];
int dp[sz][sz];
int r,c;
 
int solve(int i,int j){
    if(i>=0 && i<r && j>=0 && j<c){
        if(dp[i][j]!=-1) return dp[i][j];
        int ret=0;
        ret=max(ret,solve(i+1,j)+arr[i][j]);
        ret=max(ret,solve(i+1,j-1)+arr[i][j]);
        ret=max(ret,solve(i+1,j+1)+arr[i][j]);
        return dp[i][j]=ret;
    }
    else return 0;
}
 
int main()
{
    BeatMeScanf;
    int t;
    cin>>t;
    while(t--){
        cin>>r>>c;
        int mx=-1;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>arr[i][j];
        for(int i=0;i<c;i++){
            mx=max(mx,solve(0,i));
        }
        cout<<mx<<endl;
    }
    return 0;
}
