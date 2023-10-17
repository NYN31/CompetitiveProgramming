#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> ranks, par, sz;

    DisjointSet(int n)
    {
        ranks.resize(n + 1, 0);
        par.resize(n + 1);
        sz.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == par[node])
            return node;
        return par[node] = findUPar(par[node]);
    }

    void unionByranks(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (ranks[ulp_u] < ranks[ulp_v])
        {
            par[ulp_u] = ulp_v;
        }
        else if (ranks[ulp_v] < ranks[ulp_u])
        {
            par[ulp_v] = ulp_u;
        }
        else
        {
            par[ulp_v] = ulp_u;
            ranks[ulp_u]++;
        }
    }

    void unionBysz(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (sz[ulp_u] < sz[ulp_v])
        {
            par[ulp_u] = ulp_v;
            sz[ulp_v] += sz[ulp_u];
        }
        else
        {
            par[ulp_v] = ulp_u;
            sz[ulp_u] += sz[ulp_v];
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionBysz(1, 2);
    ds.unionBysz(2, 3);
    ds.unionBysz(4, 5);
    ds.unionBysz(6, 7);
    ds.unionBysz(5, 6);
    // if 3 and 7 same or not
    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionBysz(3, 7);

    if (ds.findUPar(3) == ds.findUPar(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}
