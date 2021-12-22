#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
 
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define N 18
 
ll n, m ;
vector<int>arr;
 
ll gcd(ll a,ll b) {return b==0? a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a*(b/gcd(a,b));}
 
ll solve(ll pos, ll rem, ll mult = 1) {
    if(rem == 0) {
        ll x = n / mult;
        return x;
    }
    if(pos == m+1) {
        if(rem == 0) {
            ll x = n / mult;
            return x;
        }
        else return 0;
    }
    ll ans = 0;
    ans = solve(pos+1, rem, mult);
    ans += solve(pos+1, rem-1, lcm(mult,arr[pos]));
    return ans;
}
 
int main() {
    int t, no = 0; scanf("%d", &t);
    while(t--) {
        scanf("%lld %lld", &n, &m);
        ll num = 0;
        arr.pb(-1);
        for(int i=1;i<=m;i++) {
            int a ; cin>>a ;
            arr.pb(a);
        }
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        for(int i=1;i<=m;i++) {
            ll ans = solve(1,i);
            if(i%2 == 0)  num -= ans;
            else num += ans;
        }
        printf("Case %d: %lld\n", ++no, n-num);
        arr.clear();
    }
    return 0;
}
