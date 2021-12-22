/// Spoj Online judge
/// Problem name: KGSS - Maximum Sum

#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 100100

int arr[sz];
struct inf{
    int mx,pos;
}tree[4*sz];

void init(int node,int b,int e){
    if(b==e){
        tree[node].mx=arr[b];
        tree[node].pos=b;
        return ;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    if(tree[left].mx<tree[right].mx){
        tree[node].mx=tree[right].mx;
        tree[node].pos=tree[right].pos;
    }else{
        tree[node].mx=tree[left].mx;
        tree[node].pos=tree[left].pos;
    }
}

void update(int node,int b,int e,int i,int x){
    if(i>e || i<b) return ;
    if(i==e && i==b){
        tree[node].mx=x;
        tree[node].pos=i;
        return;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    update(left,b,mid,i,x);
    update(right,mid+1,e,i,x);
    if(tree[left].mx<tree[right].mx){
        tree[node].mx=tree[right].mx;
        tree[node].pos=tree[right].pos;
    }else{
        tree[node].mx=tree[left].mx;
        tree[node].pos=tree[left].pos;
    }
}
pair<int,int> query(int node,int b,int e,int i,int j){
    if(i>e || j<b){
        pair<int,int>v;
        v.first=INT_MIN;
        v.second=-1;
        return v;
    }
    if(b>=i && e<=j){
        pair<int,int>v;
        v.first=tree[node].mx;
        v.second=tree[node].pos;
        return v;
    }
    int left=2*node,
        right=left+1,
        mid=(b+e)/2;
    pair<int,int> p1,p2;
    p1=query(left,b,mid,i,j);
    p2=query(right,mid+1,e,i,j);
    if(p1.first>p2.first){
        pair<int,int>v;
        v.first=p1.first;
        v.second=p1.second;
        return v;
    }
    else{
        pair<int,int>v;
        v.first=p2.first;
        v.second=p2.second;
        return v;
    }
}

int main()
{
    //BeatMeScanf;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    init(1,1,n);
    int q;
    scanf("%d",&q);
    while(q--){
        char str[5];
        scanf("%s",str);

        if(str[0]=='U'){
            int i,x;
            scanf("%d %d",&i,&x);
            update(1,1,n,i,x);
        }
        else{
            int a,b;
            scanf("%d %d",&a,&b);
            pair<int,int> mx1=query(1,1,n,a,b);
            int x,y;
            x=mx1.first,y=mx1.second;
            update(1,1,n,y,0);
            pair<int,int> mx2=query(1,1,n,a,b);
            update(1,1,n,y,x);
            printf("%d\n",x+mx2.first);
        }
    }
}


/*
// done by Ishaan
#include<bits/stdc++.h>
using namespace std;
#define     Boost               ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define     all(cont)           cont.begin(),cont.end()
#define     rall(cont)          cont.rbegin(),cont.rend()
#define     foreach(cont)       for(auto &value: cont)
#define     show(val)           cout<< #val << " -> " << val << endl
#define     flush               cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define     Case                cout<< "Case "<< ++cs << ": "
#define     mk                  make_pair
#define     pb                  push_back
#define     ff                  first
#define     ss                  second
typedef     long long                   ll ;
typedef     unsigned long long          ull ;
typedef     pair <int, int>             pii ;
const ll INF = (1LL<<60)-1 ;
#define lim 100005
pii tree[4*lim] ;
int arr[lim] ;
void build(int node,int lo,int hi){
    if(lo == hi){
        tree[node].ff = arr[lo] ;
        tree[node].ss = 0 ;
        return  ;
    }
    int mid = lo+(hi-lo)/2 ;
    build(2*node,lo,mid) ;
    build(2*node+1,mid+1,hi) ;
    vector<int> temp = {tree[2*node].ff,tree[2*node].ss,tree[2*node+1].ff,
                  tree[2*node+1].ss} ;
    sort(rall(temp)) ;
    tree[node].ff = temp[0] ;
    tree[node].ss = temp[1] ;
}
void update(int node,int lo,int hi,int qi,int val){
    if(qi<lo || qi>hi) return ;
    if(lo == hi){
        tree[node].ff =  val ;
        tree[node].ss = 0 ;
        return ;
    }
    int mid = lo+(hi-lo)/2 ;
    update(2*node,lo,mid,qi,val) ;
    update(2*node+1,mid+1,hi,qi,val) ;
    vector<int> temp = {tree[2*node].ff,tree[2*node].ss,tree[2*node+1].ff,
                  tree[2*node+1].ss} ;
    sort(rall(temp)) ;
    tree[node].ff = temp[0] ;
    tree[node].ss = temp[1] ;
}
pii query(int node,int lo,int hi,int qi,int qj){
    if(qj<lo || qi>hi) return pii(0,0) ;
    if(qi<=lo && hi<=qj)
        return tree[node] ;
    int mid = lo+(hi-lo)/2 ;
    pii lft = query(2*node,lo,mid,qi,qj) ;
    pii rgt = query(2*node+1,mid+1,hi,qi,qj) ;
    vector<int> temp = {lft.ff,lft.ss,rgt.ff,rgt.ss} ;
    sort(rall(temp)) ;
    return pii(temp[0],temp[1]) ;
}
//#define DEBUG
int main()
{
    //Boost;
    #ifdef DEBUG
    freopen("input.txt","r",stdin);    // Read
    freopen("output.txt","w",stdout);  // Write
    #endif
    int n,q ;
    cin>> n ;
    for(int i=1; i<=n; i++)
        cin>> arr[i] ;
    build(1,1,n) ;
    cin>> q ;
    while(q--){
        int a,b ;
        string chk ;
        cin>> chk >> a >> b ;
        if(chk == "U")
            update(1,1,n,a,b) ;
        else if(chk == "Q"){
            pii ans = query(1,1,n,a,b) ;
            cout<< (ans.ff+ans.ss) << endl ;
        }
    }
    return 0;
}
*/
