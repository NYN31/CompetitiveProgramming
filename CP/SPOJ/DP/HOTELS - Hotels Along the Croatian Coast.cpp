#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 100010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

int const N = 18;

int main() {
    BeatMeScanf;
    ll n, m;
    cin>>n>>m;
    int arr[n+5];
    for(int i=0;i<n;i++) cin>>arr[i];
    int i=0, j=0;
    ll sum = 0, mx = 0;
    while(j<n) {
        if(arr[j]+sum <= m)
            sum += arr[j++];
        else sum -= arr[i++];
        mx = max(sum, mx);
    }
    cout<<mx<<endl;
    return 0;
}
