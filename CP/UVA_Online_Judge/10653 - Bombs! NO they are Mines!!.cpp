#include<bits/stdc++.h>
using namespace std;
#define MX 1001
int adj[MX][MX];
int visited[MX][MX];
int x[]={0,-1,0,1};
int y[]={1,0,-1,0};

void bfs(int r, int c)
{
    queue<int> qx, qy;
    visited[r][c] = 0;
    qx.push(r);
    qy.push(c);
    while(!qx.empty() && !qy.empty())
    {
        int topx = qx.front();
        int topy = qy.front();
        qx.pop();
        qy.pop();
        for(int i = 0; i<4; i++)
        {
            int a = topx+x[i];
            int b = topy+y[i];
            if((a>=0 && a<MX) && (b>=0 && b<MX) && visited[a][b] == -1 && !adj[a][b])
            {
                qx.push(a);
                qy.push(b);
                visited[a][b] = visited[topx][topy] + 1;
            }
        }
    }
}

int main()
{
    int rw, cl;
    while(cin >> rw >> cl)
    {
        if(rw == 0 && cl == 0)
            break;
        memset(adj, 0, sizeof adj);
        memset(visited, -1, sizeof visited);
        int n, x, y;
        cin >> n;
        while(n--)
        {
            int rwnum, num, boom;
            cin >> rwnum >> num;
            while(num--)
            {
                cin>>boom;
                adj[rwnum][boom] = 1;
            }
        }
        cin >> x >> y;
        bfs(x, y);
        cin >> x >> y;
        cout << visited[x][y] << endl;
    }
    return 0;
}

