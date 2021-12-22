/// SOME PROBLEM:

/*
problem 1: finding n! using array multiplication
problem 2: fermat's little thoerem 
problem 3: How many trailing zeroes in n! in different base.
*/
  
problem 1: finding n! using array multiplication
  
#include<iostream>
using namespace std;
#define MAX 5000

int multiply(int x, int res[], int res_size);
void factorial(int n)
{
    int res[MAX];
    res[0] = 1;
    int res_size = 1;
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);

    cout << "Factorial of given number is \n";
    for (int i=res_size-1; i>=0; i--)
        cout << res[i];
}
int multiply(int x, int res[], int res_size)
{
    int carry = 0;
    for (int i=0; i<res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry  = prod/10;
    }
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}
int main()
{
    int n;
    while(cin>>n){
        factorial(n);
    }
    return 0;
}

///problem 2: fermat's little thoerem 

  
/* 
    for the equation: a^b^c%m
    we should use farmet's little theorem
    first we should find out x=b^c%(m-1)
        because fermat's little thoerem state a^(m-1)%m where a not divisible by m
    then we have to fine y=a^x%m
    complexity: log(c)+log(x) 
*/

#i0nclude<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
ll binpow(ll n, ll p, ll m) {if(p==0) return 1LL;if(p%2==0){ll res=binpow(n,p/2,m);return (res*res)%m;}return (n*binpow(n,p-1,m))%m;}
int main(){
    BeatMeScanf;
    ll a,b,c,m;
    while(cin>>a>>b>>c>>m){
        ll x=binpow(b,c,m-1);
        ll y=binpow(a,x,m);
        cout<<x<<" "<<y<<endl;
    }
    return 0;
}



/// problem 3: How many trailing zeroes in n! in different base.

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(ll n,ll b)
{
    long long ans = 1000000000000000000LL;
    for(ll i=2;i*i<=b;i++){
        int cnt=0;
        while(b%i==0){
            b=b/i;
            cnt++;
        }
        if (cnt == 0) continue;
        ll tmp=1,sum=0;
        while(tmp<=n/i){
            tmp*=i;
            sum+=(n/tmp);
        }
        ans=min(ans,sum/cnt);
    }
    if(b!=1){
        ll tmp=1,sum=0;
        while(tmp<=n/b){
            tmp*=b;
            sum+=(n/tmp);
        }
        ans=min(ans,sum);
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ll n,b;
    while(cin>>n>>b){
        solve(n,b);
    }
    return 0;
}
