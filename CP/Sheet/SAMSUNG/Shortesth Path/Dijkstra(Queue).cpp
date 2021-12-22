
/***
Question: Find the shortest path and print the path [Dijkstra]

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
int adj[sz + 1][sz + 1];
int cost[sz + 1][sz + 1];
int dis[sz + 1];
int par[sz + 1];

class Queue{
    int topId, frontId;
    int arr[sz + 1];
public:
    Queue(){topId=-1, frontId = 0;}
    int push(int x){arr[++topId]=x;}
    int peek(){ return arr[frontId]; }
    void pop(){ ++frontId;}
    bool isEmpty(){return frontId>topId;}
};

void BFSmodified(int src) {
    Queue q;
    q.push(src);
    dis[src] = 0;
    while(!q.isEmpty()) {
        int u = q.peek(); q.pop();

        if(dis[u] == inf){
            break;
        }

        for(int v=0; v<n; v++) {
            if(adj[u][v]) {
                if(dis[u] + cost[u][v] < dis[v]) { /// edge relaxation
                    q.push(v);
                    dis[v] = dis[u] + cost[u][v];
                    par[v] = u;
                }
            }
        }
    }
}

void printPath(int src, int dst) {
    if(src != dst) {
        printPath(src, par[dst]);
    }
    cout << dst + 1 << " ";
}

void solve() {
    cin >> n >> e ;
    for(int i = 0; i < e ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a][b] = 1;
        adj[b][a] = 1;
        cost[a][b] = c;
        cost[b][a] = c;
    }

    for(int i = 0; i < n; i++) dis[i] = inf;

    int source = 0, destination = n - 1;
    BFSmodified(source);

    for(int i = 0; i < n; i++) cout << dis[i] << " "; cout << endl;

    if(dis[destination] == inf) {
        cout << "there has no path from source to destination!" << endl;
    }
    else {
        cout << "Shortest path from source to destination is: " ;
        printPath(source, destination);
        cout << endl;
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

/*
4 4
1 2 2
1 4 5
2 4 1
4 3 3

6 9
1 2 1
1 3 2
2 4 7
2 5 2
3 4 4
3 5 5
5 4 1
4 6 2
6 5 8
*/


