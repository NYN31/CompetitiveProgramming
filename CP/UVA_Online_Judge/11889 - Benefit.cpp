#include<bits/stdc++.h>
using namespace std;
#define ll long long
bitset<10000010>isPrime;
vector<ll>primes;
void sieve(ll max){
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
ll power(ll a, ll n)
{
    if(n==0) return 1;
    else return a*power(a,n-1);
}
void solve(ll A, ll C)
{
    ll cnt1,cnt2,ans=1;
    for(ll i=0;i<550&&primes[i]<=A&&primes[i]<=C;i++){
        cnt1=0,cnt2=0;
        while(A%primes[i]==0){
            cnt1++;
            A=A/primes[i];
        }
        while(C%primes[i]==0){
            cnt2++;
            C=C/primes[i];
        }
       if(cnt1<cnt2) ans*=(power(primes[i],cnt2));

    }
    if(A==1 && C>1) ans=ans*C;
    cout<<ans<<endl;
}
int main()
{
    sieve(10000000);
    int t;
    cin>>t;
   while(t--){
       ll A,C;
       cin>>A>>C;
        if(C%A!=0) cout<<"NO SOLUTION"<<endl;
        else solve(A,C);
    }
    return 0;
}
