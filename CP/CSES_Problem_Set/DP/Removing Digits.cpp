#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 1000100
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
 
const int mod = 1e9+7;
 
ll cnt;
 
ll solve(ll n) {
    if(n==0) return 0;
    ll num = n, mx = 0,ans;
    while(num) {
        ll rem = num%10;
        num /= 10;
        mx = max(rem,mx);
    }
    ans = solve(n-mx)+1;
    return ans;
}
 
int main()
{
    BeatMeScanf;
    ll n;
    cin>>n;
    ll ans = solve(n);
    cout<<ans<<endl;
    return 0;
}
