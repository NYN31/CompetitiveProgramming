#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
#define lim 20000010

ll div_sum[lim+5];

void precal_divisor_sum(){
    for(ll i=1;i<lim;i++) {
        for(ll j=i;j<lim;j+=i){
            div_sum[j]+=i;
        }
    }
    div_sum[0] = div_sum[1] = 0;
    for(int i=0;i<lim;i++) {
        div_sum[i] += div_sum[i-1];
    }
}


int main() {
    precal_divisor_sum();
    ll n;
    while(cin>>n && n != 0) {
    	cout<<div_sum[n]<<endl;
    }
    return 0;
}


/// Using pattern which is same as light oj problem name -> A new funtion

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
    ll n;
    while(cin>>n && n != 0) {
        ll ans=solve(n) + (n * (n + 1)) / 2 + n - 1 ;
        cout << ans - 1 << endl;
    }
    return 0;
}
