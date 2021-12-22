#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000500

bool isprime[sz];
vector<int>primes;
void sieve(){
    for(int i=2;i<sz;i++) isprime[i]=true;
    isprime[0]=isprime[1]=false;
    for(int i=4;i<sz;i+=2) isprime[i]=false;
    for(int i=3;i*i<=sz;i++){
        if(isprime[i])
            for(int j=i*i;j<sz;j+=i)
                isprime[j]=false;
    }
    for(int i=2;i<sz;i++) if(isprime[i]) primes.push_back(i);
}

ll bmod(ll a,ll p){
    if(p==0) return 1;
    if(p%2==0){
        ll ret=bmod(a,p/2);
        return ret*ret;
    }else{
        ll ret=bmod(a,p-1);
        return a*ret;
    }
}

ll factor(ll a,ll b,ll l){
    ll ans=1;
    for(int i=0;i<primes.size()&&primes[i]*primes[i]<=l;i++){
        ll p=primes[i],cntl=0,cnta=0,cntb=0;
        if(l%p==0){
            while(l%p==0){
                cntl++;
                l/=p;
            }
        }
        if(a%p==0){
            while(a%p==0){
                cnta++;
                a/=p;
            }
        }
        if(b%p==0){
            while(b%p==0){
                cntb++;
                b/=p;
            }
        }
        if(cntl<cnta || cntl<cntb) return -1;
        ll mx = max(cntb,cnta);
        if(cntl>mx) ans=ans*bmod(p,cntl);

    }
    if(l>1 && (a==1 && b==1)) ans*=l;
    else if(l>1 && a>1 && l!=a) ans=-1;
    else if(l>1 && b>1 && l!=b) ans=-1;
    else if(l<a || l<b) ans=-1;
    return ans;
}

int main(){
    sieve();
    int t,no=0;
    cin>>t;
    while(t--){
        ll a,b,l;
        cin>>a>>b>>l;
        ll ans=factor(a,b,l);
        if(ans==-1) {
            printf("Case %d: impossible\n",++no);
            continue;
        }
        printf("Case %d: %lld\n",++no,ans);
    }
    return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000500

bool isprime[sz];
vector<int>primes;
void sieve(){
    for(int i=2;i<sz;i++) isprime[i]=true;
    isprime[0]=isprime[1]=false;
    for(int i=4;i<sz;i+=2) isprime[i]=false;
    for(int i=3;i*i<=sz;i++){
        if(isprime[i])
            for(int j=i*i;j<sz;j+=i)
                isprime[j]=false;
    }
    for(int i=2;i<sz;i++) if(isprime[i]) primes.push_back(i);
}

ll bmod(ll a,ll p){
    if(p==0) return 1;
    if(p%2==0){
        ll ret=bmod(a,p/2);
        return ret*ret;
    }else{
        ll ret=bmod(a,p-1);
        return a*ret;
    }
}

ll factor(ll l,ll lcm){
    ll ans=1;
    for(int i=0;i<primes.size()&&primes[i]<=l&&primes[i]<=lcm;i++){
        ll p=primes[i],cnt1=0,cnt2=0;

        while(l%p==0){
            cnt1++;
            l/=p;
        }
        while(lcm%p==0){
            cnt2++;
            lcm/=p;
        }
        if(cnt1==cnt2) continue;
        ll mx=max(cnt1,cnt2);
        ans=ans*bmod(p,mx);
    }
    if(l>1 && lcm==1) ans*=l;
    return ans;
}

int main(){
    sieve();
    int t,no=0;
    cin>>t;
    while(t--){
        ll a,b,l;
        cin>>a>>b>>l;
        ll lcm=(a*b)/__gcd(a,b);
        if(l%lcm != 0) {
            printf("Case %d: impossible\n",++no);
            continue;
        }
        ll ans=factor(l,lcm);
        printf("Case %d: %lld\n",++no,ans);
    }
    return 0;
}

*/
