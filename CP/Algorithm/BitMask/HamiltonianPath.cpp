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

int const N = 20;
int node,edge,target;
vector<int>adj[N+1];
bool dp[16][(1<<16)+100];

int setbit(int n,int pos){ return (n|(1<<pos)); }
bool checkbit(int n,int pos){ return (bool)(n&(1<<pos)); }
int tooglebit(int n,int pos){ return (n^(1<<pos)); }

bool hmp(int u, int vismask) {
    if(vismask == target) return true;
    bool &ret = dp[u][vismask];
    if(ret != -1) return ret;
    bool ans = false;
    for(int v : adj[u]) {
        if(!(checkbit(vismask, v))) {
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
