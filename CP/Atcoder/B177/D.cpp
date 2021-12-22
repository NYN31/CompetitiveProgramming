#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back
 
int const lim = 2e5+5;
int n , m ;
vector<int>adj[lim+5];
int vis[lim+5];
 
int bfs(int s) {
	vis[s] = 1;
	queue<int>q;
	q.push(s) ;
	vector<int>st;
	st.clear();
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		st.pb(u);
		for(auto v : adj[u]) {
			if(vis[v] == -1) {
				vis[v] = 1;
				q.push(v) ;
			}
		}
	}
	int len = st.size() ;
	return len ;
}
 
void solve() {
	cin >> n >> m;
	for(int i=1;i<=m;i++) {
		int a, b ; cin >> a >> b;
		adj[a].pb(b) , adj[b].pb(a);
	}
	memset(vis, -1, sizeof vis);
	int mx = 0;
	for(int i=1;i<=n;i++) {
		if(vis[i] == -1) {
			mx = max(mx, bfs(i)) ;
		}
	}
	cout<<mx<<endl;
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