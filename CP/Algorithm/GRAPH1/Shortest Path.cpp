/***
        problem 1: Floyd-warshall algo
        problem 2: dijkastra algo

***/


ll const node = 505 ;
ll const inf = 1e15 ;
ll n, m, q ;
ll dist[node+2][node+2] ;

void all_clear() {
        for(int i=1; i<=node; i++) {
                for(int j=1; j<=node; j++) {
                        dist[i][j] = inf ;
                }
                dist[i][i] = 0 ;
        }
}

void floyd_warshall() {
        for(int k=1; k<=n; k++) {
                for(int i=1; i<=n; i++) {
                        for(int j=1; j<=n; j++) {
                                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]) ;
                        }
                }
        }
}

void solve() {
        all_clear() ;
        cin >> n >> m >> q ;
        for(int i=1; i<=m; i++) {
                ll u, v, w ;
                cin >> u >> v >> w ;
                dist[u][v] = min(dist[u][v], w) ;
                dist[v][u] = min(dist[v][u], w) ;
        }
        floyd_warshall() ;
        while(q--) {
                int u, v ; cin >> u >> v ;
                if(dist[u][v] == inf) cout << -1 << endl ;
                else cout << dist[u][v] << endl ;
        }
}

