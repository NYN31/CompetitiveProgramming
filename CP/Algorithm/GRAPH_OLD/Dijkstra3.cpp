/******************************************************************************************************************************
*** "In the name of Allah(swt), the most gracious, most merciful. Allah(swt) blesses with knowledge to whom he wants."      ***
***     Author     : Md Sajjad Hosen Noyon                                                                                  ***
***     University : Dept. of CSE, IIUC                                                                                     ***
***     github     : https://github.com/NOYON31                                                                             ***
***     Email      : noyoncse3101@gmail.com                                                                                 ***
***     facebook   : https://www.facebook.com/md.noyon.9440                                                                 ***
*******************************************************************************************************************************/
 
 
//Spoj: TRVCOST - Travelling cost
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false)
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpll vector<pll>
#define vpii vector<pii>
 
#define PQ priority_queue
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define mem(a,x) memset(a,x,sizeof(a))
#define _ccase printf("Case %lld: ",++no)
#define _case cout<<"Case "<<++no<<": "
 
#define rev(v) reverse(v.begin(),v.end())
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define all(v) v.begin(),v.end()
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define valid(tx,ty) (tx>=0&&tx<n&&ty>=0&&ty<m)
#define one(x) __builtin_popcount(x)
#define Unique(v) v.erase(unique(all(v)),v.end())
#define stree ll l=(n<<1),r=l+1,mid=b+(e-b)/2
#define fout(x) fixed<<setprecision(x)
#define toint(a) atoi(a.c_str())
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; /// move up down && corner /// If we want only move in up and down , thne
int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; /// UVA problem samle (Oil deposite )
/*
for up down right left
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
*/
const int mod=1e9+7;
const int mxn=5100;
const ld eps=1e-9;
 
#define inf INT_MAX
vector<pair<int,int> > g[505];
int dis[mxn];
int done[mxn];
int n;
 
void solve(int src)
{
 
    for(int i=0;i<=mxn;i++) dis[i]=inf;
    priority_queue <pii ,vector<pii>,greater<pii> > pq;
    pq.push(mp(0,src));
    dis[src]=0;
    while(!pq.empty())
    {
        pii tmp=pq.top();
        pq.pop();
        int v=tmp.second;
        done[v]=1;
 
        for(int i=0;i<g[v].size();i++){
            int x=g[v][i].second;
            int y=g[v][i].first;
            if(!done[x]&&(dis[v]+y<dis[x])){
                dis[x]=dis[v]+y;
                pq.push(mp(dis[x],x));
            }
        }
 
    }
}
 
int main()
{
    int u,v,w;
    cin>>n;
        for(int i=0;i<n;i++){
            cin>>u>>v>>w;
            g[u].pb(mp(w,v));
            g[v].pb(mp(w,u));
        }
 
        int src, t;
        cin>>src;
        solve(src);
        cin>>t;
 
        while(t--){
           int node;
           cin>>node;
           if(dis[node]!=inf)
               cout<<dis[node]<<endl;
           else cout<<"NO PATH"<<endl;
 
        }
    return 0;
} 
