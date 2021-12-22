Some aplication of DFS:
       1. Finding connected component
       2. Finding the bridge of a graph
       3. Topological sort in DAG
       4. Finding strogly connected component
Complexity of DFS : O(nodes + edges)


problem 1: DFS cycle detection in directed graph using 3 colors.
          complexity O(v + e)
problem 2: DFS cycle detection in undirected graph.
problem 3: given a tree.. you have to find out number of nodes of a subtree
problem 4: given a tree.. each node has a cost. you have to find out total 
	   cost of a subtree.
problem 5: given a tree.. each node has a value. you have to find out max
	   value of a subtree.
problem 6: given a graph.. you also have some colors.. you have to find out
	   is it possible to color the given graph with given colors. but
	   you can not use same color for two adjacent node.
problem 7: DFS Flood fill



/// problem 1: DFS cycle detection in directed graph using 3 colors.

/*
	Visited will contain 3 color
	wihte(-1) -> Node is not visited
	black(0)  -> Node is visted but present in Stack
	green(1)  -> Node is visited and out of stack

	If we found any Node has color 0, there will be a back edge
	If any Back Edge present there will be a cycle
*/
#define white -1
#define black 0
#define green 1

int node, edge;
vector<int>adj[100];
int vis[100];

bool dfs(int s) {
	if(vis[s] == black) return true;
	else if(vis[s] == green) return false;
	
	vis[s] = black;
	bool ans = false;
	for(auto v : adj[s])
		ans = dfs(v);
	
	vis[s] = green;
	return ans;
}

void solve() {
	cin>>node>>edge;
	for(int i=0;i<edge;i++) {
		int a, b; cin>>a>>b;
		adj[a].pb(b);
	}
	memset(vis, white, sizeof vis);
	if(dfs(1)) cout<<"Cycle detected"<<endl;
	else cout<<"There has no cycle"<<endl;
}

/*
	 problem 2: DFS cycle detection in undirected graph.
	 
	 if any vertex s whose any one of adjacent vertex are
	 visited and not same as parent of s, then there's
	 detect a cycle.
*/

int node, edge, cnt;
vector<int>adj[100];
int vis[100];

bool dfs(int s, int par) {
	vis[s] = 1;
	bool ans = false;
	for(auto v : adj[s]) {
		if(!vis[v]) 
			ans = dfs(v, s);
		else if(v != par) 
			return true;
	}
	return ans;
}

void solve() {
	cin>>node>>edge;
	for(int i=0;i<edge;i++) {
		int a, b; cin>>a>>b;
		adj[a].pb(b);
		//adj[b].pb(a);
	}
	memset(vis, 0, sizeof vis);
	if(dfs(1,-1)) cout<<"Cycle detected"<<" "<<cnt<<endl;
	else cout<<"There has no cycle"<<endl;
}

/*
problem 3: given a tree.. you have to find out number of nodes of a subtree
*/

int node, edge;
vector<int>adj[100];
int vis[100], arr[100];

int dfs(int s) {
	if(adj[s].size() == 0) {
		arr[s] = 1;
		return 1;
	}
	vis[s] = 1;
	int ans = 0;
	for(auto v : adj[s]) {
		ans += dfs(v) ;
	}
	arr[s] = ans + 1;
	return arr[s] ;
}

void solve() {
	cin >> node >> edge ;
	for(int i=0;i<edge;i++) {
		int a, b; cin>>a>>b;
		adj[a].pb(b);
	}
	memset(vis, 0, sizeof vis);
	memset(arr, 0, sizeof arr);
	int ans = dfs(1);
	cout<<ans<<endl;
	for(int i=1;i<=node;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	/// While(q--), here will be query part
}



/*
problem 4: given a tree.. each node has a cost. you have to find out total 
	   cost of a subtree.
	   Input 1:
		13 12
		1 2
		1 3
		1 4
		2 5
		2 6
		6 12
		6 13
		3 7
		3 8
		4 9
		4 10 
		4 11
		1 7 1 5 6 3 8 4 5 2 3 1 5

	Output:
		Total cost: 51
		51 22 13 15 6 9 8 4 5 2 3 1 

	Input 2:
		9 8
		1 2
		1 3
		1 4
		3 5
		3 6
		3 7
		6 8
		6 9
		3 5 9 4 1 2 8 6 4
	Output :
		Total cost: 42
		42 5 30 4 1 12 8 6 4 

*/

int node, edge;
vector<int>adj[100];
int vis[100], sum , cost[100];

int dfs(int s) {
	if(adj[s].size() == 0) return cost[s];
	vis[s] = 1;
	int ans = 0;
	for(auto v : adj[s]) {
		ans += dfs(v) ;
	}
	cost[s] += ans;
	return cost[s] ;
}

void solve() {
	cin >> node >> edge ;
	for(int i=0;i<edge;i++) {
		int a, b; cin>>a>>b;
		adj[a].pb(b);
	}
	for(int i=1;i<=node;i++) cin>>cost[i];
	memset(vis, 0, sizeof vis);
	int ans = dfs(1);
	cout<<"Total cost: "<<ans<<endl;
	for(int i=1;i<=node;i++) 
		cout<<cost[i]<<" ";
	cout<<endl;
	/// While(q--), here will be query part
}

/*
problem 7: DFS Flood Fill
*/

#include<bits/stdc++.h>
using namespace std;
#define MX 105

int _x[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int _y[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int vis[MX][MX], row, col;
char F_Fill[MX][MX];

void dfs(int x, int y)
{
    vis[x][y]=1;
    for(int i=0;i<8;i++){
        int a, b;
        a=x+_x[i];
        b=y+_y[i];
        if((a>=1&&a<=row&&b>=1&&b<=col) && !vis[a][b]){
            vis[a][b]=1;
            if(F_Fill[a][b]=='@')
                dfs(a,b);
        }
    }
}

int main()
{
    while(cin>>row>>col && row!=0&&col!=0)
    {
        int cnt=0;
        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
                cin>>F_Fill[i][j];
        memset(vis, 0, sizeof(vis));
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(!vis[i][j] && F_Fill[i][j]=='@'){
                    dfs(i,j); cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
