#include<bits/stdc++.h>
using namespace std;
#define MX 100
int parent[MX];
int rankParent[MX];
vector <int> adj[MX];
vector<pair<int, int> > V;
int found = 0;
int Count = 0;

void initializeSet(int n)
{
    for(int i = 0; i<n; i++)
    {
        parent[i] = i;
        rankParent[i] = 0;
    }
}
int Find(int x)
{
    if(x != parent[x])
        return parent[x] = Find(parent[x]);
    else
        return x;
}
void Union(int a, int b)
{
    int k = 1;
    int px = Find(a);
    int py = Find(b);
    if(px == py){
        found = 1;
        Count = Count+1;
        cout << "Here cycle is detected: " << a << " " << b << endl;
        return;
    }
    if(rankParent[px] < rankParent[py])
        parent[px] = py;
    else if(rankParent[px] > rankParent[py])
        parent[py] = px;
    else {
        parent[py] = px;
        rankParent[px]++;
    }
}
int main()
{
    int n, x, y, flag = 0, a,b;
    n = 8;
    initializeSet(n);
    Union(0,1);
    Union(2,3);
    Union(4,5);
    Union(6,7);
    Union(1,3);
    Union(1,4);
    Union(0,2);
    Union(5,7);
    Union(4,6);
    Union(6,3);
    if(found == 1) cout << "Cycle detected" << endl;
    else cout << "Cycle not detected" << endl;
    cout << "Total Cycle is : " << Count << endl;
    return 0;
}
/*
int main()
{
    int n, x, y, flag = 0, e;
    n = 8;
    e = 10;
    initializeSet(n);
    for(int i = 0; i<e; i++){
        cin >> x; cin >> y;
        V.push_back(make_pair(x, y));
    }
    for(int i = 0; i<V.size(); i++)
    {
        x = Find(V[i].first);
        y = Find(V[i].second);
        cout << x << " " << y << endl;
        if(x == y)
        {
            cout << "YES" << endl;
            break;
        }
        Union(x,y);
    }
    cout << "NO" << endl;
    return 0;
}
*/
