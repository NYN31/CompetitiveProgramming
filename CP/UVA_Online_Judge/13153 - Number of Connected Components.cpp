#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define lim 1000010

bool isprime[lim+5];
vector<ll>primes;
vector<int>adj[lim+5];
bool vis[lim+5];

void sieve(){
    for(int i=0;i<lim;i++) isprime[i]=true;
    for(int i=4;i<lim;i+=2) isprime[i]=false;
    isprime[0]=isprime[1]=0;
    primes.pb(2);
    for(ll i=3;i<lim;i+=2) {
        if(isprime[i]) {
            primes.pb(i);
            for(ll j=i*i;j<lim;j+=i)
                isprime[j]=false;
        }
    }
}

void dfs(int s) {
	vis[s] = 1;
	for(auto x : adj[s]) {
		if(!vis[x]) {
			dfs(x);
		}
	}
}
void factor(ll n) {
	vector<int>fv;
	ll num = n;
	if(isprime[n]) fv.pb(n);
	else{
		for(int i=0;i<primes.size()&&primes[i]*primes[i]<=n;i++) {
			ll p = primes[i];
			if(n % p != 0) continue;
			while(n % p == 0) {
				n /= p;
				fv.pb(p);
			}
		}
		if(n > 1) fv.pb(n);
	}
	if(fv.size() == 1) adj[fv[0]].pb(fv[0]);
	else{
		for(int i=0;i<fv.size();i++) {
			adj[num].pb(fv[i]);
			adj[fv[i]].pb(num);
		}
	}
}

int main() {
    sieve();
    int t , no = 0; scanf("%d", &t);
    while(t--) {
    	for(int i=0;i<lim;i++) adj[i].clear();
    	int n, mx = 0, one = 0; scanf("%d", &n);
    	for(int i=1;i<=n;i++) {
    		int num; scanf("%d", &num);
    		if(num == 1) {
    			one++;
    			continue;
    		}
    		factor(num);
    		mx = max(mx, num);
    	}
    	memset(vis, 0, sizeof vis);
    	int cnt = 0;
    	for(int i=1;i<=mx;i++) {
    		if(adj[i].size() == 0) continue;
    		if(!vis[i]) {
    			dfs(i);
    			cnt++;
    		}
    	}
    	printf("Case %d: %d\n", ++no, cnt+one);
    }
    return 0;
}
