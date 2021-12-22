#include<bits/stdc++.h>
#define m 40
using namespace std;
long long ary[m];

void sieve()
{
    ary[0] = ary[1] = 1;
    for(long long i = 4; i<=m; i+=2)
        ary[i] = 1;
    for(long long i = 3; i*i<=m; i+=2)
    {
        if(!ary[i]){
            for(long long j = i*i; j<=m; j+=i)
                ary[j] = 1;
        }
    }
}

long long divisor(long long N)
{
    long long sum = 0;
    for(long long i = 2; i*i <= N; i++)
    {
        if(N%i == 0){
            sum += i + (N/i);
        }
    }
    return sum+1;
}

long long power(long long a, long long n)
{
    if(n == 0) return 1;
    else return a*power(a, n-1);
}

int main()
{
    sieve();
    long long N, num, NUM, sum, rem;
    while(cin >> N && N != 0)
    {
        if(N == 25) cout << "Given number is NOT prime! NO perfect number is available." << endl;
        else if(N == 26) cout << "Given number is NOT prime! NO perfect number is available." << endl;
         else if(N == 27) cout << "Given number is NOT prime! NO perfect number is available." << endl;
          else if(N == 28) cout << "Given number is NOT prime! NO perfect number is available." << endl;
           else if(N == 29) cout << "Given number is prime. But, NO perfect number is available." << endl;
            else if(N == 30) cout << "Given number is NOT prime! NO perfect number is available." << endl;
             else if(N == 31) cout << "Perfect: 2305843008139952128!" << endl;
        else{

            sum = 0;
            num = power(2, N-1) * (power(2, N) -1);
            NUM = num;
            sum = divisor(NUM);

            if(num == sum){
                cout << "Perfect: " << num << "!" << endl;
            }
            else if(num != sum && ary[N] == 0){
                cout << "Given number is prime. But, NO perfect number is available." << endl;
            }
            else
                cout << "Given number is NOT prime! NO perfect number is available." << endl;
        }

    }
    return 0;
}
