#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000500

pair<ll,ll> solve1(ll n){
    ll two=0,five=0,temp=2;
    pair<ll,ll>p;
    /// Using legendre's Formula
    while(temp<=n){
        two+=n/temp;
        temp*=2;
    }
    temp=5;
    /// Using legendre's Formula
    while(temp<=n){
        five+=n/temp;
        temp*=5;
    }
    p={two,five};
    return p;
}
pair<ll,ll> solve2(ll n,ll q){
    ll temp=n,two=0,five=0;
    pair<ll,ll>p;
    while(temp%2==0){
        two++;
        temp/=2;
    }
    temp=n;
    while(temp%5==0){
        five++;
        temp/=5;
    }
    p={two*q,five*q};
    return p;
}

int main(){
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        ll n,r,p,q;
        scanf("%lld %lld %lld %lld",&n,&r,&p,&q);
        pair<ll,ll>nc,rc,nrc,x;
        nc=solve1(n); /// Finding 2 and 5 in n!
        rc=solve1(r); /// Finding 2 and 5 in r!
        nrc=solve1(n-r); /// Finding 2 & 5 in (n-r)!
        x=solve2(p,q); /// Finding 2 & 5 in p
        ll tot=min(nc.first-(rc.first+nrc.first)+x.first, nc.second-(rc.second+nrc.second)+x.second);
        printf("Case %d: %lld\n",++no,tot);
    }
    return 0;
}

