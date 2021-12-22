#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ull unsigned long long
#define sz 1000010
 
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
}
 
 
int main(){
    phi_sieve();
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        printf("%lld\n",phi[n]);
    }
    return 0;
}
