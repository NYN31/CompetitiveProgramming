    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define ull unsigned long long
    #define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

    #define pii pair<int,int>
    #define ff first
    #define ss second
    #define pb push_back

    int n, m;
    int dp[210][520], res[210][520];

    int go(int i, int val) {
    	if(i == n) return val;
    	//cout<<i<<" "<<j<<endl;
    	int &ret = dp[i][val];
    	if(ret != -1) return ret;
    	int ans = 1e9;
    	for(int k=0;k<m;k++) {
    		ans = min(ans, go(i+1, val|res[i][k]));
    	}
    	ret = ans ;
    	return ret ;
    }

    void solve() {
    	cin>>n>>m;
    	vector<int> arr(n), brr(m);
    	for(int i=0;i<n;i++) cin>>arr[i];
    	for(int i=0;i<m;i++) cin>>brr[i];

    	for(int i=0;i<n;i++) {
    		for(int j=0;j<m;j++) {
    			int val = (arr[i] & brr[j]);
    			res[i][j] = val;
    		}
    	}
    	memset(dp, -1, sizeof dp);
    	int ans = go(0,0);
    	cout<<ans<<endl;
    }

    int main() {
        BeatMeScanf;
        int t = 1, no = 0;
        // cin>>t;
        while(t--) {
            solve();
        }
        return 0;
    }
