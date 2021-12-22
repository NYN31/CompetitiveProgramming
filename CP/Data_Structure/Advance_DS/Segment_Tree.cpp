#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false)
#define ll long long
#define nl "\n"
#define PI 3.14159265358979323846
#define sz 1000005
#define mod 1000000007
#define toint(a) atoll(a.c_str())
string tostr(int n) {stringstream rr;rr<<n;return rr.str();}
ll binpow(ll n, ll p) {if(p==0) return 1LL;if(p%2==0){ll res=binpow(n,p/2);return res*res;}return n*binpow(n,p-1);}
ll gcd(ll a,ll b) {return b==0? a:gcd(b,a%b);}
ll lcm(ll a,ll b) {return a*(b/gcd(a,b));}
///st.max_load_factor(0.25); st.reserve(512);

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
    tree[node]=tree[left]+tree[right];
}

void update(int node,int b,int e,int i,int newvalue){
    if (i>e||i<b)return;
    if (b>=i&&e<=i){
        tree[node] = newvalue;
        return;
    }
    int left=2*node;
    int right=left+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,newvalue);
    update(right,mid+1,e,i,newvalue);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j){
    if (i>e||j<b) return 0;
    if (b>=i&&e<=j) return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

int main(){
    BeatMeScanf;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    init(1,1,n);

    update(1,1,n,2,0);
    cout<<query(1,1,n,1,3)<<nl;
    update(1,1,n,5,9);
    cout<<query(1,1,n,3,8)<<nl;
    return 0;
}
/*
11
4 9 3 7 1 0 2 5 3 2 4
*/
