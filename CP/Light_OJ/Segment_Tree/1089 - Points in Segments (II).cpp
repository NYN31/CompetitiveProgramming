//Using line swapping technique

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        ll n,q;
        scanf("%lld %lld", &n,&q);
        map<ll,ll>mp,ans;
        map<ll,ll>::iterator it;
        ll pos[q+10];
        vector<pair<ll,ll>>vec;
        while(n--){
            ll a,b;
            scanf("%lld %lld", &a,&b);
            mp[a]++;
            mp[b+1]--;
        }
        for(int i=0;i<q;i++){
            ll a;
            scanf("%lld", &a);
            pos[i]=a;
            if(mp.count(a)!=0) continue;
            mp[a]=0;
        }

        for(it=mp.begin();it!=mp.end();it++) vec.push_back({it->first,it->second});
        for(int i=1;i<vec.size();i++) vec[i].second+=vec[i-1].second;
        for(int i=0;i<vec.size();i++) ans[vec[i].first]=vec[i].second;
        printf("Case %d:\n",++no);
        for(int i=0;i<q;i++) printf("%lld\n",ans[pos[i]]);
    }
    return 0;
}


// Using segment tree

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 150010
struct info{
    ll prop;
}tree[4*sz];
vector<pair<ll,ll>>vec;
vector<ll>pos;

void update(ll node,ll b,ll e,ll i,ll j){
    if(i>e || j<b) return ;
    if(b>=i && e<=j){
        tree[node].prop+=1;
        return ;
    }
    ll left=node*2,
        right=left+1,
        mid=(b+e)/2;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
}
ll query(ll node,ll b,ll e,ll x,ll carry){
    if(x>e || x<b) return 0LL;
    if(b==x && e==x) return carry+tree[node].prop;
    ll left=node*2,
        right=left+1,
        mid=(b+e)/2;
    ll p1=query(left,b,mid,x,carry+tree[node].prop);
    ll p2=query(right,mid+1,e,x,carry+tree[node].prop);
    return p1+p2;
}

int main(){
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        ll n,q,c=0;
        scanf("%lld %lld",&n,&q);
        map<ll,ll>mp;
        vec.clear();
        pos.clear();
        for(int i=1;i<=n;i++){
            ll a,b;
            scanf("%lld %lld",&a,&b);
            vec.push_back({a,b});
            if(mp.count(a)==0) mp[a]++;
            if(mp.count(b)==0) mp[b]++;
        }
        for(int i=1;i<=q;i++){
            ll a;
            scanf("%lld",&a);
            pos.push_back(a);
            if(mp.count(a)==0) mp[a]++;
        }
        for(auto it:mp){
            c++;
            mp[it.first]=c;
        }
        for(ll i=0;i<=4*c;i++) tree[i].prop=0;
        for(ll i=0;i<vec.size();i++)
            update(1,1,c,mp[vec[i].first],mp[vec[i].second]);
        printf("Case %d:\n",++no);
        for(ll i=0;i<pos.size();i++){
            ll ans;
            ans=query(1,1,c,mp[pos[i]],0);
            printf("%lld\n",ans);
        }
    }
    return 0;
}

/*
1
5 5
6 12
8 8
10 12
8 11
0 12
11
12
7
2
20
*/

