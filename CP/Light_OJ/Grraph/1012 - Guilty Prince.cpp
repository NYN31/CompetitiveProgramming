#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define ff first
#define ss second
#define pb push_back

int const lim = 25;
string grid[lim+5];
int vis[lim+5][lim+5];
int n, m;
int dr[] = {0,-1,0,1};
int dc[] = {1,0,-1,0};

int bfs(int r, int c) {
	int tot = 0;
	vis[r][c] = 1;
	queue<int>qx, qy;
	qx.push(r), qy.push(c);
	while(!qx.empty() && !qy.empty()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();

		for(int i=0;i<4;i++) {
		  int a = x+dr[i];
			int b = y+dc[i];
			if(a<0 || a==n || b<0 || b==m || grid[a][b]=='#') 
				continue;
			if(vis[a][b] == -1) {
				tot += 1;
				vis[a][b] = 1;
				qx.push(a), qy.push(b);
			}
		}
	}
	return tot ;
}

void solve() {
	cin >> n >> m;
	swap(n, m) ;
	int s1, s2;
	for(int i=0;i<n;i++) cin>>grid[i];
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(grid[i][j] == '@'){
				s1 = i, s2 = j;
				break;
			}
		}
	}
	memset(vis, -1, sizeof vis);
	int ans = bfs(s1, s2)+1;
	cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1, no = 0;
    cin >> t;
    while(t--) {
    	cout<<"Case "<<++no<<": ";
        solve();
    }
    return 0;
}
