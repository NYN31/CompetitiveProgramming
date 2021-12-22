#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
 
 
void solve() {
    ll a, b; cin >> a >> b;
    ll ans = (b-1) / (a - 1) ;
    ans += b ;
    cout << ans << endl;
}
  
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1, no = 0;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
/*

// Using Binary Search

int main()
{
    BeatMeScanf;
    int t;
    cin>>t;
    while(t--) {
        ll n,d;
        cin>>n>>d;
        ll lo=1,hi=1e18,mid;
        while(lo<hi) {
           // mid = lo+(hi-lo)/2;
           mid = (lo+hi)/2;
            ll x = mid - mid/n;
            //cout<<x<<" "<<mid<<" "<<lo<<" "<<hi<<endl;
            if(mid%n==0) mid--;
            if(x==d) {
                cout<<mid<<endl;
                break;
            }
            else if(x<=d) lo=mid+1;
            else hi=mid;
        }
    }
    return 0;
}

*/