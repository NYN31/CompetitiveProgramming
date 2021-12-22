#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;

vector<int> sieve_with_wheel(int n) {
    if(n <= 32) {
        vector<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
        vector<int> ans;
        for(int i = 0; i < primes.size(); i++) {
            if(n < primes[i]) {
                return ans;
            }
            ans.push_back(primes[i]);
        }
        return primes;
    }
    int u = n + 32;
    double lu = log(u);
    vector<int> ret (u / lu + u / lu / lu * 1.5, 0);
    ret[0] = 2;
    int pos = 1;
    vector<int> isp ((n + 1) / 32 / 2 + 1, 0);
    int sup = (n + 1) / 32 / 2 + 1;

    vector<int> tprimes = { 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    for(int tp : tprimes) {
        ret[pos++] = tp;
        vector<int> ptn(tp);
        for(int i = (tp - 3) / 2; i < tp << 5; i += tp)
            ptn[i >> 5] |= 1 << (i & 31);
        for(int i = 0; i < tp; i++) {
            for(int j = i; j < sup; j += tp)
                isp[j] |= ptn[i];
        }
    }
    vector<int> magic = { 0, 1, 23, 2, 29, 24, 19, 3, 30, 27, 25, 11, 20, 8, 4,
                          13, 31, 22, 28, 18, 26, 10, 7, 12, 21, 17, 9, 6, 16, 5, 15, 14
                        };
    int h = n / 2;
    for(int i = 0; i < sup; i++) {
        for(int j = ~isp[i]; j != 0; j &= j - 1) {
            int pp = i << 5 | magic[(1u*(j & -j) * 0x076be629 >> 27)]; //magic[x] = __builtin_clzll(x)
            int p = 2 * pp + 3;
            if(p > n)
                break;
            ret[pos++] = p;
            for(int q = pp; q <= h; q += p)
                isp[q >> 5] |= 1 << (q & 31);
        }
    }
    ret.resize(pos);
    return ret;
}
int a[N];
struct ST
{
    int tmx[4 * N], tmn[4 * N];
    ST(){}
    void build(int n, int b, int e)
    {
        if(b == e){
            tmx[n] = tmn[n] = a[b];
            return;
        }
        int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        tmx[n] = max(tmx[l], tmx[r]);
        tmn[n] = min(tmn[l], tmn[r]);
    }
    void upd(int n, int b, int e, int i, int x)
    {
        if(b > i || e < i) return;
        if(b == e && b == i){
            tmx[n] = tmn[n] = x;
            return;
        }
        int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
		tmx[n] = max(tmx[l], tmx[r]);
        tmn[n] = min(tmn[l], tmn[r]);
    }
    pair<int, int> query(int n, int b, int e, int i, int j)
    {
        if(b > j || e < i) return {1e9, 0};
        if(b >= i && e <= j) return {tmn[n], tmx[n]};
        int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
        pair<int, int> L = query(l, b, mid, i, j);
        pair<int, int> R = query(r, mid + 1, e, i, j);
        return {min(L.first, R.first), max(L.second, R.second)};
    }
}t;
int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<int> primes = sieve_with_wheel(100000002);
	long long ans = 1;
	//for (auto x: primes) if (x < 40) ans *= x;
	//cout << ans << '\n';
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	t.build(1, 1, n);
	while (q--) {
		int ty, l, r; cin >> ty >> l >> r;
		if (ty == 1) {
			t.upd(1, 1, n, l, r);
		}
		else {
			pair<int, int> p = t.query(1, 1, n, l, r);
			int ans = upper_bound(primes.begin(), primes.end(), p.second) -
				lower_bound(primes.begin(), primes.end(), p.first);
			cout << ans << '\n';
		}
	}
    return 0;
}
