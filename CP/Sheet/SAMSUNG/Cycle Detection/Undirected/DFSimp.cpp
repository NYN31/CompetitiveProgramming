
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


bool isCycle(int s, int parent) {
    color[s] = 0;
    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(adj[s][i]) {
            if(color[i] == -1) {
                flag = isCycle(i, s);
            }
            else if(parent != i) {
                return true;
            }
        }
    }
    return flag;
}

void solve() {
    cin >> n >> e ;
    for(int i = 0; i < e ; i++) {
        int a, b ; cin >> a >> b ;
        a--, b--;
        adj[a][b] = 1 ;
        adj[b][a] = 1 ;
    }

    for(int i = 0; i < n; i++) color[i] = -1;

    for(int i = 0; i < n; i++) {
        if(color[i] == -1) {
            if(isCycle(i, -1)) {
                cout << "Cycle Detected" << endl ;
                return ;
            }
        }
    }
    cout << "No Cycle Detected" << endl;
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

