

#include<iostream>
using namespace std;
#define sz 100

int n, e;
int adj[sz][sz];


bool isBicolorable(int u, int color[]) {
    if(adj[u][u]) return false;

    bool flag = true ;
    for(int i=1; i<=n; i++) {
        if(adj[u][i]) {
            if(color[i] == -1) {
                color[i] = 1 - color[u];
                flag = flag & isBicolorable(i, color);
            }
            else if(color[i] == color[u]) return false;
        }
    }

    return flag ;
}


int main() {
    cin >> n >> e ;

    for(int i=1; i<=e; i++) {
        int u, v ;
        cin >> u >> v ;
        adj[u][v] = 1 ;
        adj[v][u] = 1 ;
    }

    int color[n];
    for(int i=1; i<=n; i++) color[i] = -1;

    for(int i=1; i<=n; i++) {
        if(color[i] == -1) {
            if(!isBicolorable(i, color)) {
                cout << "-1" << endl ;
                return 0 ;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        cout << color[i] << " " ;
    }
    cout << endl;

    return 0;
}
