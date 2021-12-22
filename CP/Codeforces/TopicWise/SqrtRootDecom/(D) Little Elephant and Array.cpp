
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

ll const mod = 1e9+7;
ll const sz = 1e5+5;
ll const lim = 1e7+5;
ll n,q,k,sol;
ll arr[sz+5], ans[sz+5], freqar[lim+5];
map<ll,ll>freqmp;

struct Query{
    int idx, l, r;
    bool operator < (Query const &ob)const{
       return mp(l/k,r) < mp(ob.l/k,ob.r) ;
    }
}query[sz];

void add(ll idx) {
	if(arr[idx] <= lim) {
		freqar[ arr[idx] ] += 1 ;
		ll x = freqar[ arr[idx] ];
		if(x == arr[idx]) sol += 1;
		if(arr[idx] + 1 == x) sol -= 1;
	}
	else {
		freqmp[ arr[idx] ] += 1 ;
		ll x = freqmp[ arr[idx] ];
		if(x == arr[idx]) sol += 1;
		if(arr[idx] + 1 == x) sol -= 1;
	}
}
void remov(ll idx) {
	if(arr[idx] <= lim) {
		freqar[ arr[idx] ] -= 1;
		ll x = freqar[ arr[idx] ];
		if(x == arr[idx]) sol += 1;
		if(x == arr[idx] - 1) sol -= 1;
	}
	else {
		freqmp[ arr[idx] ] -= 1;
		ll x = freqmp[ arr[idx] ];
		if(x == arr[idx]) sol += 1;
		if(x == arr[idx] - 1) sol -= 1;
	}
}

void solve() {
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++) scanf("%I64d",&arr[i]);

    k = sqrt(n);

    for(int i=0;i<q;i++) {
        scanf("%d %d",&query[i].l, &query[i].r);
        query[i].idx = i;
        --query[i].l, --query[i].r;
    }
    sort(query,query+q);
    ll l=0,r=-1;
    for(int i=0;i<q;i++) {
        while(r<query[i].r) add(++r);
        while(l<query[i].l) remov(l++);
        while(r>query[i].r) remov(r--);
        while(l>query[i].l) add(--l);
        ans[ query[i].idx ] = sol;
    }
    for(int i=0;i<q;i++) printf("%I64d\n",ans[i]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int t = 1, no = 0;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
