#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 1010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
 
const int mod = 1e9+7;
int n,tot=0;
int dp[100005][105];
int coins[105];
 
vector<int>vec;
 
int call(int rem, int pos) {
    if(pos==n+1) return 0;
    int &ret = dp[rem][pos];
    if(ret != -1) return ret;
    int ans = 0;
    if(rem+coins[pos]<=tot){
        ans = call(rem+coins[pos], pos+1);
        vec.pb(rem+coins[pos]);
    }
    ans = call(rem,pos+1);
    dp[rem][pos]=ans;
    return ans;
}
 
int main()
{
    BeatMeScanf;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>coins[i];
        tot+=coins[i];
    }
    set<int>st;
    set<int>::iterator it;
    memset(dp,-1,sizeof dp);
    int ans = call(0, 1);
    for(int i=0;i<vec.size();i++) st.insert(vec[i]);
    cout<<st.size()<<endl;
    for(it=st.begin();it!=st.end();it++)
        cout<<*(it)<<" ";
    cout<<endl;
    return 0;
}
