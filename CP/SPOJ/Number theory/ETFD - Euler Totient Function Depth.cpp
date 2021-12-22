#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ull unsigned long long
#define sz 1000010
 
bool isprime[sz+10];
ll phi[sz+10];
ll dp[sz+10];
vector<ll>deg[25];
 
void phi_sieve()
{
    for(ll i=0;i<=sz;i++) phi[i]=i;
    for(ll p=2;p<=sz;p++){
        if(!isprime[p]){
            phi[p]=p-1;
            for(ll i=2*p;i<=sz;i+=p){
                phi[i]=(phi[i]/p)*(p-1);
                isprime[i]=true;
            }
        }
    }
    dp[1]=0;
    deg[0].push_back(1);
    for(int i=2;i<=sz;i++){
        dp[i]=dp[phi[i]]+1;
        deg[dp[phi[i]]+1].push_back(i);
    }
}
 
 
int main(){
    phi_sieve();
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        ll l,r,lev;
        cin>>l>>r>>lev;
        int pos = upper_bound(deg[lev].begin(),deg[lev].end(),r)-lower_bound(deg[lev].begin(),deg[lev].end(),l);
        cout<<pos<<endl;
    }
    return 0;
}
