/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

const int lm = 1e3 + 5 ;
int s, t, cs ;
vector <int> g[lm + 2] ;
int dis[lm + 2] ;


void graph_create() {
      for(int num = 2; num <= 1000; num += 1) {
            int n = num ;
            for(int p=2; p*p <= n; p++) {
                  if(n % p == 0) {
                        while(n % p == 0) {
                              n /= p ;
                        }
                        if(num + p <= 1000) {
                              g[num].pb(num + p) ;
                        }
                  }
            }
            if(n > 1 && n != num && num + n <= 1000)
                  g[num].pb(num + n);
      }
}

void bfs(int s) {
      dis[s] = 0 ;
      queue <int> q ;
      q.push(s) ;
      while(!q.empty()) {
            int u = q.front() ;
            q.pop() ;

            for(auto v: g[u]) {
                  if(dis[v] == -1) {
                        dis[v] = dis[u] + 1 ;
                        q.push(v) ;
                  }
            }
      }
}

void solve() {
      cin >> s >> t ;
      if(s > t) {
            cout << -1 << nl ;
            return ;
      }
      for(int i=0; i<=lm; i++) dis[i] = -1 ;
      bfs(s) ;
      cout << "Case " << ++cs << ": " ;
      cout << dis[t] << endl ;
}

int main() {
      ios::sync_with_stdio(false);
      cin.tie(0), cout.tie(0);
      graph_create() ;
      int tt = 1, no = 0;
      cin >> tt ;
      while(tt--) {
            solve();
      }
      return 0;
}

/*
5
6 12
6 13
17 34
45 84
32 842
*/

