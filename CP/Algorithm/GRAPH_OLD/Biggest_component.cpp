///Using Union Find Disjoint Set by SIZE and rank also
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
