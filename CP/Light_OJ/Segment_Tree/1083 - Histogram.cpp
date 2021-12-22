#include<bits/stdc++.h>
using namespace std;
#define sz 100100
#define ll long long
 
struct info{
    ll val,ind;
}tree[4*sz];
ll arr[sz],n;
 
void init(ll node,ll b,ll e){
    if(b==e){
        tree[node].val=arr[b];
        tree[node].ind=b;
        return;
    }
    ll left=node*2,
        right=left+1,
        mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    if(tree[left].val>tree[right].val){
        tree[node].val=tree[right].val;
        tree[node].ind=tree[right].ind;
    }
    else {
        tree[node].val=tree[left].val;
        tree[node].ind=tree[left].ind;
    }
}
pair<ll,ll> query(ll node,ll b,ll e,ll i,ll j){
    if(i>e || j<b) {
        pair<ll,ll>v;
        v.first=INT_MAX;
        v.second=-1;
        return v;
    }
    if(b>=i && e<=j){
        pair<ll,ll>v;
        v.first=tree[node].val;
        v.second=tree[node].ind;
        return v;
    }
    ll left=node*2,
        right=left+1,
        mid=(b+e)/2;
    pair<ll,ll> q1=query(left,b,mid,i,j);
    pair<ll,ll> q2=query(right,mid+1,e,i,j);
    if(q1.first>q2.first) {
        pair<ll,ll>v;
        v.first=q2.first;
        v.second=q2.second;
        return v;
    }
    else{
        pair<ll,ll>v;
        v.first=q1.first;
        v.second=q1.second;
        return v;
    }
}
ll solve(ll l,ll r){
    if(l==r) return arr[l];
    if(l>r) return INT_MIN;
 
    ll ans=INT_MIN;
    pair<ll,ll> mn=query(1,1,n,l,r);
 
    ll mid=mn.second;
    ans=max(ans,arr[mid]*(r-l+1));
    ans=max(ans,solve(l,mid-1));
    ans=max(ans,solve(mid+1,r));
    return ans;
}
int main(){
    int t,no=0;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<=4*sz;i++) tree[i].val=0,tree[i].ind=0;
        for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
        init(1,1,n);
        ll ans=solve(1,n);
        printf("Case %d: %lld\n",++no, ans);
    }
    return 0;
}
 
