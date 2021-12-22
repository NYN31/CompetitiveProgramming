#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 10000500

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

int main(){
    int t,no=0;
    sieve();
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll cnt=0;
        for(int a=0;primes[a]<n;a++){
            int x=n-primes[a];
            if(primes[a]>x) break;
            if(isprime[x]) cnt++;
        }
        printf("Case %d: ",++no);
        cout<<cnt<<endl;
    }
    return 0;
}
