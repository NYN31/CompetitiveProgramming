#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back
#define pii pair<ll, ll>
 
ll const lim = 100010;
ll const inf = 1e15;
vector<pii>adj[lim+5];
ll dis[lim+5], par[lim+5], done[lim+5], n, e;
priority_queue<pii, vector<pii>, greater<pii> > pq;
 
void dij(int src) {
	for(int i=1;i<=n;i++) dis[i] = inf;
	
	dis[src] = 0;
	pq.push({0, src});
	while(!pq.empty()) {
		pii temp = pq.top();
		pq.pop();
		int u = temp.ss;
		if(temp.ff > dis[u]) continue;
		done[u] = 1;
		for(int i=0;i<adj[u].size();i++) {
			ll v = adj[u][i].ss;
			ll w = adj[u][i].ff;
 
			if(!done[v] && (dis[u]+w < dis[v]) ) {
				dis[v] = dis[u]+w;
				par[v] = u;
				pq.push({dis[v], v});
			}
		}
	} 
}

void solve() {
	cin>>n>>e;
	for(int i=1;i<=e;i++) {
		ll u, v, w;
		cin>>u>>v>>w;
		adj[u].pb({w,v});
	}
	dij(1);
	for(int i=1;i<=n;i++)
		cout<<dis[i]<<" ";
	cout<<endl;
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
