
/***
Question: Detect a cycle in an undirected graph

***/

/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'
#define sz 20

int n, e;
int adj[sz + 1][sz + 1];
int color[sz + 1];


/***
using DFS with 3 color [-1, 0, 1] for directed graph

not visited = -1
visited = 0
out of stack = 1

***/

bool isCycle(int s) {
    if(color[s] == 0) return true;
    else if(color[s] == 1) return false;
    color[s] = 0 ;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(adj[s][i]) flag |= isCycle(i);
    }
    color[s] = 1;
    return flag ;
}

void solve() {
    cin >> n >> e ;
    for(int i = 0; i < e ; i++) {
        int a, b ; cin >> a >> b ;
        a--, b--;
        adj[a][b] = 1 ;
    }

    for(int i = 0; i < n; i++) color[i] = -1;

    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            if(isCycle(i)) {
                cout << "contain cycle" << endl ;
                return ;
            }
        }
    }
    cout << "Not contain cycle" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);


    int test = 1, no = 0;
    //cin >> test ;
    while(test--) {
        solve();
    }
    return 0;
}

