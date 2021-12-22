#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 500

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
    for(int i=2;i<sz-300;i++) if(isprime[i]) primes.push_back((ll)i);
}

vector<pair<ll,ll>> fact(ll n){
    vector<pair<ll,ll>>ans;
    ll x;
    for(int i=0;i<primes.size() && primes[i]<=n;i++){
        ll p=primes[i];
        ll cnt=0,temp=p;
        x=n;
        while(temp<=x){
            cnt+=x/temp;
            temp*=p;
        }
        ans.push_back({p,cnt});
    }
    return ans;
}

int main()
{
    sieve();
    ll t,no=0;
    scanf("%lld",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        vector<pair<ll,ll>>ans = fact(n);
        printf("Case %d: ", ++no);
        cout<<n<<" = ";
        for(int i=0;i<ans.size();i++) {
            printf("%lld (%lld)",ans[i].first,ans[i].second);
            if(i != ans.size()-1) printf(" * ");
        }
        cout<<endl;
    }
    return 0;
}

