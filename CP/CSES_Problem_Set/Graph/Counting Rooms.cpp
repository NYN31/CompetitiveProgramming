#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define ff first
#define ss second
#define pb push_back

int const lim = 1e3+5;
int n, m; 
string grid[lim+5];
int vis[lim+5][lim+5];

int dr[] = {0,-1,0,1};
int dc[] = {1,0,-1,0};

void bfs_grid(int r, int c) {
	vis[r][c] = 1;
	queue<int>qx,qy;
	qx.push(r); qy.push(c);
	while(!qx.empty() && !qy.empty()) {
		int x = qx.front(), y = qy.front();
		qx.pop(); qy.pop();

		for(int i=0;i<4;i++) {
			int a = x+dr[i];
			int b = y+dc[i];

			if(a<0 || a==n || b<0 || b==m || grid[a][b]=='#')
				continue;
			if(vis[a][b] == -1) {
				vis[a][b] = vis[x][y]+1;
				qx.push(a); qy.push(b);
			}
		}
	}
}

void solve() {
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>grid[i];
	memset(vis, -1, sizeof vis) ;
	int room = 0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(vis[i][j] == -1 && grid[i][j] == '.') {
				room += 1;
				bfs_grid(i, j);
			}
		}
	}
	cout<<room<<endl;
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
