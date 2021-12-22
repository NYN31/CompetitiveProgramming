#include<bits/stdc++.h>
using namespace std ;

const int lim = 1e3 + 5 ;
const int inf = 1e9 ;


int n, m, mat[lim][lim], dis[lim] ;
int cost[lim][lim], par[lim] ;
bool vis[lim] ;

void dijkstra(int src){
    for(int i = 0; i < lim; i++){
        dis[i] = inf ;
        vis[i] = 0 ;
        par[i] = -1 ;
    }

    dis[src] = 0 ;

    for(int i=0; i<n; i++){         /// maximum n relaxation needed
        int u = -1 ;
        for(int j=1; j<=n; j++){    /// finding node u which is unvisited and min distanced
            if(!vis[j] && (u == -1 || dis[j] < dis[u]))
                u = j ;
        }

        if(dis[u] == inf) break ;   /// out of source node component

        vis[u] = 1 ;    /// make current node visited

        for(int v = 1; v <= n; v++){
            if(!mat[u][v]) continue ;

            if(dis[u] + cost[u][v] <= dis[v]){    /// path relaxation
                dis[v] = dis[u] + cost[u][v] ;
                par[v] = u ;
            }
        }

    }
}

void print_path(int u){
    if(par[u] != -1) print_path(par[u]) ;
    cout<< u << " " ;
}


int main(){
    cin>> n >> m ;

    for(int i=0; i<m; i++){
        int u, v, w ;
        cin>> u >> v >> w ;
        mat[u][v] = 1 ;
        mat[v][u] = 1 ;
        cost[u][v] = w ;
        cost[v][u] = w ;
    }

    int src = 1 , dest = n ;
    dijkstra(src) ;

    print_path(dest) ;

    return 0 ;
}
