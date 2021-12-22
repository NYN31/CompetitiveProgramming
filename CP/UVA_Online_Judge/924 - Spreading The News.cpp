/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define nl '\n'

const int lm = 2550 ;
int e, q, b, d;
vector <int> g[lm + 2] ;
bool vis[lm + 2] ;

void bfs(int s) {
      vis[s] = true ;
      queue <int> q1, q2 ;
      q1.push(s) ;
      int mx_b = 0, day = 0;
      while(!q1.empty() || !q2.empty()) {
            day += 1 ;
            while(!q1.empty()) {
                  int u = q1.front() ; q1.pop() ;
                  for(auto v: g[u]) {
                        if(!vis[v]) {
                              mx_b += 1 ;
                              vis[v] = true ;
                              q2.push(v) ;
                        }
                  }
            }
            if(mx_b > b) {
                  b = mx_b ;
                  d = day ;
            }
            mx_b = 0 ;
            day += 1 ;
            while(!q2.empty()) {
                  int u = q2.front() ; q2.pop()  ;
                  for(auto v: g[u]) {
                        if(!vis[v]) {
                              mx_b += 1 ;
                              vis[v] = true ;
                              q1.push(v) ;
                        }
                  }
            }
            if(mx_b > b) {
                  b = mx_b ;
                  d = day ;
            }
            mx_b = 0 ;
      }
}

void solve() {
      cin >> e ;
      for(int i=0; i<e; i++) {
            int n ; cin >> n ;
            while(n--) {
                  int a ; cin >> a ;
                  g[i].pb(a) ;
            }
      }

      cin >> q ;
      while(q--) {
            int a ; cin >> a ;
            memset(vis, false, sizeof vis) ;
            bfs(a) ;
            if(b == 0 && d == 0) cout << 0 << nl ;
            else cout << b << " " << d << nl ;
            b = d = 0 ;
      }
}

int main() {
      ios::sync_with_stdio(false);
      cin.tie(0), cout.tie(0);
      int tt = 1, no = 0;
      //cin >> tt ;
      while(tt--) {
            solve();
      }
      return 0;
}
