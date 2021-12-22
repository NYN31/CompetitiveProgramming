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

int const N = 17;
int cost[N+1][N+1], n, target;
int dp[N][(1<<N)+10];

int setbit(int n,int pos){ return (n|(1<<pos)); }
bool checkbit(int n,int pos){ return (bool)(n&(1<<pos)); }
int tooglebit(int n,int pos){ return (n^(1<<pos)); }
vector<ll>vec;

int solve(int r, int mask) {
    if(r == n) return 0;
    int &ret = dp[r][mask];
    if(ret != -1) return ret ;

    int ans = 0;
    for(int c=0;c<n;c++) {
        if(!(checkbit(mask, c))) {
            int temp = cost[r][c] + solve(r+1, setbit(mask, c));
            if(temp > ans) ans = temp;
        }
    }
    ret = ans;
    return ret;
}

int main() {
    BeatMeScanf;
    int t, no = 0; cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                cin>>cost[i][j];
            }
        }
        memset(dp, -1, sizeof dp);
        int ans = 0;
        ans = solve(0, 0);
        cout<<"Case "<<++no<<": "<<ans<<endl;
        memset(cost, 0, sizeof cost);
    }
    return 0;
}
