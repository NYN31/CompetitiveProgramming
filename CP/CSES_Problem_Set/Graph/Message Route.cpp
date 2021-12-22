#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define ff first
#define ss second
#define pb push_back

int const lim = 1e5+5;
vector<int>adj[lim+5];
int vis[lim+5];
int par[lim+5];
int n, e;

void bfs(int s) {
	vis[s] = 0;
	queue<int>q;
	q.push(s);
	while(!q.empty()) {
		int u = q.front();
		q.pop() ;
		for(auto v : adj[u]) {
			if(vis[v] == -1) {
				vis[v] = vis[u] + 1;
				par[v] = u;
				q.push(v);
			}
		}
	}
}

void solve() {
	cin >> n >> e;
	for(int i=1;i<=e;i++) {
		int a, b; cin >> a >> b;
		adj[a].pb(b), adj[b].pb(a);
	}
	memset(vis, -1, sizeof vis) ;
	memset(par, -1, sizeof par) ;
	
	for(int i=1;i<=n;i++) {
		if(vis[i] == -1) {
			bfs(i) ;
		}
	}
	int x = n;
	vector<int>pos ;
	while(x != -1) {
		pos.pb(x) ;
		x = par[x] ;
	}
	if(pos[ pos.size()-1 ] == 1) {
		cout<<pos.size()<<endl;
		for(int i=pos.size()-1;i>=0;--i)
			cout<<pos[i]<<" ";
	}else cout<<"IMPOSSIBLE"<<endl;

	return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1, no = 0;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
