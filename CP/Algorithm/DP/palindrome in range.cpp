/*
Problem name: Find Palindrome in range
You are given a string, and Q queries. Each qeury has two value represent as the two indexes of
the string, and you are to query that the range of given string is palindrome or not palidrome
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 1000

int dp[sz][sz];
string str;

int palindrome(int st,int ed){
    if(st>=ed) return 1;
    if(dp[st][ed]!=-1) return dp[st][ed];
    int ans=0;
    if(str[st]==str[ed] && palindrome(st+1,ed-1))
        ans=1;
    else ans=0;
    return dp[st][ed]=ans;
}

int main()
{
    BeatMeScanf;
    cin>>str;
    memset(dp,-1,sizeof dp);
    while(true){
        int a,b;
        cin>>a>>b;
        int ans=palindrome(a,b);
        if(ans) cout<<"Palindrome"<<endl;
        else cout<<"Not Palindrome"<<endl;
    }
    return 0;
}

// BABABCBADCD
