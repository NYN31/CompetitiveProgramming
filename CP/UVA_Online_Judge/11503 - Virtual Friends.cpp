#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MX 200100
int par[MX];
int Size[MX];
int edge[MX];

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

int main()
{
    BeatMeScanf;
    int t;
    cin>>t;
    while(t--){
        int n,c=0;
        cin>>n;
        map<string,int>mp;
        Set(2*n);
        for(int i=1;i<=n;i++){
            string a,b;
            cin>>a>>b;
            if(mp.count(a)==0) {c++,mp[a]=c;}
            if(mp.count(b)==0) {c++,mp[b]=c;}
            Union(mp[a],mp[b]);
            cout<<Size[Find(mp[a])]<<endl;
        }
    }
    return 0;
}
