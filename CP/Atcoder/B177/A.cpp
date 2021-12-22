#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back
 
 
void solve() {
	ll d, t, s; cin >> d >> t >> s;
	ll mul = t * s ;
	if(mul >= d) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
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