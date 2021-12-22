#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
#define ff first
#define ss second
#define pb push_back
 
int const lim = 1e4+5;
int cost[lim+5], n , e, cnt ;
vector<int>adj[lim+5];
int vis[lim+5];
 
void ini() {
    for(int i=0;i<lim;i++) adj[i].clear();
    memset(vis, -1, sizeof vis);
}
 
int bfs(int s) {
    int sum = cost[s];
    vis[s] = 1;
    queue<int>q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
 
        for(auto v : adj[u]) {
            if(vis[v] == -1) {
                vis[v] = 1;
                cnt += 1;
                sum += cost[v];
                q.push(v);
            }
        }
    }
    return sum;
}
 
void solve() {
    ini();
    scanf("%d %d", &n, &e);
    for(int i=1;i<=n;i++) scanf("%d", &cost[i]);
    for(int i=0;i<e;i++) {
        int a , b;  scanf("%d %d", &a, &b);
        adj[a].pb(b); adj[b].pb(a);
    }
 
    vector<int>arr;
    int comp = 0;
    bool flag = false;
    for(int i=1;i<=n;i++) {
        if(vis[i] == -1) {
            comp += 1;
            int val = bfs(i);
            if(val%(cnt+1) != 0) {
                flag = true;
            }
            int c = val/(cnt+1);
            arr.pb(c);
            cnt = 0;
        }
    }
    if(flag) printf("No\n");
    else if(arr.size() == comp) {
        bool flag = true;
        for(int i=0;i<arr.size()-1;i++) {
            if(arr[i]!=arr[i+1]) {
                flag = false;
                break;
            }
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    else printf("No\n");
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
 
    int t = 1, no = 0;
    scanf("%d", &t);
    while(t--) {
        printf("Case %d: ", ++no);
        solve();
    }
    return 0;
}
