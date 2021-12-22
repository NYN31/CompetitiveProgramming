#include<bits/stdc++.h>
using namespace std;
#define MX 10005

vector<pair<pair<int, int>, int> > edge;
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

int kruskal(int n)
{
    sort(edge.begin(), edge.end());
    makeSet(n);
    int edge_count = 0, cost = 0;
    for(int i = 0; i<edge.size(); i++){
        int u, v;
        u = Find(edge[i].first.first);
        v = Find(edge[i].first.second);
        if(u != v){
            parent[v] = u;
            edge_count++;
            cost += edge[i].second;
            cout << edge[i].second << " ";
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
            edge.push_back(make_pair(make_pair(u, v), w));
        }
        cout << kruskal(n) << endl;
    }
    return 0;
}
/*
8 9
0 1 3
1 5 5
1 2 2
5 7 4
2 7 3
2 3 1
7 4 9
3 4 8
4 6 6
*/
