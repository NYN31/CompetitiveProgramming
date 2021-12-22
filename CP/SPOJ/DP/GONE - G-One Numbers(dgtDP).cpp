/**
  This is a Digit Dp problem solution
  Problem Link: https://www.spoj.com/problems/GONE/
**/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 100010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
string tostr(ll n) {stringstream rr;rr<<n;return rr.str();}

int const N = 18;

ll prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109};
ll dp[10][80][2];
bool cheak_prime(ll sum) {
    for(auto val : prime)
        if(val == sum) return true;
    return false;
}

ll digitDp(string str, ll pos=0, ll sum=0, ll chk=1){
    if(pos == str.size()) {
        if(cheak_prime(sum)) return 1;
        else return 0;
    }
    ll &ret = dp[pos][sum][chk];
    if(ret != -1) return ret;
    ll ans = 0;
    if(chk == 1) {
        for(ll i=0;i<=str[pos]-'0';i++){
            if(i == str[pos]-'0') ans+=digitDp(str, pos+1, sum+i, 1);
            else ans+=digitDp(str, pos+1, sum+i, 0);
        }
    }else{
        for(ll i=0;i<=9;i++)
            ans+=digitDp(str, pos+1, sum+i, 0);
    }
    ret = ans;
    return ret;
}


int main() {
    BeatMeScanf;
    int t; cin>>t;
    while(t--) {
        ll a, b; cin>>a>>b; --a;
        string x = tostr(a);
        string y = tostr(b);

        memset(dp, -1, sizeof dp);
        ll ans1 = digitDp(y);

        memset(dp, -1, sizeof dp);
        ll ans2 = digitDp(x);

        ll ans = ans1-ans2;
        cout<<ans<<endl;
    }

    return 0;
}
