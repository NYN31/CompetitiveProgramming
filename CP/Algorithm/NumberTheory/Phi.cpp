/*
Problem 1: given a number n, find total number from 1 to n such that gcd(i, n) = 1;
          complexity : O( sqrt(n) );
problem 2: Using sieve & factorization 
          complexity : O(nlogn)+O(logn)
problem 3: given two number a and b
           you have to find Euler’s Totient function for all numbers smaller than or equal to n
           complexity : O(nlogn)

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll phi(int n)
{
    ll result = n;
    for (ll p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
int main()
{
    ll n;
    while(cin>>n&&n!=0){
        cout<<phi(n)<<endl;
    }
    return 0;
}





///Using Sieve

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 1000010

bool isprime[sz+10];
vector<ll>primes;
void sieve()
{
    for(int i=2;i<=sz;i++) isprime[i]=true;
    isprime[0]=isprime[1]=false;
    for(int i=4;i<=sz;i+=2) isprime[i]=false;
    for(int i=3;i*i<=sz;i++){
        if(isprime[i]){
            for(int j=i*i;j<=sz;j+=i) isprime[j]=false;
        }
    }
    for (int i=2;i<=sz;++i) if(isprime[i]) primes.push_back((ll)i);
}

ll solve(ll n){
    ll res = n;
    for(int i=0;i<primes.size() && primes[i]*primes[i]<=n;i++){
        ll p=primes[i];
        if(n%p!=0) continue;
        while(n%p==0) n=n/p;
        res-=res/p;

       // res-=res/p can be written as:
          //  res/=p;
          //  res*=(p-1)

    }
    if(n>1) res-=res/n;
    return res;
}

int main(){
    sieve();
    ll t,no=0;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int ans = (int)solve(n);
        cout<<"Case "<<++no<<": "<<ans<<endl;
        printf("Case %d: %d\n", ++no, ans);
    }
    return 0;
}



/*
    given two number a and b
    you have to find Euler’s Totient function for all numbers smaller than or equal to n
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ull unsigned long long
#define sz 5000010

bool isprime[sz+10];
ull phi[sz+10];

void phi_sieve()
{
    for(ll i=0;i<=sz;i++) phi[i]=(ull)i;
    for(ll p=2;p<=sz;p++){
        if(!isprime[p]){
            phi[p]=p-1;
            for(ll i=2*p;i<=sz;i+=p){
                phi[i]=(phi[i]/p)*(p-1);
                isprime[i]=true;
            }
        }
    }
    for(int i=1;i<=sz;i++){
        phi[i]=phi[i-1]+phi[i];
    }
}


int main(){
    phi_sieve();
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        ll a,b;
        scanf("%lld %lld",&a,&b);
        ull ans = phi[b]-phi[a-1];
        printf("Case %d: %llu\n", ++no,ans);
    }
    return 0;
}
