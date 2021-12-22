/**
    Problem Tags: Number Theory
    Explanation: Let, k be the number of consecutive integers starting
                from x whose sum equals N.So we can write,
                x+(x+1)+........+(x+k-1)=N --------(1)
                or, kx+k*(k-1)/2=N
                or, 2kx+k^2-k=2N
                or, k(2x+k-1)=2N ----------(2)
                From equation (2) we can say, k is a divisor of 2N.
                Now, from (2)
                k(2x+k-1)=2N
                or, 2x+k-1=2N/k
                or, 2x+k-1=R  [Let R=2N/k]
                or, 2x=(R-k)+1 ------------(3)
                From, equation (3) we can say, (R-k) has to be odd number.
                Again, since R=2N/k and 2N is even, so R is always even and hence
                k must be odd to be (R-k) odd.
 
                From the requirement of problem, x must be positive integers,
                so from equation (3) we can write,
                R>=k
                or, 2N/k>=k
                or, 2N>=k^2
                or, k<=sqrt(2N) ------------(4)
 
                From the above explanation, we can say,
                1) k must be a divisor of 2N
                2) k must be odd
                3) k is less than or equals to the sqaure-root of 2N.
**/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll sz = 10000010;

bool isprime[sz+10];
vector<int>primes;

void sieve(){
    for(int i=2;i<=sz;i++) isprime[i]=true;
    for(int i=4;i<=sz;i+=2) isprime[i]=false;
    isprime[0]=isprime[1]=false;
    for(int i=3;i*i<=sz;i++){
        if(isprime[i]){
            for(int j=i*i;j<=sz;j+=i)
                isprime[j]=false;
        }
    }
    for(int i=2;i<=sz;i++) if(isprime[i]) primes.push_back(i);
}

ll solve(ll n){
    while(n%2==0) n/=2;
    ll ans=1;
    for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++){
        ll p=primes[i];
        if(n%p != 0) continue;
        ll cnt=0;
        while(n%p == 0){
            n/=p;
            cnt++;
        }
        ans*=(cnt+1);
    }
    if(n>1) ans*=2;
    return ans;
}

int main(){
    sieve();
    int t,no=0;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=solve(n)-1;
        printf("Case %d: %lld\n",++no,ans);
    }
    return 0;
}
