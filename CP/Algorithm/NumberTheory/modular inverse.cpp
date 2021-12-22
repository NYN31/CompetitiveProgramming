  
/// Using Extended Euclid

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int extendedGcd(int a,int b,int &x,int &y){
    if(a == 0){
        x = 1, y = 1;
        return b;
    }
    int x1,y1;
    int d = extendedGcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}
int modInvEgcd(int a,int m){
    int x,y;
    int gcd=extendedGcd(a,m,x,y);
    if(gcd != 1)
        return cout<<"Not possible"<< endl , 0 ;
    return (x%m + m)%m ; /// (ax)%m=1 & x can be a negative value, thats why extra m is added
}

int main()
{
    cout<<modInvEgcd(7,11)<<endl;
    return 0;
}






/// Using fermet little theorem when m is prime

#include<bits/stdc++.h>
using namespace std ;
#define ll long long 

int bigmod(int a,int b,int m){
    if(b==0) return 1;
    else if(b%2==0){
        int ret=bigmod(a,b/2,m);
        return (ret*ret)%m;
    }else{
        int ret=bigmod(a,b-1,m);
        return (a*ret)%m;
    }
}

int modInvFermat(int a,int m){
    return bigmod(a,m-2,m);
}

int main(){
    cout<<modInvFermat(7,11)<<endl;
    return 0 ;
}


/// Using Euler Totient Function
/// It is efficient when we have to find modular inverser from 1 to n
#include<bits/stdc++.h>
using namespace std ;
#define ll long long

int bigmod(int a,int b,int m){
    if(b==0) return 1;
    else if(b%2==0){
        int ret=bigmod(a,b/2,m);
        return (ret*ret)%m;
    }else{
        int ret=bigmod(a,b-1,m);
        return (a*ret)%m;
    }
}

int phi(int n){
    int res = n ;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            while(!n%i)
                n /= i;
            res-=(res/i) ;
        }
    }
    if(n>1) res -= (res/n) ;
    return res ;
}

int modInvEuler(int a,int m){
    if(__gcd(a,m) != 1) {
        cout<<"Not Possible"<<endl;
        return 0;
    }
    int p=phi(m)-1;
    return bigmod(a,p,m);
}

int main(){
    cout<<modInvEuler(7,11)<<endl;
    return 0 ;
}



/// Finding all modular inverse from 1 to n
/// Complexity : 0(N)

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 97
int main()
{
    while(1){
        int n;
        int inv[100];
        cin>>n;
        inv[1]=1;
        for(int i=2;i<=n;i++){
            inv[i] = (m - (m/i) * inv[m%i] % m) % m;
        }
        for(int i=1;i<=n;i++) cout<<i<<" "<<inv[i]<<endl;
    }
    return 0;
}
