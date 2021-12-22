#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define max 1000010
bool isPrime[max];
vector<ll>primes;

void sieve(){
    isPrime[0]=isPrime[1]=false;
    for(ll i=2;i<=max; i++) isPrime[i]=true;
    primes.push_back(2);
    for(ll i=3;i<=max;i+=2){
        if(isPrime[i]){
            for(ll j=i+i; j<=max;j+=i)
                isPrime[j]=false;
            primes.push_back(i);
        }
    }
}
ll f(ll n,ll x)
{
    ll cnt=0,pp=x;
    while(pp<=n){
        cnt++;
        pp*=x;
    }
    return cnt;
}
ll power(ll a, ll n)
{
    if(n==0) return 1;
    else return a*power(a,n-1);
}
int main()
{
    sieve();
    ll n;
    while(cin>>n&&n!=0){
        ll ans=1,cnt2=0,cnt5=0,max_cnt2;
        cnt2=f(n,2);
        cnt5=f(n,5);
        max_cnt2-=cnt2-cnt5;
        for(ll i=0;i<primes.size() && primes[i]<=n;i++){
            if(primes[i]==5) continue;
            ll pp=primes[i],cnt=0,pp2=primes[i];
            while(pp<=n && pp!=2){
                pp*=primes[i];
                if(pp<=n) pp2=pp;
            }
            if(primes[i]==2) pp2=power(2,max_cnt2);
            ans=(ans*pp2)%10;

        }
        cout<<ans<<endl;
    }
    return 0;
}
