/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define nl '\n'

const int lm = 185;
int dr[] = {0, -1, 0, 1};
int dc[] = {1, 0, -1, 0};


void solve(){
     int n, m ;
     int dis[lm + 5][lm + 5] ;
     string grid[lm + 5] ;

     cin >> n >> m ;
     for(int i=0; i<n; i++) {
            cin >> grid[i] ;
     }

     queue<int> qx, qy;
     for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                  if(grid[i][j] == '1') {
                        qx.push(i), qy.push(j);
                  }
                  dis[i][j] = 0 ;
            }
     }

	while(!qx.empty() && !qy.empty()) {
		int top1, top2 ;
		top1 = qx.front(); qx.pop();
		top2 = qy.front(); qy.pop();

		for(int i=0;i<4;i++) {
			int x = top1+dr[i];
			int y = top2+dc[i];

			if(x < 0 || x == n || y < 0 || y == m || grid[x][y] == '1' || dis[x][y] != 0)
                        continue ;
                  dis[x][y] = dis[top1][top2] + 1 ;
                  qx.push(x), qy.push(y) ;
		}
	}



     for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                  cout << dis[i][j] << " " ;
            }
            cout << endl ;
     }

}

int main() {
      int test = 1, no = 0;
      cin >> test;
      while(test--) {
            solve();
      }
      return 0;
}


/*
2
3 4
0001
0011
0110
3 4
0001
0011
0110
*/
