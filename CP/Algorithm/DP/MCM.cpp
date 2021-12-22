/***
    Problem name: Matrix Chain Multiplication
    recursive solution:

    if i=j: return 0
    else return min(cost[i][k]+cost[k+1][j]+p[i-1]*p[k]*p[j]
***/

/// recursive solution

#include<bits/stdc++.h>
using namespace std;
#define inf 10000007
#define sz 100
int dp[sz][sz];
int n, p[]={5,4,6,2,7};

int mcm(int i,int j){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=inf;
    for(int k=i;k<j;k++){
        int temp=mcm(i,k)+mcm(k+1,j)+(p[i-1]*p[k]*p[j]);
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}

int main(){
    n=5;
    memset(dp,-1,sizeof dp);
    int ans=mcm(1,4);
    cout<<ans<<endl;
    return 0;
}


/// iterative solution with bracket solution

#include<bits/stdc++.h>
using namespace std;
#define inf 10000007

int main(){
    int n=5;
    int p[]={5,4,6,2,7};
    int brac[15][15],cost[15][15];
    memset(brac,0,sizeof brac);
    memset(cost,0,sizeof cost);

    int j,mn,temp;
    for(int d=1;d<n-1;d++){
        for(int i=1;i<n-d;i++){
            j=i+d;
            mn=inf;
            for(int k=i;k<=j-1;k++){
                temp=cost[i][k]+cost[k+1][j]+(p[i-1]*p[k]*p[j]);
                if(temp<mn){
                    mn=temp;
                    brac[i][j]=k;
                }
            }
            cost[i][j]=mn;
        }
    }
    cout<<cost[1][n-1]<<endl;
    return 0;
}
