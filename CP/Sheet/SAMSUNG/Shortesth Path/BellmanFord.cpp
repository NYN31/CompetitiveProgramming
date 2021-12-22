
/***
Question: Find the shortest path and print the path [BallmenFord]

***/

/*** Md Sajjad Hosen Noyon ***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define nl '\n'
#define sz 20
#define inf 10000000

int n, e;
int graph[sz + 1][3];
int dis[sz + 1];
int par[sz + 1];

void printPath(int src, int dst) {
    if(src != dst) {
        printPath(src, par[dst]);
    }
    cout << dst + 1 << " ";
}

void BellmanFord(int s) {
    dis[s] = 0;

    for(int i=0; i<n-1; i++) { /// update n-1 times all edge
        for(int j=0; j<e; j++) { ///traverse all edge and update dis.
            int u = graph[j][0];
            int v = graph[j][1];
            int c = graph[j][2];

            if(dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c ;
                par[v] = u;
            }
        }
    }

    for(int j=0; j<e; j++) { ///if the edge can still be updated there is negative cycle
        int u = graph[j][0];
        int v = graph[j][1];
        int c = graph[j][2];

        if(dis[u] + c < dis[v]) {
            cout << "Negative cycle detected" << endl;
            return ;
        }
    }
}

void solve() {
    cin >> n >> e ;
    for(int i = 0; i < e ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[i][0] = a;
        graph[i][1] = b;
        graph[i][2] = c;
    }

    for(int i = 0; i < n; i++) dis[i] = inf;

    int source = 0, destination = n - 1;
    BellmanFord(source);

    for(int i = 0; i < n; i++) cout << dis[i] << " "; cout << endl;

    cout << "Shortest path from source to destination is: " ;
    printPath(source, destination);
    cout << endl;
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


/*
3 3
0 1 3
1 2 4
2 0 -10

*/




