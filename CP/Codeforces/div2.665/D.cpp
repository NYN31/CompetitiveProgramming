#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define ff first
#define ss second
#define pb push_back

ll const lim = 1e5+5;
ll const mod = 1000000007;
vector <ll> adj[lim+5] ;
ll vis[lim+5] , n ;
vector <ll> count_edge ;
ll child[lim+5] ;

void all_clear() {
	count_edge.clear() ;
	for(ll i=1;i<=lim;i++) {
		adj[i].clear() ; vis[i] = -1;
		child[i] = 0;
	}
}

int dfs(ll s) {
	vis[s] = 1;
	ll x = 0, flag = 0;
	for(auto v : adj[s]) {
		if(vis[v] == -1) {
			x += dfs(v) ; flag = 1;
		}
	}
	if(flag == 0) {child[s] = 1; return 1 ; }
	child[s] = x + 1;
	return child[s] ;
}

void solve() {
	cin >> n;
	all_clear() ;
	for(int i=1; i<n; i++) {
		ll a, b; cin >> a >> b;
		adj[a].pb(b) , adj[b].pb(a) ;
	}
	ll m ; cin >> m ;
	vector <ll> fact ;
	for(int i=0; i<m; i++) {
		ll p ; cin >> p;
		fact.pb(p) ;
	}
	ll x = dfs(1) ;
	for(int i=1;i<=n;i++) {
		ll val = child[i] * (n - child[i]) ;
		if(val != 0) count_edge.pb( val ) ;
	}

	sort(count_edge.rbegin(), count_edge.rend()) ;
	sort(fact.rbegin(), fact.rend()) ;
	for(int i=0; i<count_edge.size(); i++) count_edge[i] %= mod ;

	ll ans = 0;
	if(fact.size() > count_edge.size()) {
		while(fact.size() > count_edge.size()) {
			ll val = fact[0] ;
			fact.erase(fact.begin()) ;
			fact[0] = (fact[0] * val) % mod ;
		}
		for(int i=0; i<fact.size(); i++)
			ans = ( ans + (fact[i] * count_edge[i]) % mod) % mod ;

	}
	else {
		for(int i=0; i<count_edge.size(); i++) {
			if(i >= fact.size()) ans = (ans + count_edge[i]) % mod;
			else  ans = ( ans + (fact[i] * count_edge[i]) % mod ) % mod ;
		}
	}
	cout << ans << endl ;
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
