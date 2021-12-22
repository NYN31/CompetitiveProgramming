/***
    Problem name: Longest Zik-Zak Sequence
***/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 1030
#define inf 100000008

int n,arr[sz];
int dp1[sz],dp2[sz];

int lis(int in){
    if(dp1[in] != -1) return dp1[in];
    int mx=0;
    for(int j=in-1;j>=0;--j){
        if(arr[j]<arr[in]){
            int len=lis(j);
            if(len>mx) mx=len;
        }
    }
    dp1[in]=1+mx;
    return dp1[in];
}

int lds(int in){
    if(dp2[in] != -1) return dp2[in];
    int mx=0;
    for(int j=in+1;j<n;j++){
        if(arr[j]<arr[in]){
            int len=lds(j);
            if(len>mx) mx=len;
        }
    }
    dp2[in]=1+mx;
    return dp2[in];
}

int main()
{
    BeatMeScanf;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    memset(dp1,-1,sizeof dp1);
    memset(dp2,-1,sizeof dp2);
    int len1=0,len2=0,lzs=1;
    for(int i=n-1;i>=0;--i){
        len1=max(len1,lis(i));
    }
    for(int i=0;i<n;i++){
        len2=max(len2,lds(i));
    }
    for(int i=0;i<n;i++){
        lzs=max(lzs,dp1[i]+dp2[i]-1);
    }
    cout<<lzs<<endl; /// longest ZikZak Sequence
    return 0;
}

/*
input:
10
1 2 3 4 5 4 10 3 2 1
7
9 5 7 17 2 9 6

Output:
Case 1: 9
Case 2: 5
*/
