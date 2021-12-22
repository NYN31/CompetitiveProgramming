/// Tag: Bipartite graph

#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>

int const lim = 100005;

int n, m;
vector<int>adj[lim+5];
int vis[lim+5];
int par[lim+5];
bool notPossible = false;

void bfs(int src) {
	vis[src] = 1;
	queue<int>q;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(auto v : adj[u]) {
			if(vis[v] == -1) {
				if(vis[u] == 1) vis[v] = 2 ;
				else if(vis[u] == 2) vis[v] = 1 ;
				q.push(v);
			}
			else if(vis[u] == vis[v]) {
				notPossible = true;
			}
		}
	}
}

void solve() {
	cin >> n >> m;
	for(int i=1;i<=m;i++) {
		int a, b ; cin>> a >> b;
		adj[a].pb(b), adj[b].pb(a);
	}
	memset(vis, -1, sizeof vis);
	for(int i=1;i<=n;i++) {
		if(vis[i] == -1)  {
			bfs(i);
		}
	}
	if(notPossible) cout<<"IMPOSSIBLE"<<endl;
	else {
		for(int i=1;i<=n;i++)
			cout<<vis[i]<<" ";
		cout<<endl;
	}
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
