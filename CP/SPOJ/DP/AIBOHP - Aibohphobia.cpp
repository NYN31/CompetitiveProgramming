#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 6030
 
string str1,str2;
int dp[sz][sz];
 
int lcs(int i,int j){
    if(str1[i]=='\0' || str2[j]=='\0') return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(str1[i]==str2[j]) return dp[i][j]=1+lcs(i+1,j+1);
    else return dp[i][j]=max(lcs(i+1,j),lcs(i,j+1));
}
 
int main()
{
    BeatMeScanf;
    int t;
    cin>>t;
    while(t--){
        cin>>str1;
        str2=str1;
        reverse(str2.begin(),str2.end());
        memset(dp,-1,sizeof dp);
        int ans=str1.size()-lcs(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
