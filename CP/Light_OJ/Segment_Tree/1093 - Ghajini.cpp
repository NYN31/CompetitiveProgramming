#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100100
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int arr[sz],tree1[sz*3],tree2[sz*3];

void init1(int node, int st, int ed){
    if(st==ed){
        tree1[node]=arr[st];
        return;
    }
    int mid,left,right;
    left=2*node;
    right=left+1;
    mid=(st+ed)/2;
    init1(left,st,mid);
    init1(right,mid+1,ed);
    tree1[node]=max(tree1[left],tree1[right]);
}
void init2(int node, int st, int ed){
    if(st==ed){
        tree2[node]=arr[st];
        return;
    }
    int mid,left,right;
    left=2*node;
    right=left+1;
    mid=(st+ed)/2;
    init2(left,st,mid);
    init2(right,mid+1,ed);
    tree2[node]=min(tree2[left],tree2[right]);
}

int query1(int node,int st,int ed,int i,int j){
    if(i>ed || j<st) return -1000000000;
    if(st>=i && ed<=j) return tree1[node];
    int right, left, mid;
    left=node*2;
    right=left+1;
    mid=(st+ed)/2;
    int p1=query1(left,st,mid,i,j);
    int p2=query1(right,mid+1,ed,i,j);
    return max(p1,p2);
}

int query2(int node,int st,int ed,int i,int j){
    if(i>ed || j<st) return 1000000000;
    if(st>=i && ed<=j) return tree2[node];
    int right, left, mid;
    left=node*2;
    right=left+1;
    mid=(st+ed)/2;
    int p1=query2(left,st,mid,i,j);
    int p2=query2(right,mid+1,ed,i,j);
    return min(p1,p2);
}

int main(){
    BeatMeScanf;
    int t,no=0;
    cin>>t;
    while(t--){
        int n,d,mx=-100;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>arr[i];
        init1(1,1,n);
        init2(1,1,n);
        for(int i=1;i<=n;i++){
            if(i+d-1>n) break;
            int x1=query1(1,1,n,i,i+d-1);
            int x2=query2(1,1,n,i,i+d-1);
            mx=max(mx,abs(x1-x2));
        }
        cout<<"Case "<<++no<<": "<<mx<<endl;
    }
    return 0;
}


struct ST
{
    int tmx[4 * N], tmn[4 * N];
    ST(){}
    void build(int n, int b, int e)
    {
        if(b == e){
            tmx[n] = tmn[n] = a[b];
            return;
        }
        int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        tmx[n] = max(tmx[l], tmx[r]);
        tmn[n] = min(tmn[l], tmn[r]);
    }
    void upd(int n, int b, int e, int i, int x)
    {
        if(b > i || e < i) return;
        if(b == e && b == i){
            tmx[n] = tmn[n] = x;
            return;
        }
        int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
        upd(l, b, mid, i, x);
        upd(r, mid + 1, e, i, x);
		tmx[n] = max(tmx[l], tmx[r]);
        tmn[n] = min(tmn[l], tmn[r]);    
    }
    pair<int, int> query(int n, int b, int e, int i, int j)
    {
        if(b > j || e < i) return {1e9, 0};
        if(b >= i && e <= j) return {tmn[n], tmx[n]};
        int mid = (b + e) >> 1,  l = n << 1,  r = l | 1;
        pair<int, int> L = query(l, b, mid, i, j);
        pair<int, int> R = query(r, mid + 1, e, i, j);
        return {min(L.first, R.first), max(L.second, R.second)};
    }
}t;
