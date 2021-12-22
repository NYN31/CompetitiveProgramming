#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, e;
int vis[100];
int distances[100];
vector<int>adj[100];

class DFS_BFS{
    public:
    void input()
    {
        int a, b;
        memset(vis, -1, sizeof(vis));
        cin>> n >> e;
        for(int i = 1; i<=e; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);

        }
    }
    void bfs(int x)
    {
        vis[x] = 1;
        queue <ll> q;
        q.push(x);
        while(!q.empty())
        {
            ll node = q.front();
            q.pop();
            for(ll i = 0; i<adj[node].size(); i++)
            {
                ll v = adj[node][i];
                if(vis[adj[node][i]] == -1)
                {
                    vis[v] = 1;
                    distances[v] = vis[node]+1;
                    q.push(v);
                }
            }
        }
    }
    void dfs(int src)
    {
        stack<int>s;
        s.push(src);
        vis[src] = 1;

        while(!s.empty())
        {
            int u = s.top();
            int flag = 0 ;
            for(int i = 0; i < adj[u].size(); i++)
            {
                int ans = adj[u][i];

                if(vis[ans] == -1)
                {
                    s.push(ans);
                    vis[ans] = 1;
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) s.pop();
        }
    }
    void dist(int x)
    {
        memset(distances, -1, sizeof(distances));
        distances[x] = 0;
        queue <ll> q;
        q.push(x);
        while(!q.empty())
        {
            ll node = q.front();
            q.pop();
            for(ll i = 0; i<adj[node].size(); i++)
            {
                ll v = adj[node][i];
                if(distances[adj[node][i]] == -1)
                {
                    distances[v] = distances[node]+1;
                    q.push(v);
                }
            }
        }
    }

};

int main()
{
    DFS_BFS ob1;
    
    ob1.input();
    ob1.bfs(1);
    cout << "For BFS: ";
    for(int i = 1; i<=n; i++)
        cout << vis[i] << " ";
    cout << endl;
    
    
    ob1.input();
    ob1.dfs(1);
    cout << "For DFS: ";
    for(int i = 1; i<=n; i++)
        cout << vis[i] << " ";
    cout << endl;
    
    
    ob1.dist(5);
    cout << "Distance from node 5: ";
    for(int i = 1; i<=n; i++)
        cout << distances[i] << " ";
    cout << endl;
    
    return 0;
}

/*
5 7
1 2
1 3
1 4
2 4
2 5
4 3
4 5
*/
