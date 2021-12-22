#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>primes;
bool isPrime[1000005];

void sieve(ll max){
    isPrime[0]=isPrime[1]=false;
    for(ll i=2;i<=max; i++) isPrime[i]=true;
    for(ll i=4;i<=max;i+=2) isPrime[i]=false;
    primes.push_back(2);
    for(ll i=3;i*i<=max;i++){
        if(isPrime[i]){
            for(ll j=i*i; j<=max;j+=i)
                isPrime[j]=false;
            primes.push_back(i);
        }
    }
}

int main()
{
    sieve(1000000);
    ll n;
    while(cin>>n && n!=0)
    {
        vector<int>vec;
        for(ll i=0;i<primes.size()&&primes[i]<=n;i++)
        {
            ll pp=primes[i],cnt=0;
            while(pp<=n){
                cnt+=(n/pp);
                pp=pp*primes[i];
            }

            if(cnt>0) vec.push_back(cnt);
        }
        cout.width(3);
        cout<<n<<"! =";
        ll x=0,y=0;
        for(ll i=0;i<vec.size();i++){
            cout.width(3);
            x+=3;
            if(x<=45||y==1) cout<<vec[i];
            else cout<<endl<<"        "<<vec[i],y=1;

        }
        cout<<endl;
        vec.clear();
    }
    return 0;
}
