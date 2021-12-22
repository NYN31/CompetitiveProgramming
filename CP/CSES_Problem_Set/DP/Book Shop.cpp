#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 1010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
 
 
int n,x;
int dp[1005][100005],h[1005],s[1005];
 
void Knapsack(int item, int capacity)
{
    for(int i = 0; i<=item; i++){
        for(int w = 0; w<=capacity; w++){
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(w < h[i])
                dp[i][w] = dp[i-1][w];
            else
                dp[i][w] = max(dp[i-1][w], s[i]+dp[i-1][w-h[i]]);
        }
    }
    cout<<dp[item][capacity]<<endl;
}
 
int main()
{
    BeatMeScanf;
    cin>>n>>x;
    h[0]=0,s[0]=0;
    for(int i=0;i<n;i++) cin>>h[i+1]; /// books price
    for(int i=0;i<n;i++) cin>>s[i+1]; /// page numbers
 
    Knapsack(n,x);
    return 0;
}
