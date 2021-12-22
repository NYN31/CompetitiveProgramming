#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 50000
bool isPrime[MAX+3];
ll arr[MAX+3];
vector<ll>primes;
void sieve()
{
    isPrime[0]=isPrime[1]=false;
    for(ll i=2;i<=MAX;i++) isPrime[i]=true;
    for(ll i=2;i<=MAX;i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(ll j=i*i;j<=MAX;j+=i)
                isPrime[j]=false;

        }
    }
}
int solve(ll n, ll m)
{
    for(int i=0;i<primes.size()&&primes[i]*primes[i]<=m;i++){
        if(m%primes[i]==0){
            ll cnt=0;
            while(m%primes[i]==0)
                cnt++, m/=primes[i];
            ll temp=primes[i], cnt2=0;
            while(temp<=n){
                cnt2+=(n/temp);
                temp*=primes[i];
            }
            if(cnt2<cnt) return 0;
        }
    }
    if(m!=1) if(n<m) return 0;
    return 1;
}
int main()
{
    sieve();
    ll n,m;
    while(cin>>n>>m){
        if(solve(n, m))
            printf("%lld divides %lld!\n", m, n);
        else
            printf("%lld does not divide %lld!\n", m, n);
    }
    return 0;
}
