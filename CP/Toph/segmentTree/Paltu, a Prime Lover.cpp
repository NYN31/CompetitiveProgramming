#include<bits/stdc++.h>
using namespace std;
#define ll long long

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

const ll lim1 = 1e8+5 ;
const ll lim2 = 1e5+5 ;
pair<int,int>tree[4*lim2+5];
ll n, q, arr[lim2+1];
ll mark[ (lim1/64)+5 ] ;
vector<int> primes ;

inline ll   setBit(ll num, ll pos){ return num = (num | (1LL<<pos)); }
inline bool getBit(ll num, ll pos){ return (bool)(num & (1LL<<pos)); }

void sieve(){
    primes.pb(2) ;
    for(ll i=4; i<lim1; i+=2) mark[i/64LL] = setBit(mark[i/64LL], i%64LL) ;
    for(ll i=3; i<lim1; i+=2){
        if(getBit(mark[i/64LL], i%64LL)) continue ;
        primes.pb(i) ;
        for(ll j=i*i; j<lim1; j+=2*i)
            mark[j/64LL] = setBit(mark[j/64LL], j%64LL) ;
    }
}

void build(int node, int b, int e) {
    if(b == e) {
        tree[node].ff = tree[node].ss = arr[b];
        return ;
    }
    int mid, left, right;
    left = 2 * node;
    right = left + 1;
    mid = (b + e) / 2;
    build(left, b, mid);
    build(right, mid+1, e);
    tree[node].ff = min(tree[left].ff, tree[right].ff);
    tree[node].ss = max(tree[left].ss, tree[right].ss);
}

void update(int node, int b, int e, int pos, int val) {
    if(b > pos || e < pos) return;
    if(b == e && b == pos){
        tree[node].ff = tree[node].ss = val;
        return;
    }
    int mid, left, right;
    left = 2 * node;
    right = left + 1;
    mid = (b + e) / 2;
    update(left, b, mid, pos, val);
    update(right, mid+1, e, pos, val);
    tree[node].ff = min(tree[left].ff, tree[right].ff);
    tree[node].ss = max(tree[left].ss, tree[right].ss);
}
pair<int,int> query(int node, int b, int e, int i, int j) {
    if(b > j || e < i) return {1e9, 0};
    if(b >= i && e <= j) {
        return {tree[node].ff, tree[node].ss};
    }
    int mid, left, right;
    left = 2 * node;
    right = left + 1;
    mid = (b + e) / 2;
    pair<int,int> p1, p2;
    p1 = query(left, b, mid, i, j);
    p2 = query(right, mid+1, e, i, j);
    return {min(p1.ff, p2.ff), max(p1.ss, p2.ss)};
}

int main() {
    sieve();
    scanf("%lld %lld",&n,&q);
    for(int i=1;i<=n;i++) scanf("%lld", &arr[i]);
    build(1,1,n);
    while(q--) {
        int ch; scanf("%d",&ch);
        if(ch == 1) {
            int pos, val;
            scanf("%d %d", &pos, &val);
            update(1,1,n,pos,val);
        } else{
            int l, r;
            scanf("%d %d",&l, &r);
            pair<int,int> p = query(1,1,n,l,r);
            int ans = upper_bound(primes.begin(), primes.end(), p.second) -
                lower_bound(primes.begin(), primes.end(), p.first);
            printf("%d\n", ans);
        }
    }
    return 0;
}
