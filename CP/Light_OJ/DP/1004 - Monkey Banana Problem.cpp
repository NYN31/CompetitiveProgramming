/*
DP in 2D grid
--> Rock climbing Technique
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 1 << 28
#define sz 110

int arr[2*sz+5][sz+5];
int dp[2*sz+5][sz+5];
int n;
int call(int i, int j)
{
    if (i >= 0 && i < 2*n-1 && j >= 0 && j < n){
        if(arr[i][j]==0) return -inf;
        if (dp[i][j] != 0)
            return dp[i][j];
        int ret = -inf,ret1,ret2;
        if(i<n-1){
            ret1=call(i + 1, j);
            ret2=call(i + 1, j + 1);
        }
        else{
            ret1=call(i+1,j-1);
            ret2=call(i+1,j);
        }
        ret=arr[i][j]+max({ret1,ret2});
        return dp[i][j] = ret;
    }
    else if(i<2*n-1 && (j<0 || j>n)) return -inf;
    else return 0;
}
int main()
{
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        int mx=-inf;
        scanf("%d",&n);
        memset(arr,0,sizeof arr);
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
                scanf("%d",&arr[i][j]);
        for(int i=0;i<n-1;i++)
            for(int j=0;j<n-i-1;j++)
                scanf("%d",&arr[n+i][j]);

        mx=max(mx,call(0,0));
        printf("Case %d: %d\n", ++no, mx);
    }
}
