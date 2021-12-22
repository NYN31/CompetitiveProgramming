#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false)
#define ll long long
#define sz 1000005
 
#define mx 100001
int arr[mx];
int tree[mx*3];
 
void init(int node,int b,int e){
    if(b==e){
        tree[node]=arr[b];
        return;
    }
    int left=2*node;
    int right=left+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
 
int query(int node,int b,int e,int i,int j){
    if (i>e||j<b) return 1000000;
    if (b>=i&&e<=j) return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}
 
int main(){
    BeatMeScanf;
    int t,no=0;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++) cin>>arr[i];
        init(1,1,n);
        cout<<"Case "<<++no<<":"<<endl;
        while(q--){
            int a,b,mn;
            cin>>a>>b;
            mn=query(1,1,n,a,b);
            cout<<mn<<endl;
        }
    }
    return 0;
}
