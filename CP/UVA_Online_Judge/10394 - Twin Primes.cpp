

#include<bits/stdc++.h>
#define m 20000010
using namespace std;
bool prime[m];
long long twin[m];
void sieve()
{
    for(long long i = 2; i<=m; i++)
        prime[i] = true;
    prime[0] = prime[1] = false;
    for(long long i = 4; i<=m; i+=2)
        prime[i] = false;
    for(long long i = 3; i*i <= m; i+=2)
    {
        if(prime[i]){
            for(long long j = i*i; j<=m; j+=i)
                prime[j] = false;
        }
    }
}
void prime_twin()
{
   long long k=1;
    for(long long i = 3; i<=m; i++){
        if(prime[i] && prime[i+2]){
            twin[k++] = i;
        }
    }
}


int main()
{
    sieve();
    prime_twin();
    long long N;
    while(cin >> N)
    {
        cout << "(" << twin[N] <<", " << twin[N]+2 << ")" << endl;
    }

    return 0;
}

