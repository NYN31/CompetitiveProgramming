/// Using Rock Climbing Technique


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1 << 28
int mat[30][10];
int dp[30][10];
int n, c = 3;
int call(int i, int j)
{
    if (i >= 0 && i < n && j >= 0 && j < c)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        int ret = inf;
        int ret1=call(i + 1, j + 1);
        int ret2=call(i + 1, j - 1);
        int ret3=call(i + 1, j - 2);
        int ret4=call(i + 1, j + 2);
        ret=mat[i][j]+min({ret1,ret2,ret3,ret4});
        return dp[i][j] = ret;
    }
    else if(i<n && (j<0 || j>2)) return inf;
    else return 0;
}
int main()
{
    int t,no=0;
    cin>>t;
    while(t--){
        memset(dp, -1, sizeof dp);
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<c;j++){
                cin>>mat[i][j];
            }
        }
        int mn=inf;
        for(int i=0;i<3;i++) {
            mn=min(mn,call(0,i));
        }
        cout<<"Case "<<++no<<": "<<mn<<endl;
    }
    return 0;
}



/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1 << 28
int mat[30][5];
int dp[30][5];
int n, c = 3;

int solve(int i,int last){
    if(i>n) return 0;
    if(dp[i][last]!=-1) return dp[i][last];
    int ret=inf;
    for(int k=1;k<=3;k++)
        if(last!=k)
            ret=min(ret,solve(i+1,k)+mat[i][k]);
    return dp[i][last]=ret;
}

int main()
{
    int t,no=0;
    cin>>t;
    while(t--){
        memset(dp, -1, sizeof dp);
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=c;j++){
                cin>>mat[i][j];
            }
        }
        int ans=solve(1,0);
        cout<<"Case "<<++no<<": "<<ans<<endl;
    }
    return 0;
}

*/
