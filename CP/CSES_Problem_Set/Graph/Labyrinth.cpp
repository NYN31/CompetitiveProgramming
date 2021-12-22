/// Tags: BFS grid + shortest path + solution print

#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define ff first
#define ss second
#define pb push_back
#define pii pair<int,int>

int const lim = 1005;

int n, m;
string grid[lim+5];
int dis[lim+5][lim+5];
pii par[lim+5][lim+5];
pii src, des ;
int const dr[] = { 0, 0, 1, -1, -1, -1, 1, 1 } ;
int const dc[] = { 1, -1, 0, 0, -1, 1, -1, 1 } ;

void bfs(int r, int c) {
	int tot = 0;
	dis[r][c] = 0;
	queue<int>qx, qy;
	qx.push(r), qy.push(c);
	while(!qx.empty() && !qy.empty()) {
		int x = qx.front(); qx.pop();
		int y = qy.front(); qy.pop();

		for(int i=0;i<4;i++) {
			int a = x+dr[i];
			int b = y+dc[i];

			if(a<0 || a==n || b<0 || b==m || grid[a][b] == '#' || dis[a][b] != -1)
				continue;
			if(dis[a][b] == 'B') {
				dis[a][b] = dis[x][y] + 1;
				par[a][b] = {x,y};
				return ;
			}
			dis[a][b] = dis[x][y] + 1;
			par[a][b] = {x,y};
			qx.push(a), qy.push(b);
		}
	}
}
char direction(int a, int b, int c, int d) {
	if(d > b) return 'R' ;
	if(c < a) return 'U' ;
	if(d < b) return 'L' ;
	if(c > a) return 'D' ;
}
void print(int r, int c) {
	if(r == src.ff && c == src.ss) return ;
	pii temp = par[r][c];
	print(temp.ff, temp.ss);
	//cout<<temp.ff<<" "<<temp.ss<<endl;
	cout<<direction(temp.ff, temp.ss, r, c);
}
void solve() {
	cin >> n >> m;
	for(int i=0;i<n;i++) cin>>grid[i];
	memset(dis, -1, sizeof dis) ;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(grid[i][j] == 'A') src = {i, j} ;
			if(grid[i][j] == 'B') des = {i, j} ;
		}
	}
	bfs(src.ff, src.ss);
	int distance = dis[des.ff][des.ss];
	if(distance == -1) cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl<<distance<<endl;

		print(des.ff, des.ss);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1, no = 0;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
