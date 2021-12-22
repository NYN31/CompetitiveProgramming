#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 100010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

int const N = 55;

char grid[N+5][N+5];
int vis[N+5][N+5];
int dp[N+5][N+5];
int n, m;

int go(int i, int j, int k) {
    char ch = (char)(k+'A');
    if(!(i>=0 && i<n && j>=0 && j<m) || k<0 || k>25) return 0;
    if( ch != grid[i][j] || vis[i][j]) return 0;
    vis[i][j] = 1;
    int &ret = dp[i][j];
    if(ret != -1) return ret;
    int ans1=0,ans2=0,ans3=0,ans4=0;

    ans1 = max({go(i+1, j, k+1)+1,go(i-1,j,k+1)+1, go(i,j+1,k+1)+1,go(i,j-1,k+1)+1});
    ans2 = max({go(i+1,j+1,k+1)+1,go(i-1,j+1,k+1)+1,go(i+1,j-1,k+1)+1,go(i-1,j-1,k+1)+1});
    ans3 = max({go(i+1, j, k+1)+1,go(i-1,j,k+1)+1, go(i,j+1,k+1)+1,go(i,j-1,k+1)+1});
    ans4 = max({go(i+1,j+1,k+1)+1,go(i-1,j+1,k+1)+1,go(i+1,j-1,k+1)+1,go(i-1,j-1,k+1)+1});
    ans1 = max({ans1, ans2, ans3, ans4});
    ret = ans1;
    return ret;
}

int main() {
    BeatMeScanf;
    int no = 0;
    while(cin>>n>>m && n!=0 && m!=0){
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cin>>grid[i][j];
                vis[i][j] = 0;
            }
        }
        int ans = 0;
        memset(dp, -1, sizeof dp);

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ///memset(dp, -1, sizeof dp);
                if(grid[i][j]=='A') ans = max(ans, go(i,j,0));
            }
        }
        cout<<"Case "<<++no<<": "<<ans<<endl;

    }
    return 0;
}


/*
4 3
ABE
CFG
BDH
ABC
4 3
ABF
CEG
BDH
ABC
1 1
B
1 2
AA
1 1
A
1 1
B
5 3
ABF
CFG
OQP
DCB
PQA
0 0
*/
