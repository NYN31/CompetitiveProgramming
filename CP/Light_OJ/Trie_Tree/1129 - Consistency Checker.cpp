#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 100100

int trie[sz][12];
bool flag[sz];
int cnt[sz];
int n,idx;

void add(string str){
    int u=0;
    for(int i=0;i<str.size();i++){
        int d=str[i]-'0';
        if(!trie[u][d]) trie[u][d]=++idx;
        u=trie[u][d];
        cnt[u]++;
    }
    flag[u]=true;
}

bool dfs(int u){
    if(flag[u] && cnt[u]>1) return true;
    for(int d=0;d<=9;d++){
        int v=trie[u][d];
        if(v && dfs(v)) return true;
    }
    return false;
}

int main()
{
    BeatMeScanf;
    int t,no=0;
    cin>>t;
    while(t--){
        idx=0;
        memset(trie,0,sizeof trie);
        memset(flag,false,sizeof flag);
        memset(cnt,0,sizeof cnt);

        cin>>n;
        while(n--){
            string str;
            cin>>str;
            add(str);
        }
        cout<<"Case "<<++no<<": ";
        if(dfs(0)) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }
    return 0;
}
