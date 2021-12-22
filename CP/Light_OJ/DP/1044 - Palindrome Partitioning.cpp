#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 1010

ll dp[sz][sz],dp2[sz];
string str;

ll palindrome(ll st,ll ed){
    if(st>=ed) return 1;
    if(dp[st][ed]!=-1) return dp[st][ed];
    ll ans=0;
    if(str[st]==str[ed] && palindrome(st+1,ed-1))
        ans=1;
    return dp[st][ed]=ans;
}

ll part(int in){
    if(dp2[in]!=-1) return dp2[in];
    ll ans=INT_MAX;
    if(palindrome(0,in)) ans=1;
    for(int i=in;i>0;--i)
        if(palindrome(i,in)) {
            ans=min(ans,1+part(i-1));
        }
    dp2[in]=ans;
    return ans;
}

int main()
{
    BeatMeScanf;
    int t,no=0;
    cin>>t;
    while(t--){
        cin>>str;
        memset(dp,-1,sizeof dp);
        memset(dp2,-1,sizeof dp2);
        ll ans=part(str.size()-1);
        cout<<"Case "<<++no<<": "<<ans<<endl;
    }
    return 0;
}
