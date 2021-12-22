#include<bits/stdc++.h>
#define m 5000000
using namespace std;
long long ary[m];
vector<long long int>prime;

void sieve(long long N)
{
    ary[0] = ary[1] = 1;
    for(long long i = 4; i<=N; i+=2)
        ary[i] = 1;
    for(long long i = 3; i*i<=N; i++)
    {
        if(!ary[i]){
            for(long long j = i*i; j<=N; j+=i)
                ary[j] = 1;
        }
    }
    prime.push_back(2);
    for(long long i = 3; i<=N; i+=2){
        if(!ary[i])
            prime.push_back(i);
    }
}
int main()
{
    long long N;
    sieve(100000);
    while(cin >> N && N!=0)
    {
        long long len = N/2, count = 0, count2 = 0;
        for(long long i = 0; i<len; i++){
            for(long long j = 0; j<N; j++){
                if(prime[i] == prime[j] && prime[i]+prime[j] == N){
                    count++;
                }
                else if(prime[i]+prime[j] == N){
                    count2++;
                }
                if(prime[i]+prime[j]>N)
                    break;
            }
        }
        count = count2/2 + count;
        cout << count << endl;
    }
    return 0;
}

