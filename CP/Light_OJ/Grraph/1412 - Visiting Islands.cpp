/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define nl '\n'

const int lm = 1e3 + 5, inf = 1e9 ;
int n, m, cs, src1, src2, d, mx_d, lands, mx_lands;
vector <int> g[lm + 2] ;
bool vis[lm + 2] ;
int ans[lm + 2] ;
vector <int> temp ;
vector <pair<int,int>> costs ;

void reset() {
      mx_d = 0 ;
      mx_lands = 0 ;
      costs.clear() ;
      memset(vis, false, sizeof vis) ;
      for(int i=0; i<lm; i++) g[i].clear() ;
}

void dfs(int s, int c) {
      vis[s] = true ;
      temp.pb(s) ;
      for(auto v: g[s]) {
            if(!vis[v]) {
                  lands += 1 ;
                  dfs(v, c + 1) ;
            }
      }
      if(c >= d) d = c, src2 = s ;
}

void solve() {
      scanf("%d %d", &n, &m) ;
      for(int i=0; i<lm; i++) ans[i] = 1e9 ;
      for(int i=1; i<=m; i++) {
            int a, b ; scanf("%d %d", &a, &b) ;
            g[a].pb(b), g[b].pb(a) ;
      }
      for(int i=1; i<=n; i++) {
            if(!vis[i]) {
                  lands = 0 , d = 0, src1 = i ;
                  dfs(src1, 0) ;
                  src1 = src2 ;
                  for(auto v: temp) vis[v] = false ;
                  lands = 0 ;
                  dfs(src1, 0) ;
                  mx_d = max(mx_d, d) ;
                  mx_lands = max(mx_lands, lands + 1) ;
                  costs.pb({lands+1, d}) ;
                  temp.clear() ;
            }
      }
      sort(costs.rbegin(), costs.rend()) ;

      for(int i=0; i<costs.size(); i++) {
            int l = costs[i].ff, dm = costs[i].ss, x ;
            x = dm ;
            for(int j=1; j<=l; j++) {
                  if(j - 1 <= dm) ans[j] = j - 1;
                  else {
                        x += 2 ;
                        ans[j] = min(ans[j], x) ;
                  }
            }
      }

      int q ; scanf("%d", &q) ;
      printf("Case %d:\n", ++cs) ;
      while(q--) {
            int a; scanf("%d", &a) ;
            if(ans[a] == inf) {
                  printf("impossible\n") ;
                  continue ;
            }
            printf("%d\n", ans[a]) ;
      }

      reset() ;
}

int main() {
      int tt = 1, no = 0;
      scanf("%d", &tt) ;
      while(tt--) {
            solve();
      }
      return 0;
}



