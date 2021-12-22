#include<iostream>
using namespace std;
#define sz 100

int n, e;
int adj[sz][sz];

class Queue{
    int topId, frontId;
    int arr[sz];
public:
    Queue() {
        topId = -1;
        frontId = 0;
    }
    void push(int x) { arr[++topId] = x; }
    void pop() { frontId++; }
    int peek() { return arr[topId]; }
    bool isEmpty() { return frontId > topId; }
};

bool isBicolorable(int src, int color[]) {
    Queue q;
    q.push(src);
    color[src] = 0;
    if(adj[src][src]) return false;

    while(!q.isEmpty()) {
        int u = q.peek();
        q.pop();

        for(int i=1; i<=n; i++) {
            if(adj[u][i]) {
                if(color[i] == -1) {
                    color[i] = 1 - color[u];
                    q.push(i);
                }
                else if(color[i] == color[u]) return false;
            }
        }
    }
    return true ;
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
