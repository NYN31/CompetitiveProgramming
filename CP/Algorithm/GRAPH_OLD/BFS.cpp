#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios::sync_with_stdio(0)
#define ll long long
#define ull unsigned ll
#define CaseNum cout<<"Case "<<++no<<": "
#define nl "\n"
#define PI 3.14159265358979323846
#define sz 150500
#define mod 1000000007
#define toint(a) atoll(a.c_str())
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
ll power(ll a,ll b){return b==0?:a*power(a,b-1);}
ll gcd(ll a,ll b) {return b==0? a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a*(b/gcd(a,b));}

///st.max_load_factor(0.25); st.reserve(512);

bool vis[sz];
ll edge,vertex;

void bfs(int s,vector<int>graph[]){
    vis[s]=1;
    queue<int>q;
    q.push(s);
    vertex++;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++){
            int v=graph[u][i];
            edge++;
            if(vis[v]==0){
                vertex++;
                vis[v]=1;
                q.push(v);
            }
        }
    }
}

int main(){
    BeatMeScanf;
    int n,m;
    while(cin>>n>>m){
        bool ok=true;
        vector<int>graph[sz];
        for(int i=0;i<graph[i].size();i++) graph[i].clear();
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        for(int i=0;i<=n;i++) vis[i]=0;
        for(int i=1;i<=n;i++){
            edge=vertex=0;
            if(!vis[i]){
                bfs(i,graph);
                edge/=2;
                ll x=(vertex*(vertex-1))/2;
                if(x!=edge){
                    ok=false;
                }
            }
        }
        if(ok) cout<<"YES"<<nl;
        else cout<<"NO"<<nl;
    }
    return 0;
}






#include<bits/stdc++.h>
using namespace std;
int visited[10000];
typedef long long ll;

void bfs(long long x, map <long long , vector<long long> > adj)
{
    visited[x] = 0;
    queue <ll> q;
    q.push(x);
    while(!q.empty())
    {
        ll node = q.front();
        q.pop();
        for(ll i = 0; i<adj[node].size(); i++)
        {
            if(visited[adj[node][i]] == -1)
            {
                ll v = adj[node][i];
                visited[v] = visited[node]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    ll n, e, x, a, b;
    cin >> n >> e;
    map<ll, vector<ll> > adj;
    for(int i = 1; i<=e; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        visited[a] = -1;
        visited[b] = -1;
    }
    while(cin >> x && x != 0)
    {
        bfs(x, adj);
        for(ll i = 0; i<=n; i++)
        {
             cout << visited[i] << " ";
        }
        memset(visited, -1, sizeof(visited));
        cout << endl;
    }
    return 0;
}
/*
6 7
6 4
4 5
4 3
5 2
5 1
2 1
2 3
*/



int main()
{
    BeatMeScanf;
    int n,m;
    while(cin>>n>>m){
        int grp[1005],u,x,cnt=0;
        queue<int>q;
        vector<int>adj[1005];
        for(int i=1;i<=n;i++){
            cin>>grp[i];
            if(grp[i]==0) q.push(i);
        }
        for(int i=1;i<=m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(q.size()==0) {cout<<0<<endl;continue;}
        while(!q.empty()){
            u=q.front();
            cout<<u<<endl;
            q.pop();
            for(int i=0;i<adj[u].size();i++){
                x=adj[u][i];
                grp[x]--;
                if(grp[x]==0) q.push(x);
            }
        }
        //for(int i=1;i<=n;i++) cout<<grp[i]<<" ";cout<<endl;
        for(int i=1;i<=n;i++) if(grp[i]<=0) cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}
