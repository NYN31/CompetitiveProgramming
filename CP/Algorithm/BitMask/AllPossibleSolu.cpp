///https://cses.fi/problemset/task/1623/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 1010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
 
const int mod = 1e9+7;
 
int main()
{
    BeatMeScanf;
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0;i<n;i++) cin>>arr[i];
 
    int tot = 1<<n;
    ll ans = INT_MAX;
    for(int mask=0;mask<tot;mask++) {
        ll sum1=0,sum2=0;
        for(int pos=0;pos<n;pos++) {
            int f = 1<<pos;
            if(mask&f) sum1+=arr[pos];
            else sum2+=arr[pos];
        }
        ans = min(ans,abs(sum1-sum2));
    }
    cout<<ans<<endl;
    
