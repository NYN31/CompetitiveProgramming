/// Using BFS

#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false)
int color[30000];
vector<int>adj[30000];

int BFS(int s)
{
    int c = 1;
    queue<int>q;
    color[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int v, u = q.front();
        q.pop();
        for(int i = 0; i<adj[u].size(); i++)
        {
            v = adj[u][i];
            if(color[v] == -1){
                color[v] = 1;
                c++;
                q.push(v);
            }
        }
    }
    return c;
}

int main()
{
    BeatMeScanf;
    int n,e, t,no = 0;
    cin >> t;
    while(t--)
    {
        memset(color, -1, sizeof color);
        int a, b, N = 1, Max;
        cin>>n>>e;
        for(int i=1;i<=e;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 1; i<=n; i++)
        {
            if(color[i] == -1)
            {
                Max = BFS(i);
                if(Max>N){
                    N = Max;
                }
            }
        }
        cout << N << endl;
        for(int i = 1; i<=n; i++) adj[i].clear();
    }
    return 0;
}

/*
///Using Union Find Disjoint Set
#include<bits/stdc++.h>
using namespace std;
int parent[30005];
int rankParent[30005];
int ans[30005];

void makeSet(int n)
{
    for(int i = 0; i<n; i++){
        parent[i] = i;
        rankParent[i] = 0;
        ans[i] = 1;
    }
}
int Find(int x)
{
    if(x != parent[x])
        return parent[x] = Find(parent[x]);
    else
    {
        return x;
    }
}
void Union(int a, int b)
{
    int px = Find(a);
    int py = Find(b);
    if(rankParent[px]<rankParent[py]){
        parent[px] = py;
        ans[py] += ans[px];
    }
    else if(rankParent[px]>rankParent[py]){
        parent[py] = px;
        ans[px] += ans[py];
    }
    else{
        parent[py] = px;
        rankParent[px]++;
        ans[px] += ans[py];
    }

}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, e, a, b;
        cin >> n >> e;
        makeSet(n);
        for(int i = 1; i<=e; i++)
        {
            cin >> a >> b;
            a--; b--;
            if(Find(a) == Find(b))
                continue;
            Union(a, b);
        }
        cout << *max_element(ans, ans+n) << endl;
    }
    return 0;
}

*/
