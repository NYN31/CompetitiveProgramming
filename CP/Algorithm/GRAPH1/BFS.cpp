/*
problem 1: Shortest path between two nodes in a grid..!
           complexity : 
problem 2: find number of connected component & shortest distance for every node in a graph...!!
Problem 3: Bipartite check using BFS.
*/


/*
problem 1: Shortest path between two nodes in a grid..!


	BFS grid:
	there is a grid. You have to find out minimal distance from cell (0,0) t0 from
	cell (n-1,m-1). But there is a condition. Some cell has mostar and you can't 
	visit this cell. 
	input :
		4 6
		......
		#..#..
		.#....
		#.#...
                      
	output : Minimum distace: 8
*/

int n, m;
string grid[100];
int dis[100][100];
int dr[] = {0,-1,0,1};
int dc[] = {1,0,-1,0};

void bfs_grid(int r, int c) {
	dis[r][c] = 0;
	queue<int> qx, qy;
	qx.push(r); qy.push(c);
	while(!qx.empty() && !qy.empty()) {
		int top1, top2 ;
		top1 = qx.front(); qx.pop();
		top2 = qy.front(); qy.pop();

		for(int i=0;i<4;i++) {
			int x = top1+dr[i];
			int y = top2+dc[i];

			if(x<0 || x==n || y<0 || y==m || grid[x][y]=='#')
				continue;
			if(dis[x][y] == -1) {
				dis[x][y] = dis[top1][top2]+1;
				qx.push(x), qy.push(y);
			}
		}
	}
}
void solve() {
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>grid[i];

	memset(dis, -1, sizeof dis);
	bfs_grid(0,0);
	cout<<"Minimum distace: "<<dis[n-1][m-1]<<endl;
}


/*
Problem 2: find number of connected component & shortest distance for every node in a graph...!!

           input : 
                      8 6
                      1 2
                      1 3
                      3 5
                      3 4
                      4 6
                      7 8
           output:
                      total_component: 2
                      Distance from every node to other node: 
                      0 1 1 2 2 3 0 1 

*/

int n, e;
vector<int>adj[100];
int vis[100], dis[100];

void bfs(int src) {
	vis[src] = 1;
	dis[src] = 0;
	queue<int>q;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(auto v : adj[u]) {
			if(!vis[v]) {
				vis[v] = 1;
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}

}
void solve() {
	cin>>n>>e;
	for(int i=1;i<=e;i++) {
		int a , b; cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	memset(vis, 0, sizeof vis);
	int total_component = 0;
	for(int i=1;i<=n;i++) {
		if(!vis[i]){
			bfs(i);
			total_component += 1;
		}
	}
	cout<<"total_component: "<<total_component<<endl;
	cout<<"Distance from every node to other node: \n";
	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";cout<<endl;
}

/*
Problem 3: Bipartite check using BFS.
	input:  4 4 	output: The graph is bipartite.
		1 2
		2 3
		3 4
		4 1
*/

int n, e;
bool flag = false ;
vector<int>adj[100];
int color[100];

void bfs(int src) {
	color[src] = 1;
	queue<int>q;
	q.push(src);
	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(auto v : adj[u]) {
			if(color[v] == -1) {
				if(color[u] == 1) color[v]=0;
				else color[v]=1;
				q.push(v);
			}
			else if(color[v] == color[u]) flag = true;
		}
	}

}
void solve() {
	cin>>n>>e;
	for(int i=1;i<=e;i++) {
		int a , b; cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	memset(color, -1, sizeof color);
	bfs(1);
	if(!flag) cout<<"The graph is bipartite"<<endl;
	else cout<<"The graph is not bipartite"<<endl;
}

