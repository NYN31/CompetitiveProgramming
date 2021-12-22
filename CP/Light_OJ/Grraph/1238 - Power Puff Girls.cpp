/// BFS grid

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 25
char g[sz][sz];
int vis[sz][sz];
int x[] = {0,-1,0,1};
int y[] = {1,0,-1,0};
int n,m;
void bfs(int r,int c){
    vis[r][c] = 0;
    queue<int>qx,qy;
    qx.push(r); qy.push(c);
    while(!qx.empty() && !qy.empty()){
        int u1=qx.front(),u2=qy.front();
        qx.pop(),qy.pop();

        for(int i=0;i<4;i++){
            int a = u1+x[i];
            int b = u2+y[i];

            if((a>=0 && a<n) && (b>=0 && b<m) && vis[a][b]==-1 && g[a][b]!='m' && g[a][b]!='#'){
                qx.push(a);
                qy.push(b);
                vis[a][b] = vis[u1][u2] + 1;
            }
        }
    }
}


int main()
{
    int t,no=0;
    cin>>t;
    while(t--){
        cin>>n>>m;
        int ai,aj,bi,bj,ci,cj,hi,hj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[i][j];
                if(g[i][j] == 'a') ai=i,aj=j;
                else if(g[i][j] == 'b') bi=i,bj=j;
                else if(g[i][j] == 'c') ci=i,cj=j;
                else if(g[i][j] == 'h') hi=i,hj=j;
                vis[i][j] = -1;
            }
        }
        bfs(hi,hj);
        //cout<<ai<<" "<<aj<<" "<<bi<<" "<<bj<<" "<<ci<<" "<<cj<<" "<<hi<<" "<<hj<<endl;
        cout<<"Case "<<++no<<": ";
        cout<<max(vis[ai][aj], max(vis[bi][bj], vis[ci][cj]))<<endl;
    }
    return 0;
}
