//CF: Dijkstra

#include<bits/stdc++.h>
using namespace std;
#define mxn 100100
#define inf INT_MAX
vector<pair<int,int> > g[mxn];
int dis[mxn],par[mxn],done[mxn];
int n;
priority_queue<pair<int,int> >pq;
void solve()
{
    int i,j,x,y,v;
    for(i=0;i<mxn;i++) dis[i]=inf;

    pq.push(make_pair(0,1));
    dis[1]=0;
    while(!pq.empty()){
        pair<int,int> tmp=pq.top();
        pq.pop();
        v=tmp.second;
        //cout<<"-->"<<tmp.first<<"-->"<<v<<endl; ///popped elements
        if(v==n) return;
        done[v]=1;
        for(i=0;i<g[v].size();i++){
            x=g[v][i].first;
            y=g[v][i].second;
            //cout<<x<<" "<<y<<endl; ///elements of every pair
            if(!done[x]&&(dis[v]+y<dis[x])){
                par[x]=v;
                dis[x]=dis[v]+y;
                pq.push(make_pair(-dis[x],x));
                //cout<<-dis[x]<<" "<<x<<endl; ///pushed elements
            }
        }
    }
}
int print_path(int x)
{
    if(x==1){
        cout<<1<<" ";
    }
    else if(par[x]==0){
        cout<<-1<<endl;
    }
    else{
        print_path(par[x]);
        cout<<x<<" ";
    }
}
int main()
{
    int i,j,cs,t,e,u,s,v,w;
        scanf("%d%d",&n,&e);
        for(j=0;j<e;j++){
            scanf("%d%d%d",&u,&v,&w);

            g[u].push_back(make_pair(v,w));
            g[v].push_back(make_pair(u,w));
        }
        solve();
        for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++) cout<<done[i]<<" ";
        cout<<endl;
        print_path(n);

    return 0;
}
