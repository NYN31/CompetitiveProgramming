#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100100
 
int tree[4*sz];
 
void update(int node,int b,int e,int i,int j){
    if(i>e || j<b) return ;
    if(b>=i && e<=j) {
        tree[node]+=1;
        return ;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
}
int query(int node,int b,int e,int q,int carry){
    if(q>e || q<b) return 0;
    if(b==e) return carry+tree[node];
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    int p1=query(left,b,mid,q,carry+tree[node]);
    int p2=query(right,mid+1,e,q,carry+tree[node]);
    return p1+p2;
}
 
int main(){
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        memset(tree,0,sizeof tree);
        string s;
        cin>>s;
        s=' '+s;
        int q,n;
        scanf("%d",&q);
        printf("Case %d:\n",++no);
        n=s.size();
        while(q--){
            char ch;
            scanf(" %c",&ch);
            if(ch=='I'){
                int i,j;
                scanf(" %d %d",&i,&j);
                update(1,1,n,i,j);
            }
            else if(ch=='Q'){
                int pos;
                scanf(" %d",&pos);
                char ch1=s[pos];
                int ans=query(1,1,n,pos,0);
                if(ans%2==0) printf("%c\n",ch1);
                else {
                    if(ch1=='1') printf("0\n");
                    else printf("1\n");
                }
            }
            //for(int i=1;i<=2*n;i++) cout<<tree[i]<<" ";cout<<endl;
        }
    }
    return 0;
}
