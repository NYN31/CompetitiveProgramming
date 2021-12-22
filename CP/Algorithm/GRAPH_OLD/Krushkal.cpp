#include<bits/stdc++.h>
using namespace std;
#define MX 10005

struct node{
    int u, v, w;
    node(int a, int b, int c) {
        u = a;
        v = b;
        w = c;
    }
    bool operator<(const node& p) const
    {
        return w < p.w;
    }
};
vector<node>edge;
int parent[MX];

void makeSet(int n){
    for(int i = 0; i<n; i++)
        parent[i] = i;
}

int Find(int x)
{
    if(x != parent[x])
        return parent[x] = Find(parent[x]);
    else
        return x;
}

int krushkal(int n)
{
    sort(edge.begin(), edge.end());
    makeSet(n);
    int edge_count = 0, cost = 0;
    for(int i = 0; i<(int)edge.size(); i++){
        int u, v;
        u = Find(edge[i].u);
        v = Find(edge[i].v);
        if(u != v){
            parent[v] = u;
            edge_count++;
            cost += edge[i].w;
            if(edge_count == n-1)
                break;
        }
    }
    return cost;
}

int main()
{
    int n, e;
    while(cin >> n >> e)
    {
        for(int i=1; i<=e; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edge.push_back(node(u,v,w));
        }
        cout << krushkal(n) << endl;
    }
    return 0;
}
