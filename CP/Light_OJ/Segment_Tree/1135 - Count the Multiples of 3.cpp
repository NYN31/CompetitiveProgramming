#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100100

int arr[sz];
struct info{
    ll prop,zero,one,two;
}tree[4*sz];

void init(int node,int b,int e){
    if(b==e){
        tree[node].zero=1;
        tree[node].one=0;
        tree[node].two=0;
        tree[node].prop=0;
        return;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].zero=tree[left].zero+tree[right].zero;
    tree[node].one=0;
    tree[node].two=0;
    tree[node].prop=0;
}
void update(int node,int b,int e,int i,int j){
    if(i>e || j<b) return ;
    if(b>=i && e<=j){
        int temp;
        temp=tree[node].zero;
        tree[node].zero=tree[node].one;
        tree[node].one=tree[node].two;
        tree[node].two=temp;
        tree[node].prop+=1;
        return ;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2,t,temp;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    tree[node].zero=tree[left].zero+tree[right].zero;
    tree[node].one=tree[left].one+tree[right].one;
    tree[node].two=tree[left].two+tree[right].two;
    t=tree[node].prop%3;
    for(int a=0;a<t;a++){
        temp=tree[node].zero;
        tree[node].zero=tree[node].one;
        tree[node].one=tree[node].two;
        tree[node].two=temp;
    }
}
int query(int node,int b,int e,int i,int j,int carry){
    if(i>e || j<b) return 0;
    if(b>=i && e<=j){
        int t=carry%3,temp,x,y,z;
        x=tree[node].zero;
        y=tree[node].one;
        z=tree[node].two;
        for(int a=0;a<t;a++){
            temp=x;
            x=y;
            y=z;
            z=temp;
        }
        return x;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    int q1=query(left,b,mid,i,j,carry+tree[node].prop);
    int q2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return q1+q2;
}

int main(){
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++) arr[i]=0;
        init(1,1,n);
        printf("Case %d:\n",++no);
        while(q--){
            int ch,ans,i,j;
            scanf("%d",&ch);
            if(ch==0){
                scanf("%d %d",&i,&j);
                ++i,++j;
                update(1,1,n,i,j);
            }
            else {
                scanf("%d %d",&i,&j);
                ++i,++j;
                ans=query(1,1,n,i,j,0);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

