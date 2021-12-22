#include<bits/stdc++.h>
using namespace std;
#define mx 2100
#define inf 100000
int U[mx],V[mx],W[mx],dist[mx];
int vertex,edge;

bool BellManFord(int src)
{
    for(int i=0;i<vertex;i++) dist[i]=inf;
    dist[src]=0;
    bool update,negative_cycle=false;
    for(int step=1;step<=vertex;step++){
        update=false;
        for(int i=0;i<edge;i++){
            int a=U[i];
            int b=V[i];
            if(dist[b]>dist[a]+W[i]){
                update=true;
                dist[b]=dist[a]+W[i];
                if(step==vertex){
                        negative_cycle=true;
                }
            }
        }
        if(update==false) break;
    }
    return negative_cycle;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        cin>>vertex>>edge;
        for(int i=0;i<edge;i++)
            cin>>U[i]>>V[i]>>W[i];

        bool x=BellManFord(0);
        if(x==false) cout<<"not possible"<<endl;
        else cout<<"possible"<<endl;
    }
    return 0;
}
