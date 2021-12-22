/*
    Problem name: Longest Repeated subsequence
*/

#include<bits/stdc++.h>
using namespace std;
string s;
int dp[100][100];

int findlen(int i, int j){
    if(i==0 || j==0) return 0;
    else if(dp[i][j]!=0) return dp[i][j];
    else if(s[i-1]==s[j-1] && i!=j)
        return dp[i][j]=findlen(i-1,j-1)+1;
    else return dp[i][j]=max(findlen(i-1,j), findlen(i,j-1));
}


int main(){
    while(cin>>s){
        memset(dp,0,sizeof(dp));
        int m = s.size();
        cout<<findlen(m,m)<<endl;
    }
    return 0;
}
