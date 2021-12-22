#include<bits/stdc++.h>
using namespace std ;
#define lim 10000

int n,cap;
int cost[lim],weight[lim] ;
int dp[lim][lim] ;

/// complexity O(n*cap)
int knapsack(int i,int w){
    if(i == n) return 0 ;
    int &ans = dp[i][w] ;
    if(ans != -1) return ans ;
    ans = 0 ;
    if(w+weight[i] <= cap)
        ans = cost[i]+knapsack(i+1,w+weight[i]) ;   /// Taking that element
    ans = max(ans,knapsack(i+1,w)) ;        /// Without taking that element
    return ans ;
}

int main(){

    memset(dp,-1,sizeof dp) ;
    cin>> n >> cap ;
    for(int i=0; i<n; i++)
        cin>> cost[i] >> weight[i] ;
    int ans = knapsack(0,0) ;
    cout<< ans << endl ;

    return 0 ;
}






#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int values[] = {0,120,280,150,200}; /// during the calculation, for this two array, we should use i-1
int weight[] = {0,1,4,3,4}; ///if in 0 index item 0 will not present


void Knapsack(int item, int capacity)
{
    for(int i = 0; i<=item; i++){
        for(int w = 0; w<=capacity; w++){
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(w < weight[i])
                dp[i][w] = dp[i-1][w];
            else
                dp[i][w] = max(dp[i-1][w], values[i]+dp[i-1][w-weight[i]]);
            //cout << dp[i][w] << " ";
        }
        //cout << endl;
    }
}
void print(int item, int capacity)
{
    for(int i = 0; i<=item; i++){
        for(int j = 0; j<=capacity; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    Knapsack(4, 10); /// item number = 4, capacity of weight = 10
    print(4, 10);
    return 0;
}
/*
//Printing which items are included
i = item; j = capacity;
while(i>0&&j>0)
{
    if(dp[i][j] == dp[i-1][j])
    {
        cout << i << " = 0" << endl;
        i--;
    }
    else
    {
        cout << i << " = 1" << endl;
        i--; j = j-weight[i];
    }
}
*/


/*
  
/*
if w<weight dp[i][w]=dp[i-1][w]
if dp[i][w]=max(dp[i-1][w],prize[i]+dp[i-1][w-weight[i]]);
*/

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
*/
