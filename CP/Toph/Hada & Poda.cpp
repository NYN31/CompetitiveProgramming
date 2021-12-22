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

int const mod = 1e9;
int const N = 200010;
int const M = 1000010;

int n,t;
ll k,sum, x;
ll arr[N], ans[N], freq[M];
// ll presum[N];

struct Query{
    int idx, l, r;
    bool operator < (const Query &other) const{
        ll own = l/k;
        ll otr = other.l/k;
        if(own == otr) return r < other.r;
        else return own < otr;
    }
}query[N];

/*void precal() {
    presum[0]=0;
    for(int i=1;i<N;i++) {
        if(i & 1) presum[i]=i;
        else presum[i]=0;
        presum[i]+=presum[i-1];
    }
    for(int i=0;i<20;i++) cout<<presum[i]<<endl;
}*/

void add(int idx){
    ll tm = freq[arr[idx]];
    ll val = (tm+1)/2;
    sum -= (val*val*arr[idx]);
    freq[ arr[idx] ]++;
    tm += 1;
    val = (tm+1)/2;
    sum += (val*val*arr[idx]);
}
void del(int idx){
    ll tm = freq[arr[idx]];
    ll val = (tm+1)/2;
    sum -= (val*val*arr[idx]);
    freq[ arr[idx] ]--;
    tm -= 1;
    val = (tm+1)/2;
    sum += (val*val*arr[idx]);
}

int main(){
    BeatMeScanf;
    //precal();
    scanf("%d %d",&n,&t);
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]);

    k = sqrt(n);

    for(int i=0;i<t;i++) {
        scanf("%d %d",&query[i].l, &query[i].r);
        query[i].idx = i;
        --query[i].l, --query[i].r;
    }
    sort(query, query+t);
    int r = -1, l = 0;
    for(int i=0;i<t;i++) {
        while(r<query[i].r) add(++r);
        while(l<query[i].l) del(l++);
        while(r>query[i].r) del(r--);
        while(l>query[i].l) add(--l);
        ans[ query[i].idx ] = sum;
    }
    for(int i=0;i<t;i++) printf("%lld\n",ans[i]);
}
