/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'

int const dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
int const dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;

int n, no, cnt;
int mat[30][30] ;
bool vis[30][30] ;

void dfs(int r, int c) {
      vis[r][c] = true ;
      queue <int> qr, qc ;
      qr.push(r), qc.push(c) ;
      while(!qr.empty() && !qc.empty()) {
            int x = qr.front(), y = qc.front() ;
            qr.pop(), qc.pop() ;

            for(int i=0; i<8; i++) {
                  int a = x + dr[i] ;
                  int b = y + dc[i] ;

                  if(a >= 0 && a < n && b >= 0 && b < n && mat[a][b] == 1 && !vis[a][b]) {
                        vis[a][b] = true ;
                        qr.push(a), qc.push(b) ;
                  }
            }
      }
}

void reset() {
      cnt = 0 ;
      for(int i=0; i<30; i++) {
            for(int j=0; j<30; j++) {
                  vis[i][j] = false ;
                  mat[i][j] = 0 ;
            }
      }
}

void solve() {
      reset() ;
      for(int i=0; i<n; i++) {
            string s ; cin >> s ;
            for(int j=0; j<s.size(); j++) {
                  (s[j] == '0') ? mat[i][j] = 0: mat[i][j] = 1 ;
            }
      }

      for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                  if(!vis[i][j] && mat[i][j] == 1) {
                        dfs(i, j) ;
                        cnt += 1 ;
                  }
            }
      }
      cout << "Image number " << ++no << " contains " << cnt << " war eagles." << endl ;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);
        int tt = 1, no = 0;
        //cin >> tt ;
        while(cin >> n) {
                solve();
        }
        return 0;
}
