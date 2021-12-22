#include<bits/stdc++.h>
using namespace std;
vector<int>adj[105];
int vis[105];
vector<int>ts;

void dfs(int u)
{
    vis[u]=true;
    for(int i=0;i<adj[u].size();i++){
        if(vis[adj[u][i]]==false)
            dfs(adj[u][i]);
    }
    ts.push_back(u);
}
int main()
{
    int n,e,a,b;
    while(cin>>n>>e)
    {
        if(n==0&&e==0) break;
        ts.clear();
        memset(vis,false,sizeof vis);
        for(int i=0;i<e;i++){
            cin>>a>>b;
            adj[a].push_back(b);
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==false)
                dfs(i);
        }

        cout<<ts[ts.size()-1];
        for(int i=ts.size()-2;i>=0;i--)
            cout<<" "<<ts[i];
        cout<<endl;
        for(int i=0;i<=n;i++) adj[i].clear();
    }
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
