//Adj Matrix

#include<bits/stdc++.h>
using namespace std;
#define MX 1500
#define inf INT_MAX
int adj[MX][MX],dis[MX],par[MX],done[MX];
int n;
priority_queue<pair<int,int> >pq;

void dijkstra(int src)
{
    for(int i=1;i<=n;i++) dis[i]=inf;
    pq.push(make_pair(0,src));
    dis[src]=0;
    while(!pq.empty())
    {
        pair<int,int> tmp=pq.top();
        pq.pop();
        int v=tmp.second;
        if(v==n) return;
        done[v]=1;
        for(int i=1;i<=n;i++){
            int x=i;
            int y=adj[v][i];
            if(!done[x]&&adj[v][i]!=0&&(dis[v]+y<dis[x])) {
                par[x]=v;
                dis[x]=dis[v]+y;
                pq.push(make_pair(-dis[x], x));
            }
        }

    }
}

int main()
{
    int e1,e2,w;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>e1>>e2>>w;
        if(adj[e1][e2]<w || !adj[e1][e2]){
            adj[e1][e2]=w;
            adj[e2][e1]=w;
        }
    }
    int src, t,node;
    cin>>src>>t;
    dijkstra(src);
    while(t--){
        cin>>node;
        if(node==src) cout<<0<<endl;
        else if(dis[node]==inf) cout<<"NO PATH"<<endl;
        else cout<<dis[node]<<endl;
    }

    return 0;
}
