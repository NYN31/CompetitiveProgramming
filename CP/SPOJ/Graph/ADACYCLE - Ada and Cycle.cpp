#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const int lm = 2005, inf = 1e9 ;
vector <int> adj[lm + 5] ;
int vis[lm + 5], dis[lm + 5] ;

int bfs(int src) {
    memset(vis, 0, sizeof vis) ;
    memset(dis, 0, sizeof dis) ;
    vis[src] = 1 ;
    dis[src] = 1 ;
    queue <int> q ;
    q.push(src) ;
    int mn = INT_MAX ;
    while(!q.empty()) {
        int u = q.front() ; q.pop() ;

        for(auto v : adj[u]) {
            if(!vis[v]) {
                vis[v] = 1 ;
                q.push(v) ;
                dis[v] = dis[u] + 1 ;
            }
            if(v == src) {
                mn = dis[u] ;
                return mn ;
            }
        }
    }
    return mn ;
}

void solve() {
    int n ; scanf("%d", &n) ;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int a ; scanf("%d", &a) ;
            if(a) adj[i].pb(j) ;
        }
    }
    for(int i=0; i<n; i++) {
        int val = bfs(i) ;
        if(val == INT_MAX) printf("NO WAY\n") ;
        else printf("%d\n", val) ;
    }

}

int main() {
    int t = 1, no = 0;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
