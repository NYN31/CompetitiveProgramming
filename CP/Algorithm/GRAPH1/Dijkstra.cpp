/*
Problem 1 : Dijkstra Algorithm using priority queue.
	    complexity : O( (n+e) * log(n) ).
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>

int const lim = 100;
int const inf = 1e9;
vector<pii>adj[lim+5];
int dis[lim+5], par[lim+5], n, e;

void dij(int src) {
	for(int i=1;i<=n;i++) dis[i] = inf;
	for(int i=1;i<=n;i++) par[i] = -1;
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	
	dis[src] = 0;
	pq.push({0, src}); ///  ff = weight, ss = node;
	while(!pq.empty()) {
		pii temp = pq.top();
		pq.pop();

		int u = temp.ss;
		if(temp.ff > dis[u]) continue;

		for(pii i : adj[u]) {
			int v = i.ss;
			int w = i.ff;

			if(dis[u]+w < dis[v]) {
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
		int u, v, w;
		cin>>u>>v>>w;
		adj[u].pb({w,v});
		adj[v].pb({w,u});
	}
	dij(1);
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
