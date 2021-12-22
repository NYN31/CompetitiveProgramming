/// bicoloring

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 20005
vector<int>g[sz];
int vis[sz];
int cnt1,cnt0;
void bfs(int s){
    vis[s] = 1;
    cnt1++;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : g[u]){
            if(vis[v] == -1){
                if(vis[u] == 1) vis[v]=0,cnt0++;
                else vis[v] = 1,cnt1++;
                q.push(v);
            }
        }
    }
}

int main()
{
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        int n,k=1,x=-1,ans=0;
        cnt0=0,cnt1=0;
        vector<int>vec;
        for(int i=0;i<=sz;i++) g[i].clear();
        vec.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int u,v;
            scanf("%d %d", &u,&v);
            vec.push_back(u);
            vec.push_back(v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(vis,-1,sizeof vis);
        for(int i=0;i<vec.size();i++){
            if(vis[vec[i]]==-1){
                bfs(vec[i]);
                ans+=max(cnt1,cnt0);
                cnt1=0,cnt0=0;
            }
        }
        printf("Case %d: %d\n", ++no, ans);

    }
    return 0;
}
