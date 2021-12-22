/*
LIS best ans + solution
Complexity: O(n*max_value_of_given_number_in_array)
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 1001
#define inf 10000007

int n;
int arr[sz],dir[sz][sz];
int dp[sz][sz];

int lis(int in,int last){
    if(in == n) return 0;
    if(dp[in][last] != -1) return dp[in][last];
    int ans=-inf,bp=0;
    ans=max(ans,lis(in+1,last)); /// without taking in'th position value
    if(last<arr[in]){ /// taking in'th position value
        int temp=1+lis(in+1,arr[in]);
        if(temp>ans){
            ans=temp;
            bp=1;
        }
    }
    dir[in][last]=bp;
    return dp[in][last]=ans;
}

void solution(int in,int last){
    if(in == n) return;
    int bp=dir[in][last];
    if(bp==1){
        cout<<arr[in]<<" ";
        solution(in+1,arr[in]);
    }else solution(in+1,last);
}
int main()
{
    BeatMeScanf;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    memset(dp,-1,sizeof dp);
    int ans=lis(0,0);
    cout<<ans<<endl;
    solution(0,0);
    return 0;
}

/*
In this solution there are no need to compressed array, because the second
sate is also a index.... we used 2nd state in last program as the value of
the array, now we used as a index...!!

Complexity: O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 1001
#define inf 10000007

int n;
int arr[sz];
int dp[sz][sz];

int lis(int in,int last){
    if(in > n) return 0;
    if(dp[in][last] != -1) return dp[in][last];
    int ans=-inf;
    ans=lis(in+1,last);
    if(arr[last]<arr[in]) ans=max(ans,1+lis(in+1,in));
    return dp[in][last]=ans;
}

int main()
{
    BeatMeScanf;
    cin>>n;
    arr[0]=-inf;
    for(int i=1;i<=n;i++) cin>>arr[i];
    memset(dp,-1,sizeof dp);
    int ans=lis(1,0);
    cout<<ans<<endl;
    return 0;
}

/***
    with solution print

    Recursive in O(n^2)
***/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 1001
#define inf 10000007

int n;
int arr[sz],dir[sz];
int dp[sz];

int lis(int u){
    if(dp[u]!=-1) return dp[u];
    int mx=0;
    for(int v=u+1;v<=n;v++){
        if(arr[v]>arr[u]){
            int len=lis(v);
            if(len>mx){
                mx=len;
                dir[u]=v;
            }
        }
    }
    dp[u]=1+mx;
    return dp[u];
}

void sol(int i){
    cout<<"LIS: ";
    while(dir[i] != -1){
        cout<<arr[i]<<" ";
        i=dir[i];
    }
    cout<<arr[i];
    cout<<endl;
}

int main()
{
    BeatMeScanf;
    cin>>n;
    arr[0]=-inf;
    for(int i=1;i<=n;i++) cin>>arr[i];
    memset(dp,-1,sizeof dp);
    memset(dir,-1,sizeof dir);

    int len=0,mxlen=0,start=0;
    for(int i=1;i<=n;i++){
        len=lis(i);
        if(len>mxlen){
            mxlen=len;
            start=i;
        }
    }
    sol(start);
    return 0;
}



/***
    Iterative LIS Problem
***/

int lis_iterative(){
    memset(dp,1,sizeof dp) ;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] > arr[i] && dp[i]+1 > dp[j])
                dp[j] = dp[i] + 1 ;
        }
    }

    int mx = 0 ;
    for(int i=0; i<n; i++)
        mx = max(mx,dp[i]) ;
    return mx ;
}
