/*For every visited vertex ‘v’, if there is an adjacent ‘u’ such that u is already
visited and u is not parent of v, then there is a cycle in graph. If we don’t find
such an adjacent for any vertex, we say that there is no cycle. The assumption of
this approach is that there are no parallel edges between any two vertices.*/

#include<bits/stdc++.h>
using namespace std;
int visited[100];
vector<int> adj[100];
int parent[100];

int bfs(int s, int V)
{
    memset(parent, -1, sizeof(parent));
    queue<int>q;
    visited[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(visited[v] == 0)
            {
                visited[v] = 1;
                q.push(v);
                parent[v] = u;
            }
            else if(parent[u] != v){ /// if parent[i] and v are not equal, then the condition becomes true
                cout << u << " " << v << endl; ///here cycle is detected
                return 1;
            }
        }
    }
    return 0;
}
bool isCycle(int V)
{
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= V; i++) /// this for loop use for those node who are not visited
        if (!visited[i] && bfs(i,V))
            return true;
    return false;
}
int main()
{
    int V, a, b, e;
    cin >> V >>e;

    for(int i = 1; i<=e; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (isCycle(V)) cout << "Yes" << endl;
    else cout << "No" << endl;

    for(int i=0;i<=V;i++) cout<<parent[i]<<" ";cout<<endl;
    return 0;
}







/*
BFS cycle detection using 3 color(-1,0,1)


https://www.youtube.com/watch?v=vXrv3kruvwE&fbclid=IwAR10FXKaxUA8Y5pIIQmqOJ3fSiLY7eMbWBgD8sf23Dn6JlrAfoiny6fZhVY

*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<int>g[100];
int vis[100];
int par[100];
int n,e;

bool bfs(int s){
    queue<int>q;
    q.push(s);
    vis[s]=0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0;i<g[u].size();i++){
            int v = g[u][i];
            if(vis[v] == -1){
                q.push(v);
                vis[v]=0;
            }
            else if(vis[v] == 0){
                cout<<"DOKCHE"<<endl;
                return true;
            }
        }
        vis[u]=1;
    }
    return false;
}


int main()
{
    BeatMeScanf;
    cin>>n>>e;
    for(int i=1;i<=e;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(vis, -1, sizeof vis);

    int cn=0;
    bool ok;
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            ok = bfs(i);
        }
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
/*
5 5
1 2
1 3
2 4
2 5
4 5
*/

