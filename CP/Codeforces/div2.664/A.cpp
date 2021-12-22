    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define ull unsigned long long
    #define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
     
    #define pii pair<int,int>
    #define ff first
    #define ss second
    #define pb push_back
     
    bool go1(ll arr[]) {
    	int cnt = 0;
    	for(int i=0;i<4;i++) {
    		if(arr[i] == 0) cnt++;
    	}
    	return (cnt == 3) ;
    }
     
    bool go2(ll arr[]) {
    	int cnt = 0;
    	for(int i=0;i<4;i++) {
    		if(arr[i]%2 == 1) cnt++;
    	}
    	return (cnt <= 1) ;
    }
    bool go3(ll arr[]) {
    	int mn = *min_element(arr, arr+3);
    	if(mn == 0) {
    		int cnt = 0;
    		for(int i=0;i<4;i++) {
    			if(arr[i] % 2 == 1) {
    				cnt++;
    			}
    		}
    		return (cnt <= 1) ;
    	}
    	else {
    		arr[0] -= 1, arr[1] -= 1, arr[2] -= 1, arr[3] += 3;
    		if(go2(arr)) return true;
    	}
    	return false;
    }
     
    void solve() {
    	ll arr[10], cnt = 0;
    	for(int i=0;i<4;i++) cin>>arr[i];
    	if(go1(arr)) cout<<"Yes"<<endl;
    	else if(go2(arr)) cout<<"Yes"<<endl;
    	else if(go3(arr)) cout<<"Yes"<<endl;
    	else cout<<"No"<<endl;
    }
     
    int main() {
        BeatMeScanf;
        int t = 1, no = 0;
        cin>>t;
        while(t--) {
            solve();
        }
        return 0;
    }