/**
    Range minimum number query:

    Given an array of size n and also q query.
    You have to Find the minimum number
    between the range a and b
    And update/add given number between the
    range a and b
**/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 100100

int n,q,arr[sz];
struct info{
    int prop,mn;
}tree[4*sz];

void build(int node,int b,int e){
    if(b==e){
        tree[node].mn=arr[b];
        tree[node].prop=0;
        return ;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node].mn=min(tree[left].mn,tree[right].mn);
    tree[node].prop=0;
}

void update(int node,int b,int e,int i,int j,int nv){
    if(i>e || j<b) return ;
    if(b>=i && e<=j){
        tree[node].prop+=nv;
        tree[node].mn+=nv;
        return ;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    update(left,b,mid,i,j,nv);
    update(right,mid+1,e,i,j,nv);
    tree[node].mn=tree[node].prop+min(tree[left].mn,tree[right].mn);
}

int query(int node,int b,int e,int i,int j,int carry){
    if(i>e || j<b) return INT_MAX;
    if(b>=i && e<=j) return carry+tree[node].mn;
    int left=2*node,
        right=left+1,
        mid=(b+e)/2,q1,q2;
    q1=query(left,b,mid,i,j,carry+tree[node].prop);
    q2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    if(q1<q2) return q1;
    else return q2;
}

int main(){
    BeatMeScanf;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    for(int i=1;i<=2*n;i++) cout<<tree[i].mn<<" ";cout<<endl;
    while(q--){
        int a,b,ch,nv;
        cin>>ch;
        if(ch==1){
            cin>>a>>b>>nv;
            update(1,1,n,a,b,nv);
            for(int i=1;i<=2*n;i++) cout<<tree[i].mn<<" ";cout<<endl;
        }
        else if(ch==2){
            cin>>a>>b;
            ll ans=query(1,1,n,a,b,0);
            cout<<ans<<endl;
        }
    }

    return 0;
}

