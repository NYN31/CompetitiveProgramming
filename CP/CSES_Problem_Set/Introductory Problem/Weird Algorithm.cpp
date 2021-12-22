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
    ll n;
    cin>>n;
    while(n!=1) {
        cout<<n<<" ";
        if(n%2==0) n /= 2;
        else if(n%2==1) n = 3*n+1;
    }
    cout<<n<<endl;
    return 0;
}
