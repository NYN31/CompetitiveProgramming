/***
  Problem name: Easy Prime!
  Link: https://toph.co/p/easy-prime?fbclid=IwAR1uefatzt8-CKh0N7FS-1oCghHoZmDyj6wOTFBASqpi5mxHdMlk5s1jdRc
***/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 100100
#define MAX 10000100
#define segment int left=2*node,right=left+1,mid=(b+e)/2
bool isPrime[MAX];
vector<int>primes;
int n,tree[4*sz],arr[sz];
void sieve()
{
    isPrime[0]=isPrime[1]=false;
    for(ll i=2;i<=MAX;i++) isPrime[i]=true;
    for(ll i=2;i<=MAX;i++){
        if(isPrime[i]){
            for(ll j=i*i;j<=MAX;j+=i)
                isPrime[j]=false;
        }
    }
}
void build(int node,int b,int e){
    if(b==e){
        if(isPrime[arr[b]]) tree[node]=1;
        else tree[node]=0;
        return ;
    }
    segment;
    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
void update(int node,int b,int e,int pos,int nv){
    if(pos>e || pos<b) return ;
    if(pos==b && pos==e){
        if(isPrime[nv]) tree[node]=1;
        else tree[node]=0;
        return ;
    }
    segment;
    update(left,b,mid,pos,nv);
    update(right,mid+1,e,pos,nv);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int b,int e,int i,int j){
    if(i>e || j<b) return 0;
    if(b>=i && e<=j) return tree[node];
    segment;
    int p,q;
    p=query(left,b,mid,i,j);
    q=query(right,mid+1,e,i,j);
    return p+q;
}
int main(){
    sieve();
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    build(1,1,n);
    int q;
    cin>>q;
    while(q--){
        int ch;
        cin>>ch;
        if(ch==1){
            //query
            int a,b;
            cin>>a>>b;
            int ans=query(1,1,n,a,b);
            cout<<ans<<endl;
        }
        else{
            //update
            int pos,val;
            cin>>pos>>val;
            update(1,1,n,pos,val);
        }
    }
    return 0;
}
