/// REcursive Way

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 100000007
int n,k;
int dp[10][7500];
int coin[]={1,5,10,25,50};

int solve(int i,int rem){
    //cout<<i<<" "<<rem<<endl;
    if(i>=5){
        if(rem==0) return 1;
        else return 0;
    }
    if(dp[i][rem]!=-1) return dp[i][rem];
    int ans1=0,ans2=0;
    if(rem-coin[i]>=0) ans1=solve(i,rem-coin[i]);
    ans2=solve(i+1,rem);
    dp[i][rem]=(ans1+ans2);
    return dp[i][rem];
}

int main(){
    memset(dp,-1,sizeof dp);
    while(cin>>k){
        int ans=solve(0,k);
        cout<<ans<<endl;
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

int dp[6][7500];
int count( int S[], int m, int n )
{
    if (n == 0)
        return 1;

    if (n < 0)
        return 0;
    if (m <=0 && n >= 1)
        return 0;
    if(dp[m][n] != -1) return dp[m][n];
    return dp[m][n] = count( S, m - 1, n ) + count( S, m, n-S[m-1] );
}

int main()
{
    int i, j, m = 5, amount;
    int arr[] = {1, 5, 10, 25, 50};
    memset(dp, -1, sizeof(dp));
    while(cin >> amount)
        printf("%d\n", count(arr, m, amount));
    return 0;
}

// Iterative way

/*
#include<bits/stdc++.h>
using namespace std;
int coin[] = {0, 1, 5, 10, 25, 50};
int way[6][7490];

void pre()
{

    for(int i = 1; i<=5; i++)
        for(int j = 0; j<=7490; j++)
            way[i][j] = 0;
    way[0][0] = 1;
    for(int i = 1; i<=5; i++){
        for(int j = 0; j<7490; j++){
            if(coin[i]>j)
                way[i][j] = way[i-1][j];
            else
                way[i][j] = way[i-1][j] + way[i][j-coin[i]];
        }
    }
}

int main()
{
    pre();
    int n;
    while(cin >> n)
    {
        cout << way[5][n] << endl;
    }
    return 0;
}*/


/*
#include<bits/stdc++.h>
using namespace std;
int way[7490];
void pre()
{

  int coin[5] = {1, 5, 10, 25, 50};
  memset(way,0,sizeof(way));
  way[0]=1;
  for(int j=0;j<5;j++){
    for(int i=1;i<65;i++){
      if(i>=coin[j]){
        way[i]+=way[i-coin[j]];
      }
      cout << way[i] << " ";
    }
    cout << endl;
  }
}
int main(){
    pre();
    int n;

    while(scanf("%d",&n)==1){

        cout<<way[n]<<endl;
  }

}
*/
