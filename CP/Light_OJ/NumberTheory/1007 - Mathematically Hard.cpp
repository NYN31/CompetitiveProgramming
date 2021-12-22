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
        phi[i]=phi[i]*phi[i];
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

