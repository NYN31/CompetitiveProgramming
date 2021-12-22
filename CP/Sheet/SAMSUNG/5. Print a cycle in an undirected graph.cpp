

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
int par[sz + 1];
int first = -1, last;


bool isCycle(int s, int parent) {
    color[s] = 0;
    for(int i = 0; i < n; i++) {
        if(adj[s][i]) {
            if(color[i] == -1) {
                par[i] = s;
                if(isCycle(i, s)) return true;
            }
            else if(parent != i) {
                first = i;
                last = s;
                return true;
            }
        }
    }
    return false;
}

void findPath(int x) {
    if(par[x] != first) {
        findPath(par[x]);
    }
    cout << x + 1 << " ";
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
                break;
            }
        }
    }
    if(first == -1) cout << "No Cycle Detected" << endl;
    else if(first == last) cout << "Self loop detected" << endl;
    else {
        cout << first + 1 << " ";
        findPath(last) ;
        cout << first + 1 << endl;
    }
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

