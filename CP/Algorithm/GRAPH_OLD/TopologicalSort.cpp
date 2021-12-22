#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false)
vector<int>adj[100];
int vis[100];
vector<int>ts;

void dfs(int u)
{
    BeatMeScanf;
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++){
        if(!vis[adj[u][i]])
            dfs(adj[u][i]);
    }
    ts.push_back(u);
}
int main()
{
    int n,e,a,b;
    cin>>n>>e;
    ts.clear();
    memset(vis,0,sizeof vis);
    for(int i=0;i<e;i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=0;i<n;i++){
        if(!vis[i])
            dfs(i);
    }
    for(int i=ts.size()-1;i>=0;i--)
        cout<<ts[i]<<" ";
    cout<<endl;
    return 0;
}
/*
8 9
0 1
1 3
1 5
1 6
0 4
4 6
3 7
4 7
5 7
*/
/*
8 8
0 1
0 2
1 3
1 2
2 3
2 5
3 4
7 6
*/
