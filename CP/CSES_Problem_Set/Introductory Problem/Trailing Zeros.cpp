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
 
 
int main()
{
    BeatMeScanf;
    int n;
    cin>>n;
    ll ans = 0, p = 5;
    while(n/p!=0){
        ans += (n/p);
        p*=5;
    }
    cout<<ans<<endl;
    return 0;
}
