#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 200100
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
 
const int mod = 1e9+7;
 
int pref[sz];
 
int main()
{
    BeatMeScanf;
    int n;
    cin>>n;
    --n;
    int arr[n+5];
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
        pref[arr[i]] = 1;
    }
    for(int i=1;i<=n+1;i++) {
        if(pref[i]==0){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
