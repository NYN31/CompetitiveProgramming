// TO find longest palindromic subsequence use the logic of longest common subsequence

#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define mod 10000007

int dp[100][100];
string s;
int total;

int findlen(int i,int j){
    if(i>j) return 0;
    else if(i==j) return 1;
    else if(dp[i][j]!=-1) return dp[i][j];
    else if(s[i]==s[j]){
        total=findlen(i+1,j-1)+2;
        return dp[i][j]=total;
    }
    else{
        dp[i][j]=max(findlen(i+1,j),findlen(i,j-1));
        return dp[i][j];
    }
}


int main(){
    while(cin>>s){
        total=0;
        memset(dp,-1,sizeof(dp));
        int len=findlen(0,s.size()-1);
        cout<<len<<endl;
    }
    return 0;
}
