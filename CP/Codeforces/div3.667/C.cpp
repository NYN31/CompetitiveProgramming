#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back

vector<ll> factor(ll diff, vector <ll> &div ) {
	for(int i=1; i*i<=diff; i++) {
		if(diff%i != 0) continue ;
		if(diff/i == i) div.pb(i) ;
		else {
			div.pb(i) ;
			div.pb(diff / i) ;
		}
	}
	return div ;
}


void solve() {
	ll n , a, b; cin >> n >> a >> b;
	vector <ll> div ;
	ll diff = abs(b - a) ;
	factor( diff, div ) ;
	sort(div.begin(), div.end()) ;
		for(int i=0; i<div.size(); i++) {
		vector <ll> ans ;				
		ans.pb(a) ;
		ll d = div[i] , x = a, y = a;
		while(1) {
			if(x+d<=b) {
				ans.pb(x+d) ;					
				x = x+d ;
			}
			else if(x+d>b && y-d > 0) {
				ans.pb(y-d) ;						
				y = y-d ;
			}		
			else {					
				ans.pb(x+d) ;
				x = x+d ;
			}
			if(ans.size() == n) break ;				
		}
		bool flag1 = false , flag2= false ;				
		for(int i=0;i<ans.size();i++) {
				if(ans[i] == a) flag1 = true ;
				if(ans[i] == b) flag2 = true ;
		}
			
		if(flag1 && flag2 && ans.size() == n) {
			for(int i=0;i<ans.size();i++) 
				cout << ans[i] <<" " ;				
			cout << endl;					
			return ;
		}
	}
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