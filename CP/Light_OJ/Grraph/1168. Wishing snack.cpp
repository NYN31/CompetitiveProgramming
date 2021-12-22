#include<bits/stdc++.h>
using namespace std;
vector<int>g[1010],rg[1010],sg[1010];
int vis[1010],comp[1010];
vector<int>top;
vector<int>vc;
bool ok;
int jh;
void init(){
    vc.clear();
    top.clear();
    for(int i=0;i<1010;i++) g[i].clear();
    for(int i=0;i<1010;i++) rg[i].clear();
    for(int i=0;i<1010;i++) sg[i].clear();
}

void dfs1(int s){
    vis[s]=1;

    for(int v : g[s]){
        if(vis[v] == 0){
            vis[v] = 1;
            dfs1(v);
        }
    }
    top.push_back(s);
}

void dfs2(int s, int cmp){
    vis[s] = 1;
    comp[s]=cmp;

    for(int v : rg[s]){
        if(vis[v] == 0){
            vis[v] = 1;
            dfs2(v, cmp);
        }
    }
}
bool dfs3(int s){
    if(sg[s].size()>1) ok = false;
    vis[s]=1;
    if(!sg[s].empty()){
        int v = sg[s][0];
        if(vis[v]==0){
            return dfs3(v);
        }
    }
    return true;
}

int main()
{
    int t,no=0;
    cin>>t;
    while(t--){
        int n,k;
        jh = 1;
        ok = true;
        bool x = false;
        init();
        cin>>n;
        while(n--){
            cin>>k;
            for(int i=0;i<k;i++){
                int a,b;
                cin>>a>>b;
                vc.push_back(a), vc.push_back(b);
                g[a].push_back(b);
                rg[b].push_back(a);
            }
        }

        for(int i=0;i<vc.size();i++){
            if(vis[vc[i]]==0){
                dfs1(vc[i]);
            }
        }
       // for(int i=0;i<2*top.size();i++) cout<<top[i]<<" ";cout<<endl;
        for(int i=0;i<=1005;i++) vis[i] = 0;
        int cmp=0;
        for(int i=top.size()-1;i>=0;i--){
            int u = top[i];
            if(vis[u] == 0){
                ++cmp;
                dfs2(u, cmp);
            }
        }
        //for(int i=0;i<top.size();i++) cout<<comp[i]<<" ";cout<<endl;
        for(int i=0;i<1005;i++){
            if(g[i].size()){
                for(int j=0;j<g[i].size();j++){
                    int v = g[i][j];
                    if(comp[i] != comp[v]){
                        sg[comp[i]].push_back(comp[v]);
                    }
                }
            }
        }
        /*for(int i=0;i<1010;i++){
            if(sg[i].size()>0){
                cout<<i<<": ";
                for(int v:sg[i]){
                    cout<<v<<" ";
                }
                cout<<endl;
            }
        }*/

        for(int i=0;i<=1005;i++) vis[i] = 0;
        ok = dfs3(comp[0]);
        //for(int i=0;i<=cmp;i++) cout<<vis[i]<<" ";cout<<endl;
        for(int i=1;i<=cmp;i++){
            if(vis[i] == 0){
                ok = false;
                break;
            }
        }
        if(ok) printf("Case %d: YES\n", ++no);
        else printf("Case %d: NO\n", ++no);

    }
    return 0;
}

/*
1
7
3 4
3 1
0 3
1 3
4 3
1 0
1 4


1
1
5
0 1
1 3
3 4
4 1
6 4
*/
