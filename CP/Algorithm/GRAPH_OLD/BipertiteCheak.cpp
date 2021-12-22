#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false)
int color[100000];
vector<int>adj[100000];

int BFS(int s)
{
    int flag = 0;
    queue<int>q;
    color[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int v, u = q.front();
        q.pop();
        for(int i = 0; i<adj[u].size(); i++)
        {
            v = adj[u][i];
            if(color[v] == -1){
                if(color[u] == 0)
                    color[v] = 1;
                else
                    color[v] = 0;
                q.push(v);
            }
            else{
                if(color[v] == color[u]){
                   flag = 1;
                   break;
                }
            }
        }
        if(flag == 1)
            break;
    }
    return flag;
}

int main()
{
    BeatMeScanf;
    int t, no = 0;
    cin>>t;
    while(t--)
    {
        memset(color, -1, sizeof color);

        int n, e, f = 0, a, b;
        cin>>n>>e;
        for(int i=1;i<=e;i++)
        {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 1; i<=n; i++){
            if(color[i]==-1 && BFS(i)){
                f = 1;
                cout << "NOT BICOLORABLE.\n";
                break;
            }
        }
        if(f == 0)
            cout << "BICOLORABLE." << endl;
        for(int i = 1; i<=n; i++) adj[i].clear();
    }
    return 0;
}
