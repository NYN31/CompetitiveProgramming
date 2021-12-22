#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000100

int main(){
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        ll m,n;
        scanf("%lld %lld",&n,&m);
        printf("Case %d: %lld\n",++no,(n/2)*m);
    }
    return 0;
}
