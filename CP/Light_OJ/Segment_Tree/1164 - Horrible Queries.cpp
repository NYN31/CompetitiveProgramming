#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100100
ll arr[sz];
struct inf{
    ll prop,sum;
}tree[3*sz];
void init(ll node,ll b,ll e){
    if(b==e){
        tree[node].sum=arr[b];
        return;
    }
    ll right,left,mid;
    left=node<<1;
    right=left+1;
    mid=(b+e)>>1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

void update(ll node,ll b,ll e,ll i,ll j,ll nv){
    if(i>e || j<b) return;
    if(b>=i && e<=j) {
        tree[node].prop+=nv;
        tree[node].sum+=(e-b+1)*nv;
        return;
    }
    ll right,left,mid;
    left=node<<1;
    right=left+1;
    mid=(b+e)>>1;
    update(left,b,mid,i,j,nv);
    update(right,mid+1,e,i,j,nv);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
ll query(ll node,ll b,ll e,ll i,ll j,ll carry=0){
    if(i>e || j<b) return 0LL;
    if(b>=i && e<=j) return tree[node].sum+carry*(e-b+1);
    ll right,left,mid;
    left=node<<1;
    right=left+1;
    mid=(b+e)>>1;
    ll p1=query(left,b,mid,i,j,carry+tree[node].prop);
    ll p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}

int main(){
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        ll n,q;
        scanf("%lld %lld",&n,&q);
        for(int i=0;i<3*sz;i++) {
            tree[i].sum=0;
            tree[i].prop=0;
        }
        for(int i=1;i<=n;i++) cin>>arr[i];
        init(1,1,n);
        printf("Case %d:\n",++no);
        while(q--){
            ll ch,i,j,nv;
            scanf("%lld",&ch);
            if(ch==0){
                scanf("%lld %lld %lld",&i,&j,&nv);
                ++i,++j;
                update(1,1,n,i,j,nv);
            }
            else {
                scanf("%lld %lld", &i,&j);
                ++i,++j;
                ll ans=query(1,1,n,i,j);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
