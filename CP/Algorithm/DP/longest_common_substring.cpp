/// Iterative: length with string

#include<bits/stdc++.h>
using namespace std;
int const sz = 100;

string x,y;
int dp[sz][sz];

int main(){
    while(cin>>x>>y){
        int maxlen=0,lastind=0;
        memset(dp,0,sizeof(dp));
        int x1=x.size(),y1=y.size();
        for(int i=1;i<=x1;i++){
            for(int j=1;j<=y1;j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                    if(dp[i][j]>maxlen){
                        maxlen=dp[i][j];
                        lastind=i;
                    }
                }
            }
        }
        cout<<maxlen<<" "<<x.substr(lastind-maxlen,maxlen)<<endl;
    }
    return 0;
}


/// Recursive: length with string 
#include<bits/stdc++.h>
using namespace std;
int const sz = 100;

string x,y;
int dp[sz][sz],mx,total,ind;

int lcs(int n, int m){
    if(n==0 || m==0) return 0;
    else if(dp[n][m]!=0) return dp[n][m];
    else if(x[n-1]==y[m-1]){
        total=lcs(n-1,m-1)+1;
        if(mx<total){
            mx=total;
            ind=n;
        }
        return dp[n][m]=total;
    }
    else{
        lcs(n-1,m);
        lcs(n,m-1);
    }
}
int main(){
    while(cin>>x>>y){
        mx=0,total=0,ind=0;
        memset(dp,0,sizeof(dp));
        int ans=max(mx,lcs(x.size(),y.size()));
        cout<<ind<<endl;

        for(int i=0;i<=x.size();i++){
            for(int j=0;j<=y.size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<ans<<" "<<x.substr(ind-mx,mx)<<endl;
    }
    return 0;
}
/*
BABA
ABAC

ABBBACAS
DBBACDKL

ABBABCD
BVGBBAF
*/
