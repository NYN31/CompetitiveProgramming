//Longest common subsequence

#include<bits/stdc++.h>
using namespace std;
string s,t;
int dp[1010][1010];
int total,s1,t1;
int lcs(int n,int m){
    if(n==-1 || m==-1) return 0;
    else if(dp[n][m]!=-1) return dp[n][m];
    else if(s[n]==t[m]) total=lcs(n-1,m-1)+1;
    else total=max(lcs(n-1,m),lcs(n,m-1));
    return dp[n][m]=total;
}

int main(){
    while(getline(cin,s)){
        getline(cin,t);
        s1=s.size();
        t1=t.size();
        memset(dp,-1,sizeof(dp));
        int ans=lcs(s1-1,t1-1);
        cout<<ans<<endl;
    }
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
string s,t;
int dp[1010][1010];
int total;
int lcs(int n,int m){
    if(n==s.size() || m==t.size()) return 0;
    else if(dp[n][m]!=-1) return dp[n][m];
    else if(s[n]==t[m]) return dp[n][m]=lcs(n+1,m+1)+1;
    else return dp[n][m]=max(lcs(n+1,m),lcs(n,m+1));
}

int main(){
    while(getline(cin,s)){
        getline(cin,t);
        memset(dp,-1,sizeof(dp));
        int ans=lcs(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
/*
ABCBDAB
BDCABA
*/

*/
