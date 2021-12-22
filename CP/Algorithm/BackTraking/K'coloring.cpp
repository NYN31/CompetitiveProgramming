#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 100010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

int const mod = 1e9;
int const N = 100;

int node, edge, k;
vector<int> adj[N+5];
int color[N+5];

bool isUsable(int u, int c) { 
    for(auto v : adj[u])
        if(color[v] == c) return false; /// if color[v] & c are equal then we can't use color c
    return true;
}

bool coloring(int u) {
    if(u > node) return true;
    for(int c=1;c<=k;c++) {
        if(isUsable(u,c)){
            color[u]=c; /// if color[v] & c aren't equal then we can use color c
            if( coloring(u+1) ) return true;
            color[u] = 0;
        }
    }
}

int main()
{
    BeatMeScanf;
    cin>>node>>edge>>k;
    for(int i=1;i<=edge;i++) {
        int a, b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool ans = coloring(1);
    if(ans) {
        for(int i=1;i<=node;i++)
            cout<<i<<"--->"<<color[i]<<endl;
    }
    else cout<<"NOT possible"<<endl;
    return 0;

}

/*
8 14 3
1 2
1 3
1 4
2 4
2 6
2 8
3 5
3 8
4 6
4 7
5 7
5 8
6 7
7 8
*/
