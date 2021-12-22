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

int const N = 100;
int node, edge, k;
vector<int> adj[N+5];
bool vis[N+5];

/// Only BackTracking
bool hamilTpath(int u, int cnt) {
    if(cnt == node) return true;
    for(auto v : adj[u]) {
        if(vis[v]) continue;
        vis[v] = true;
        if(hamilTpath(u+1, cnt+1)) return true;
        vis[v] = false;
    }
    return false;
}

int main() {
    cin>>node>>edge;
    for(int i=1;i<=edge;i++) {
        int a, b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bool ans = false;
    for(int i=1;i<=node;i++) {
        vis[i]=true;
        if(hamilTpath(i, 1)) {
            ans = true;
            break;
        }
        vis[i]=false;
    }
    if(ans) cout<<"YES"<<endl;
    else cout<<"NOT POSSIBLE"<<endl;
    return 0;
}


/// Using Bitmask (BackTracking)
int const N = 20;
int node,edge,target;
vector<int>adj[N+1];

int setbit(int mask, int p) {
    return (mask | (1<<p));
}
int chkbit(int mask, int p) {
    return (mask & (1<<p));
}
int togbit(int mask, int p) {
    return (mask ^ (1<<p));
}

bool hmp(int u, int vismask) {
    if(vismask == target) return true;

    for(int v : adj[u]) {
        if(chkbit(vismask, v)) continue;
        if(hmp(v, setbit(vismask, v))) return true;
    }
    return false;
}

int main() {
    BeatMeScanf;
    cin>>node>>edge;
    for(int i=0;i<edge;i++) {
        int a, b; cin>>a>>b; --a; --b;
        adj[a].pb(b), adj[b].pb(a);
    }
    bool flag = false;
    target = (1<<node) - 1;
    for(int i=0;i<node;i++) {
        if( hmp(i, setbit(0, i)) ) {
            flag = true;
            break;
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}


/// Using DP
bool dp[16][(1<<16)+100];
bool hmp(int u, int vismask) {
    if(vismask == target) return true;
    bool &ret = dp[u][vismask];
    if(ret != -1) return ret;
    bool ans = false;
    for(int v : adj[u]) {
        if(!(chkbit(vismask, v))) {
            if(v, setbit(vismask, v)) {
                ans = true;
                break;
            }
        }
    }
    ret = ans;
    return ret;
}

int main() {
    BeatMeScanf;
    cin>>node>>edge;
    for(int i=0;i<edge;i++) {
        int a, b; cin>>a>>b; --a; --b;
        adj[a].pb(b), adj[b].pb(a);
    }
    bool flag = false;
    target = (1<<node) - 1;
    memset(dp, -1, sizeof dp);
    for(int i=0;i<node;i++) {
        if( hmp(i, setbit(0, i)) ) {
            flag = true;
            break;
        }
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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
