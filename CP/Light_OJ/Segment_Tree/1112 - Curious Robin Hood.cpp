#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 100100
 
ll arr[sz], tree[4*sz];
 
void build(int node,int b,int e){
    if(b==e){
        tree[node]=arr[b];
        return ;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
 
void update(int node,int b,int e,int pos,int nv){
    if(pos>e || pos<b) return ;
    if(b==pos && e==pos){
        tree[node]+=nv;
        return ;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    update(left,b,mid,pos,nv);
    update(right,mid+1,e,pos,nv);
    tree[node]=tree[left]+tree[right];
}
 
void update2(int node,int b,int e,int pos){
    if(pos>e || pos<b) return;
    if(b==pos && e==pos) {
        tree[node]=0;
        return ;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    update2(left,b,mid,pos);
    update2(right,mid+1,e,pos);
    tree[node]=tree[left]+tree[right];
}
 
ll query1(int node,int b,int e,int pos){
    if(pos>e || pos<b) return 0LL;
    if(b>=pos && e<=pos){
        ll x=tree[node];
        tree[node]=0;
        return x;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    ll q1=query1(left,b,mid,pos);
    ll q2=query1(right,mid+1,e,pos);
    return q1+q2;
}
 
ll query2(int node,int b,int e,int i,int j){
    if(i>e || j<b) return 0;
    if(b>=i && e<=j){
        return tree[node];
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    ll q1=query2(left,b,mid,i,j);
    ll q2=query2(right,mid+1,e,i,j);
    return q1+q2;
}
 
int main(){
    BeatMeScanf;
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++) scanf("%lld",&arr[i]);
        build(1,1,n);
        printf("Case %d:\n",++no);
        while(q--){
            int ch;
            scanf("%d",&ch);
            if(ch==1){
                int pos;
                scanf("%d",&pos);
                ++pos;
                ll ans=query1(1,1,n,pos);
                printf("%lld\n",ans);
                update2(1,1,n,pos);
            }
            else if(ch==2){
                int pos,a;
                scanf("%d %d",&pos,&a);
                ++pos;
                update(1,1,n,pos,a);
            }
            else if(ch==3){
                int i,j;
                scanf("%d %d",&i,&j);
                ++i,++j;
                ll ans=query2(1,1,n,i,j);
                printf("%lld\n",ans);
            }
        }
        for(int i=0;i<=4*sz;i++) tree[i]=0;
    }
    return 0;
}
