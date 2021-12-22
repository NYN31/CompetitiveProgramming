#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define sz 1000200
#define mod 1000000007

bool isprime[sz];
vector<ll>primes;

void sieve(){
    for(int i=2;i<sz;i++) isprime[i]=true;
    isprime[0]=isprime[1]=false;
    for(int i=4;i<sz;i+=2) isprime[i]=false;
    for(int i=3;i*i<sz;i+=2){
        if(isprime[i]){
            for(int j=i*i;j<sz;j+=i)
                isprime[j]=false;
        }
    }
    for(int i=2;i<sz;i++) if(isprime[i]) primes.push_back((ll)i);
}
ll bmod(ll a,ll b){

    if(b==0) return 1;
    if(b%2==0) {
        ll even=bmod(a,b/2)%mod;
        return ((even%mod)*(even%mod))%mod;
    }
    else{
        ll odd=bmod(a,b-1)%mod;
        return ((a%mod)*(odd%mod))%mod;
    }
}
ll sod(ll n,ll b){
    ll ans=1;
    for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++){
        ll p=primes[i];
        if(n%p != 0) continue;
        ll power=0;
        while(n%p==0){
            power++;
            n/=p;
        }
        ll x,y,temp;
        x = bmod(p,(power*b)+1)-1;
        y = bmod(p-1,mod-2);
        temp = ((x)%mod*(y)%mod)%mod;
        ans = (ans*temp)%mod;
    }
    if(n>1) {
         ll x,y,temp;
         x = bmod(n,b+1)-1;
         y = bmod(n-1,mod-2);
         temp = ((x+mod)%mod*(y+mod)%mod)%mod;
         ans = (ans*temp)%mod;
    }
    return ans;
}
int main(){
    sieve();
    int t,no=0;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll ans=sod(a,b);
        printf("Case %d: %lld\n",++no,ans);
    }
    return 0;
}
