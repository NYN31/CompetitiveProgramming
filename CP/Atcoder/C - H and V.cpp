
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

int const N = 6;
int color[N+1][N+1];
int n, m, k, tot;

int go(int r, int mask) {
    if(r == n+m) {
        int sum = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if((mask&(1<<i)) && (mask&(1<<(j+n))))
                    sum += color[i][j];
            }
        }
        return (sum == k);
    }
    int ans = go(r+1, mask);
    ans += go(r+1, mask|(1<<r));
    return ans;
}

int main() {
    BeatMeScanf;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) {
        string str; cin>>str;
        for(int j=0;j<m;j++) {
            color[i][j] = (str[j]=='#') ? 1 : 0;
            if(color[i][j] == 1) tot++;
        }
    }
    ll ans = 0;
    ans = go(0,0);
    cout<<ans<<endl;
    return 0;
}
