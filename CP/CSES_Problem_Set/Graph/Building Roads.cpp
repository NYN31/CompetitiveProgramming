#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define ff first
#define ss second
#define pb push_back

int const lim = 1e5+10;

int n, e;
vector<int>adj[lim+10];
int vis[lim+10];

void bfs(int src) {
	vis[src] = 1;
	queue<int>q;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(auto v : adj[u]) {
			if(!vis[v]) {
				vis[v] = 1;
				q.push(v);
			}
		}
	}

}
void solve() {
	cin>>n>>e;
	for(int i=1;i<=e;i++) {
		int a , b; cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	memset(vis, 0, sizeof vis);
	vector<int>vec;
	for(int i=1;i<=n;i++) {
		if(!vis[i]){
			vec.pb(i);
			bfs(i);
		}
	}
	int ans = vec.size() - 1;
	cout<<max(0, ans)<<endl;
	for(int i=0;i<vec.size()-1;i++)
		cout<<vec[i]<<" "<<vec[i+1]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1, no = 0;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
