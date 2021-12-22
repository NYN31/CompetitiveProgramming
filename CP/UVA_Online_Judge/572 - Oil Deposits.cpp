///DFS Flood Fill

#include<bits/stdc++.h>
using namespace std;
#define MX 105

int _x[] = {+0,+0,+1,-1,-1,+1,-1,+1};
int _y[] = {-1,+1,+0,+0,+1,+1,-1,-1};
int vis[MX][MX], row, col;
char F_Fill[MX][MX];

void dfs(int x, int y)
{
    vis[x][y]=1;
    for(int i=0;i<8;i++){
        int a, b;
        a=x+_x[i];
        b=y+_y[i];
        if((a>=1&&a<=row&&b>=1&&b<=col) && !vis[a][b]){
            vis[a][b]=1;
            if(F_Fill[a][b]=='@')
                dfs(a,b);
        }
    }
}

int main()
{
    while(cin>>row>>col && row!=0&&col!=0)
    {
        int cnt=0;
        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
                cin>>F_Fill[i][j];
        memset(vis, 0, sizeof(vis));
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(!vis[i][j] && F_Fill[i][j]=='@'){
                    dfs(i,j); cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
