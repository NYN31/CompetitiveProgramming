#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false)
#define ll long long
#define nl "\n"
#define PI 3.14159265358979323846
#define sz 1000005
#define mod 1000000007
#define toint(a) atoll(a.c_str())
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
ll power(ll a,ll b){return b==0?:a*power(a,b-1);}
ll gcd(ll a,ll b) {return b==0? a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a*(b/gcd(a,b));}
#define MX 500005

int par[MX];
int Rank[MX];

void initializeSet(int n){
    for(int i=1;i<=n;i++){
        par[i]=i;
        Rank[i]=1;
    }
}
int Find(int x){
    if(x!=par[x]) return par[x]=Find(par[x]);
    else return x;
}
void Union(int a,int b){
    int x=Find(a),y=Find(b);
    if(x==y) return;
    if(Rank[x]<Rank[y]) par[x]=y;
    else if(Rank[x]>Rank[y]) par[y]=x;
    else par[y]=x, Rank[x]++;
}

int main()
{
    BeatMeScanf;
    int n,m,x,y;
    while(cin>>n>>m){
        initializeSet(n);

        for(int i=1;i<=m;i++){
            int a;
            cin>>a;
            if(a==0) continue;
            cin>>x;
            for(int j=1;j<a;j++){
                cin>>y;
                Union(x,y);
            }
        }
        int M[MX]={0};
        for(int i=1;i<=n;i++) M[Find(i)]++; // if we use union by size, then we don't need to use this loop
        for(int i=1;i<=n;i++) cout<<M[Find(i)]<<" "; // if we use union by size, then we need to print Size[Find(i)];
        cout<<nl;
    }
    return 0;
}

/*

#define MX 150500
 
int par[MX];
int Size[MX];
 
void Set(int n){
    for(int i=1;i<=n;i++){
        par[i]=i;
        Size[i]=1;
    }
}
int Find(int x){
    if(x!=par[x]) return par[x]=Find(par[x]);
    else return x;
}
void Union(int a,int b){
    int i=Find(a),j=Find(b);
    if(i==j) return;
    if(Size[i]>Size[j]) swap(i,j);
    par[i]=j;
    Size[j]+=Size[i];
}

*/
