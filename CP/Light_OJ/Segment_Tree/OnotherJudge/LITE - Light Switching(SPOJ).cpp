/*
SPOJ Light Swithching Problem solution done by me
*/

#include<bits/stdc++.h>
using namespace std;
#define sz 100100
int arr[sz];
struct info{
    int zero,one,prop;
}tree[4*sz];

void init(int node,int b,int e){
    if(b==e){
        tree[node].zero=1;
        tree[node].one=0;
        tree[node].prop=0;
        return ;
    }
    int left=node*2,
        right=left+1,
        mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].zero=tree[left].zero+tree[right].zero;
    tree[node].one=tree[left].one+tree[right].one;
}

void update(int node,int b,int e,int i,int j){
    if(i>e || j<b) return;
    if(b>=i && e<=j){
        swap(tree[node].zero,tree[node].one);
        tree[node].prop+=1;
        return;
    }
    int left=node*2,
        right=left+1,
        mid=(b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    tree[node].zero=tree[left].zero+tree[right].zero;
    tree[node].one=tree[left].one+tree[right].one;
    int t=tree[node].prop%2;
    if(t==1) swap(tree[node].zero,tree[node].one);
}

int query(int node,int b,int e,int i,int j,int carry){
    if(i>e || j<b) return 0;
    if(b>=i && e<=j){
        int t=carry%2,x=tree[node].zero,y=tree[node].one;
        if(t==1) swap(x,y);
        return y;
    }
    int left=node*2,
        right=left+1,
        mid=(b+e)/2;
    int q1=query(left,b,mid,i,j,carry+tree[node].prop);
    int q2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return q1+q2;
}

int main(){
    int n,q;
    while(cin>>n>>q){
        for(int i=1;i<=n;i++) arr[i]=0;
        init(1,1,n);

        while(q--){
            int ch;
            cin>>ch;
            if(ch==0){
                int i,j;
                cin>>i>>j;
                update(1,1,n,i,j);
            }
            else if(ch==1){
                int i,j;
                cin>>i>>j;
                int ans=query(1,1,n,i,j,0);
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}
