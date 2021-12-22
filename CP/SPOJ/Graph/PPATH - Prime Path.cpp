#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 100100
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define toint(a) atoll(a.c_str())
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
 
bool isprime[sz+10];
vector<int>primes;
bool vis[sz];
int dist[sz];
vector<int>adj[sz];
 
void sieve() {
 
    memset(isprime, true, sizeof isprime);
    isprime[0]=isprime[1]=false;
    for(int i=4;i<=sz;i+=2) isprime[i]=false;
    for(int i=3;i*i<=sz;i++)
        if(isprime[i])
            for(int j=i*i;j<=sz;j+=i) isprime[j]=false;
 
    for(int i=1000;i<=9999;i++) if(isprime[i]) primes.pb(i);
}
 
bool moding(int a,int b) {
    string x,y;
    int cnt=0;
    x = tostr(a);
    y = tostr(b);
    for(int i=0;i<x.size();i++)
        if(x[i]!=y[i]) cnt++;
    if(cnt==1) return 1;
    else return 0;
}
void bfs(int s){
    vis[s]=true;
    dist[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : adj[u]) {
            if(vis[v]==false){
                vis[v]=true;
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
}
int main()
{
    BeatMeScanf;
    sieve();
    for(int i=0;i<primes.size();i++){
        for(int j=0;j<primes.size();j++) {
            int p1=primes[i],p2=primes[j];
            if(i == j) continue;
            bool x=moding(p1,p2);
            if(x) {
                adj[p1].pb(p2);
                adj[p2].pb(p1);
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        memset(vis,false,sizeof vis);
        memset(dist,0,sizeof dist);
        bfs(a);
        cout<<dist[b]<<endl;
    }
 
    return 0;
} 
