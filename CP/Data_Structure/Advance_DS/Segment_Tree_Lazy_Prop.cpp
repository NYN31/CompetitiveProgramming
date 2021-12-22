#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 100100

int arr[sz];
struct inf{
    ll prop,sum;
}tree[3*sz];

void init(int node,int b,int e){
    if(b==e){
        tree[node].sum=arr[b];
        return;
    }
    int left,right,mid;
    left=node<<1;
    right=left+1;
    mid=(b+e)>>1;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(int node,int b,int e,int i,int j,int newvalue){
    if(i>e || j<b) return;
    if(b>=i && e<=j){
        tree[node].prop+=newvalue;
        tree[node].sum+=(e-b+1)*newvalue;
        return ;
    }
    int left,right,mid;
    left=node<<1;
    right=left+1;
    mid=(b+e)>>1;
    update(left,b,mid,i,j,newvalue);
    update(right,mid+1,e,i,j,newvalue);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
int query(int node,int b,int e,int i,int j,int carry=0){
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) return tree[node].sum+carry*(e-b+1);
    int left,right,mid;
    left=node<<1;
    right=left+1;
    mid=(b+e)>>1;
    int p1=query(left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}

int main(){
    BeatMeScanf;
    int n;
    while(cin>>n){
        for(int i=1;i<=n;i++) cin>>arr[i];
        init(1,1,n);
        update(1,1,n,2,5,2);
        cout<<query(1,1,n,2,5)<<endl;
        update(1,1,n,1,4,2);
        update(1,1,n,2,5,4);
        cout<<query(1,1,n,1,5)<<endl;
        cout<<query(1,1,n,2,4)<<endl;
    }
    return 0;
}

