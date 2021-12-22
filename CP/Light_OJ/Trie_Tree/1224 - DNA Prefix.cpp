#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 2500010

int trie[sz][5];
bool flag[sz];
int cnt[sz],idx;

int rep(char ch){
    if(ch=='A') return 0;
    else if(ch=='C') return 1;
    else if(ch=='G') return 2;
    else return 3;
}
void add(string str){
    int u=0;
    for(int i=0;i<str.size();i++){
        int d=rep(str[i]);
        if(!trie[u][d]) trie[u][d] = ++idx;
        u=trie[u][d];
        cnt[u]++;
    }
    flag[u]=true;
}

int dfs(int u,int c){
    int ans=cnt[u]*c;
    for(int i=0;i<4;i++){
        int v=trie[u][i];
        if(v) ans=max(ans,dfs(v,c+1));
    }
    return ans;
}

int main()
{
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        idx=0;
        memset(cnt,0,sizeof cnt);
        memset(flag,false,sizeof flag);
        memset(trie,0,sizeof trie);

        string str;
        for(int i=0;i<n;i++){
            cin>>str;
            add(str);
        }
        int ans=dfs(0,0);
        printf("Case %d: %d\n",++no,ans);
    }
    return 0;
}
