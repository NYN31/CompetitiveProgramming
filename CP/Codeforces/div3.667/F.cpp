#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back

int n, k ;
string str, ttr ;
int dp[202][202][202] ;

int go(int pos, int mov, int cnt) {
    if(mov > k) return -1000000 ;
    if(pos == n) return 0 ;
    int &ret = dp[pos][mov][cnt] ;
    if(ret != -1) return ret ;
    ret = go(pos+1, mov, cnt + (str[pos] == ttr[0])) + cnt * (str[pos] == ttr[1]) ;
    ret = max(ret, go(pos+1, mov+1, cnt+1) + cnt * (ttr[0] == ttr[1]) ) ;
    ret = max(ret, go(pos+1, mov+1, cnt + (ttr[0] == ttr[1])) + cnt ) ;
    return ret ;
}
void solve() {
    cin >> n >> k;
    cin >> str >> ttr ;

    memset(dp, -1, sizeof dp) ;
    int ans = go(0, 0, 0) ;
    cout << ans << '\n' ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1, no = 0;
   // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
