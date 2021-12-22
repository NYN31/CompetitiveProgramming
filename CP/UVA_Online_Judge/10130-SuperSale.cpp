/*
if w<weight dp[i][w]=dp[i-1][w]
if dp[i][w]=max(dp[i-1][w],prize[i]+dp[i-1][w-weight[i]]);
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1010
int n,cap,dp[sz][35];
int cost[sz],weight[sz];

int knapsack(int i,int w){
    if(i>=n) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    int ans=0;
    if(w+weight[i]<=cap)
        ans=cost[i]+knapsack(i+1,w+weight[i]);
    ans=max(ans,knapsack(i+1,w));
    dp[i][w]=ans;
    return dp[i][w];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int q,ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>cost[i]>>weight[i];
        cin>>q;
        for(int i=1;i<=q;i++){
            cin>>cap;
            memset(dp,-1,sizeof dp);
            ans+=knapsack(0,0);
        }
        cout<<ans<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 550

int dp[1010][35];
int prize[1010],weight[1010];

void solve(int item, int cap){
    for(int i=1;i<=item;i++){
        for(int w=1;w<=cap;w++){
            if(w<weight[i])
                dp[i][w]=dp[i-1][w];
            else
                dp[i][w]=max(dp[i-1][w],prize[i]+dp[i-1][w-weight[i]]);
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q,total=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>prize[i]>>weight[i];
        cin>>q;
        memset(dp,0,sizeof dp);
        solve(n,32);
        for(int i=1;i<=q;i++){
            int a,mx=0;
            cin>>a;
            for(int j=0;j<=n;j++){
                mx=max(mx,dp[j][a]);
            }
            total+=mx;
        }
        cout<<total<<endl;
    }
}










#include<bits/stdc++.h>
using namespace std;
int a[1010][1010];
int main()
{
    int T;

    cin >> T;
    while(T--)
    {
        int N, P[1010], W[1010], n, i = 1;
        cin >> N;
        n = N;
        while(N--)
        {
            cin >> P[i] >> W[i];
            i++;

        }
        int G, mx,sum=0;
        cin >> G;
        while(G--)
        {
            cin >> mx;
            for(int i = 1; i<=n; i++){
                for(int j = 1; j<=mx; j++){
                    if(i == 0 || j == 0)
                        a[i][j] = 0;
                    else if(j>=W[i])
                        a[i][j] = max(a[i-1][j], P[i]+a[i-1][j-W[i]]);
                    else
                        a[i][j] = a[i-1][j];
                }
            }
            sum += a[n][mx];
        }
        cout << sum << endl;
    }
    return 0;
}

