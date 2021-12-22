/*
Problem name: KQUERY - K-query
Judge: SPOJ
Using Merge sort tree..
Finding the number of elements greater then K in a given range
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 30010

#define segTree int left=node*2,right=left+1,mid=(b+e)/2
int arr[sz],n,q;
vector<int>tree[4*sz];

void build(int node,int b,int e){
    if(b==e){
        tree[node].push_back(arr[b]);
        return ;
    }
    segTree;
    build(left,b,mid);
    build(right,mid+1,e);
    merge(tree[left].begin(),tree[left].end(),
          tree[right].begin(),tree[right].end(),
          back_inserter(tree[node]));
}

int query(int node,int b,int e,int i,int j,int k){
    if(i>e || j<b) return 0;
    if(b>=i && e<=j){
        int ans=0;
        ans=tree[node].size() - (upper_bound(tree[node].begin(),tree[node].end(),k)-tree[node].begin());
        return ans;
    }
    segTree;
    int q1,q2;
    q1=query(left,b,mid,i,j,k);
    q2=query(right,mid+1,e,i,j,k);
    return q1+q2;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    cin>>q;
    while(q--){
        int i,j,k;
        cin>>i>>j>>k;
        int ans=query(1,1,n,i,j,k);
        cout<<ans<<endl;
    }
    return 0;
}
