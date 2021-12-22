#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000500



int main(){
    int t,no=0;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        if(n==1) {
            printf("Case %d: %lld\n",++no, m);
            continue;
        }
        else if(m==1){
            printf("Case %d: %lld\n",++no, n);
            continue;
        }
        ll ans=(n*m)+1;
        ans/=2;

        if(n==2) {
            ans=(m/4)*4;
            if(m%4==1) ans+=2;
            else if(m%4>1) ans+=4;
            printf("Case %d: %lld\n",++no,ans);
        }
        else if(m==2) {
            ans=(n/4)*4;
            if(n%4==1) ans+=2;
            else if(n%4>1) ans+=4;
            printf("Case %d: %lld\n",++no,ans);
        }
        else printf("Case %d: %lld\n",++no,ans);

    }
    return 0;
}
