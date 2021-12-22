#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MX 5500
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

int main()
{
    BeatMeScanf;
    int n,r;
    while(cin>>n>>r){
        if(n==0 && r==0) break;
        int c=0;
        string s;
        map<string,int>mp;
        for(int i=1;i<=n;i++) cin>>s;

        if(r==0){
            cout<<1<<endl;
            continue;
        }
        Set(n);
        for(int i=1;i<=r;i++){
            string a,b;
            cin>>a>>b;
            if(mp.count(a)==0) {c++,mp[a]=c;}
            if(mp.count(b)==0) {c++,mp[b]=c;}
            Union(mp[a],mp[b]);
        }
        cout<<*max_element(Size+1,Size+n+1)<<endl;
    }
    return 0;
}
