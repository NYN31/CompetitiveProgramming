/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define nl '\n'

int n, cs ;
map <ll, ll> dist ;

void bfs(ll s, map <ll, vector<ll> > g) {
      dist[s] = 0 ;
      queue <int> q ;
      q.push(s) ;
      while(!q.empty()) {
            int u = q.front() ; q.pop() ;

            for(auto v: g[u]) {
                  if(dist[v] == -1) {
                        dist[v] = dist[u] + 1 ;
                        q.push(v) ;
                  }
            }
      }
}

void solve() {
      map <ll, vector<ll> > g ;
      for(int i=1; i<=n; i++) {
            ll a, b ; cin >> a >> b ;
            g[a].pb(b), g[b].pb(a) ;
            dist[a] = dist[b] = -1 ;
      }

      ll a, b ;
      while(cin >> a >> b) {
            if(a == 0 && b == 0) break ;
            bfs(a, g) ;
            ll tot = 0 ;
            for(auto x: dist) {
                  if(x.ss > b || x.ss == -1) tot += 1 ;
                  dist[x.ff] = -1 ;
            }
            dist[a] = -1 ;
            //Case 1: 5 nodes not reachable from node 35 with TTL = 2.
            cout << "Case " << ++cs << ": " << tot << " nodes not reachable from node " << a << " with TTL = " << b << "." << nl ;
      }
      dist.clear() ;
}

int main() {
      ios::sync_with_stdio(false);
      cin.tie(0), cout.tie(0);
      int tt = 1, no = 0;
      //cin >> tt ;
      while(cin >> n && n != 0) {
            solve();
      }
      return 0;
}
