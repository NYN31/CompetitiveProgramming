#include<bits/stdc++.h>
#define m 100000005
using namespace std;
bool prime[m];

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

int main()
{
    sieve();
    long long N,f;
    while(cin >> N)
    {
        if(N%2 == 1)  {
            if(prime[N-2]==0) cout << N << " is not the sum of two primes!" << endl;
            else cout << N << " is the sum of 2 and " << N-2 << "." << endl;
            continue;
        }
        else{
            long long k, j, f = 0;
            k = N/2;
            for(long long i = k+1; ; i++){
                if(prime[i]){
                    j = N-i;
                    if(j<0) break;
                    if(prime[j]){
                        f = 1;
                        cout << N << " is the sum of " << j << " and " << i << "." << endl;
                        break;
                    }
                }
            }
            if(f == 1)
                continue;
        }
       if(f == 0)
           cout << N << " is not the sum of two primes!" << endl;
    }
    return 0;
}



