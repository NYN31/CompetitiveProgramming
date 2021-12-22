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
    char arr[26];
    for(int i=65;i<=90;i++) arr[i-65]=(char)i;

    int t;
    cin>>t;
    while(t--) {
        int  n;
        cin>>n;

        int tot=1<<n;
        for(int mask=0; mask<tot;mask++){
            for(int i=0;i<n;i++) {
                int f = 1<<i;
                if(mask&f) cout<<arr[i];
            }
            cout<<endl;
        }
    }
    return 0;
}
