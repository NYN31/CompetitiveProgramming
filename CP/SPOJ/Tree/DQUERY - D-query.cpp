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

int const mod = 1e9;
int n,q,k,sum;
int arr[30010], ans[200010], freq[1000100];

struct Query{
    int idx, l, r;
    bool operator < (const Query & other) const{
        int own = l/k;
        int otr = other.l/k;
        if(own == otr) return r < other.r;
        else return own < otr;
    }
}query[200010];

/*bool cmp(Query a, Query b){
    if(a.l/k != b.l/k) return a.l/k < b.l/k;
    return a.r < b.r;
}*/
void add(int idx) {
    freq[arr[idx]]++;
    if(freq[arr[idx]] == 1) sum++;
}
void remov(int idx) {
    freq[arr[idx]]--;
    if(freq[arr[idx]] == 0) sum--;
}
int main()
{
    BeatMeScanf;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    k = sqrt(n);

    cin>>q;
    for(int i=0;i<q;i++) {
        cin>>query[i].l>>query[i].r;
        query[i].idx = i;
        --query[i].l;
        --query[i].r;
    }
    sort(query,query+q);
    int l=0,r=-1;
    for(int i=0;i<q;i++) {
        while(r<query[i].r) add(++r);
        while(l<query[i].l) remov(l++);
        while(r>query[i].r) remov(r--);
        while(l>query[i].l) add(--l);
        ans[query[i].idx]=sum;
    }
    for(int i=0;i<q;i++) cout<<ans[i]<<endl;
    return 0;
}
