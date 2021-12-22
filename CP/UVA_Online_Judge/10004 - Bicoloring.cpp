/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const int lm = 205 ;
int n, e ;
bool global ;
vector <int> g[lm + 5] ;
bool vis[lm + 5] ;
int color[lm + 5] ;

void dfs(int s, int pv) {
      vis[s] = true ;
      color[s] = pv;
      for(auto v: g[s]) {
            if(color[v] == color[s]) global = false ;
            if(!vis[v]) {
                  color[v] = !pv ;
                  dfs(v, !pv) ;
            }
      }
}

void reset() {
      global = true ;
      for(int i=0; i<lm; i++) g[i].clear() ;
      memset(vis, false, sizeof vis) ;
      memset(color, -1, sizeof color) ;
}
void solve() {
      reset() ;
      for(int i=0; i<e; i++) {
            int a, b ; cin >> a >> b ;
            g[a].pb(b), g[b].pb(a) ;
      }
      dfs(0, 1) ;
      if(global) cout << "BICOLORABLE." << nl ;
      else cout << "NOT BICOLORABLE." << nl ;
}

int main() {
      ios::sync_with_stdio(false);
      cin.tie(0), cout.tie(0);
      int tt = 1, no = 0;
      //cin >> tt ;
      while(cin >> n && n != 0) {
            cin >> e ;
            solve();
      }
      return 0;
}

