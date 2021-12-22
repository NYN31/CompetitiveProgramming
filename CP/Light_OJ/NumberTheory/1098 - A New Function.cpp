/*
    There is a pattern, which can be solve in O( sqrt(n) )
    pattern:

        24
        2:
        3:
        4: 2
        5:
        6: 2 3
        7:
        8: 2   4
        9:   3
        10: 2     5
        11:
        12: 2 3 4   6
        13:
        14: 2         7
        15:   3   5
        16: 2   4       8
        17:
        18: 2 3     6     9
        19:
        20: 2   4 5         10
        21:   3       7
        22: 2                 11
        23:
        24: 2 3 4   6   8       12

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long


ll solve(ll n){
    ll sum=0,prev=0;
    for(int i=2;i*i<=n;i++){
        sum += ((i+n/i)*((n/i)-i+1))/2;
        sum += ((n/i)-i)*i;
        prev=sum;
    }
    return sum;
}

int main(){
    int t,no=0;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=solve(n);
        printf("Case %d: %lld\n",++no,ans);
    }
    return 0;
}
