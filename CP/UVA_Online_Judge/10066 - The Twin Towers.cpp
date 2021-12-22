#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 110
int n1,n2,arr[sz],brr[sz];
int dp[sz][sz];

int lcs(int m,int n){
    if(m==n1 || n==n2) return 0;
    else if(dp[m][n]!=-1) return dp[m][n];
    else if(arr[m]==brr[n]) return dp[m][n]=lcs(m+1,n+1)+1;
    else return dp[m][n]=max(lcs(m+1,n),lcs(m,n+1));
}

int main(){
    int no=0;
    while(cin>>n1>>n2 && n1!=0 && n2!=0){
        for(int i=0;i<n1;i++) cin>>arr[i];
        for(int i=0;i<n2;i++) cin>>brr[i];

        memset(dp,-1,sizeof dp);
        int ans=lcs(0,0);
        cout<<"Twin Towers #"<<++no<<endl;
        cout<<"Number of Tiles : "<<ans<<endl<<endl;
    }
}

/*
Twin Towers #1
Number of Tiles : 4
*/


/*#include<bits/stdc++.h>
using namespace std;

ll LCS(ll a1[], ll a2[], ll n1, ll n2)
{
    ll L[n1+2][n2+2];
    for(ll i = 0; i<=n1; i++){
        for(int j = 0; j<=n2; j++){
            if(i == 0 || j == 0)
                L[i][j] = 0;
            else if(a1[i-1] == a2[j-1])
                L[i][j] = 1 + L[i-1][j-1];
            else
                L[i][j] = max(L[i][j-1], L[i-1][j]);
        }
    }
    return L[n1][n2];
}

int main()
{
    ll a1[105], a2[105];
    ll n1, n2, no = 0;
    while(cin >> n1 >> n2)
    {
        if(n1 == 0 && n2 == 0)
            break;
        for(ll i = 0; i<n1; i++) cin >> a1[i];
        for(ll i = 0; i<n2; i++) cin >> a2[i];

        cout << "Twin Towers #" << ++no << endl << "Number of Tiles : " << LCS(a1, a2, n1, n2) << endl << endl;
    }
    return 0;
}*/
