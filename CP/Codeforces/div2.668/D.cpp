#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back

int const lim = 1e5+5 ;

int n, e, a, b, da, db, src1, src2, dia ;
vector <int> adj[lim + 2] ;
bool vis[lim + 2] ;
int dis[lim + 2] ;

void all_clear() {
	for(int i=0; i<=lim; i++) adj[i].clear() ;
	memset(vis, false, sizeof vis) ;
	memset(dis, 0, sizeof dis) ;
	src1 = 0, src2 = 0, dia = 0 ;
}
void bfs(int src) {
	vis[src] = true ;
	queue <int> q ;
	q.push(src) ;
	while(!q.empty()) {
		int u = q.front() ;
		q.pop() ;

		for(auto v : adj[u]) {
			if(!vis[v]) {
				dis[v] = dis[u] + 1;
				vis[v] = true ;
				q.push(v) ;
				if(dia < dis[v]) {
					dia = dis[v] ;
					src2 = v ;
				}
			}
		}
	}
}

void solve() {
	all_clear() ;

	cin >> n >> a >> b >> da >> db ;
	for(int i=1; i<=n-1; i++) {
		int x, y ; cin >> x >> y;
		adj[x].pb(y), adj[y].pb(x) ;
	}
	src1 = a;
	memset(vis, false, sizeof vis) ;
	bfs(src1) ;
	if(dis[b] <= da) {
		cout << "Alice" << endl; 
		return ;
	}
	memset(dis, 0, sizeof dis) ;
	memset(vis, false, sizeof vis) ;
	dia = 0, src1 = src2 ;
	bfs(src1) ;
	
	da = min(da, dia), db = min(db, dia) ;
	if(2*da < db) cout << "Bob" << endl ;
	else cout << "Alice" << endl ;

	
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