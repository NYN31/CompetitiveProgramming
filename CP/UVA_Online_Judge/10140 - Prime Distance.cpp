#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 1000000
#define BeatMeScanf ios_base::sync_with_stdio(false)
vector<ll>prime, primes;
void sieve()
{
    bool isPrime[MAX];
    for(ll i=0;i<MAX;i++) isPrime[i]=true;

    for(ll i=3;i*i<=MAX;i++){
        if(isPrime[i]){
            for(ll j=i*i;j<=MAX;j+=i)
                isPrime[j]=false;
        }
    }
    prime.push_back(2);
    for(int i=3;i<MAX;i+=2) if(isPrime[i]) prime.push_back(i);
}

void SegSieve(ll l, ll r)
{
    bool isPrime[r-l+50];
    for(ll i=0;i<r-l+1;i++) isPrime[i]=true;
    if(l==1) isPrime[0]=false;
    for(ll i=0;prime[i]*prime[i]<=r;i++){
        ll currentPrime=prime[i];
        ll base =(l/currentPrime)*currentPrime;
        if(base<l) base+=currentPrime;
        for(ll j=base;j<=r;j+=currentPrime)
            isPrime[j-l]=false;
        if(base==currentPrime) isPrime[base-l]=true;
    }
    for(ll i=0;i<r-l+1;i++)
        if(isPrime[i]) primes.push_back(i+l);
}

int main()
{
    sieve();
    ll l,r;
    while(cin>>l>>r){
        ll x=0,mini=1000,maxi=0,e1=0,e2=0,f1=0,f2=0,k1,k2;

        SegSieve(l,r);
        if(primes.size()==0||primes.size()==1){
            cout<<"There are no adjacent primes."<<endl;
            primes.clear();
            continue;
        }
        else if(primes.size()==2) {
            cout<<primes[0]<<","<<primes[1]<<" are closest, "<<primes[0]<<","<<primes[1]<<" are most distant."<<endl;
            primes.clear();
            continue;
        }
        for(ll i=0;i<primes.size()-1;i++){
            x=primes[i+1]-primes[i];
            if(x<mini){
                e1=primes[i]; e2=primes[i+1];
                mini=primes[i+1]-primes[i];
            }
            if(x>maxi){
                f1=primes[i]; f2=primes[i+1];
                maxi=primes[i+1]-primes[i];
            }
        }
        cout<<e1<<","<<e2<<" are closest, "<<f1<<","<<f2<<" are most distant."<<endl;
        primes.clear();
    }
    return 0;
}
