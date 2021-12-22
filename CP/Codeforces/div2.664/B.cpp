    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define ull unsigned long long
    #define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
     
    #define pii pair<int,int>
    #define ff first
    #define ss second
    #define pb push_back
     
    void solve() {
    	int x,y,a,b; cin>>x>>y>>a>>b;
    	vector<pii>index;
    	for(int i=b;  i>=1;--i) index.pb({a,i});
    	for(int i=b+1;i<=y;i++) index.pb({a,i});
    	int k = 1;
    	for(int i=a+1;i<=x;i++) {
    		vector<pii>p;
    		for(int j=1;j<=y;j++) {
    			p.pb({j,i});
    		}
    		if(k%2 == 1) {
    			sort(p.rbegin(), p.rend()) ;
    			for(auto s : p) index.pb({s.ss, s.ff});
    		}
    		else for(auto s : p) index.pb({s.ss, s.ff});
    		k++;
    	}
    	for(int i=1;i<a;i++) {
    		vector<pii>p;
    		for(int j=1;j<=y;j++) {
    			p.pb({j, i});
    		}
    		if(k%2 == 1) {
    			sort(p.rbegin(), p.rend());
    			for(auto s : p) index.pb({s.ss, s.ff});
    		}
    		else for(auto s : p) index.pb({s.ss, s.ff});
    		k++;
    	}
    	for(int i=0;i<index.size();i++)
    		cout<<index[i].ff<< " " <<index[i].ss<<endl;
    	return ;
    }
     
    int main() {
        BeatMeScanf;
        int t = 1, no = 0;
        //cin>>t;
        while(t--) {
            solve();
        }
        return 0;
    }