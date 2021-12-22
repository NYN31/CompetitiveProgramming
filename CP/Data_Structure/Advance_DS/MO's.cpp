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
int n,q,k,sum;
int arr[sz], ans[sz];

struct Query{
    int idx, l, r;
    bool operator < (const Query & other) const{
        int own = l/k;
        int otr = other.l/k;
        if(own == otr) return r < other.r;
        else own < otr;
    }
    bool operator < (Query const &ob)const{
       return mp(l/k,r) < mp(ob.l/k,ob.r) ;
    }
}query[sz];

void add(int idx) {
    sum += arr[idx];
}
void remov(int idx) {
    sum -= arr[idx];
}
int main()
{
    BeatMeScanf;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>arr[i];

    k = sqrt(n);

    for(int i=0;i<q;i++) {
        cin>>query[i].l>>query[i].r;
        query[i].idx = i;
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
    for(int i=0;i<q;i++) cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}

