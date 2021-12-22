#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 5005
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
 
string str,btr;
int dp[sz][sz];
 
int solve(int i,int j) {
    if(str[i]=='\0') return btr.size()-j;
    if(btr[j]=='\0') return str.size()-i;
    int &ret = dp[i][j];
    if(ret != -1) return ret;
    if(str[i] == btr[j]) dp[i][j]=solve(i+1,j+1);
    else dp[i][j]=1+min({solve(i+1,j), solve(i,j+1), solve(i+1,j+1)});
    return dp[i][j];
}
 
int main()
{
    BeatMeScanf;
    cin>>str>>btr;
    memset(dp,-1,sizeof dp);
    int ans = solve(0,0);
    cout<<ans<<endl;
    return 0;
}
