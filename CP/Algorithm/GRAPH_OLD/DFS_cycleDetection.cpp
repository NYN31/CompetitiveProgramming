/*
Cycle detecting using DFS.. (three coloring system)
*/

#include<bits/stdc++.h>
using namespace std;
int vis[100];
vector<int> adj[100];
int parent[100];
int n,e,cnt;
bool ok;
void dfs(int s)
{
    vis[s] = 0;
    for(int i : adj[s]){
        if(vis[i] == -1){
            vis[i] = 0;
            dfs(i);
        }
        else if(vis[i] == 0)
            cnt++, ok = true;
    }
    vis[s]=1;
}

int main()
{
    cin>>n>>e;

    for(int i = 1; i<=e; i++)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(vis, -1, sizeof vis);
    for(int i=1;i<=n;i++){
        if(vis[i] == -1){
            dfs(i);
        }
    }
    if(ok) cout<<"Cycle is detected"<<endl;
    else cout<<"There is no cycle"<<endl;
    cout<<"Total cycle found: "<<cnt<<endl;

    return 0;
}
