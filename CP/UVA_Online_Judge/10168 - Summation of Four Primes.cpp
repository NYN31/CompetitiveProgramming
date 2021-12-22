#include<bits/stdc++.h>
#define Num 10000000
using namespace std;
bool prime[Num];

void sieve()
{

    for(long long i = 2; i<=Num; i++) prime[i] = true;
    prime[0] = prime[1] = false;
    for(long long i = 4; i<=Num; i+=2)
        prime[i] = false;
    for(long long i = 3; i*i<=Num; i++)
    {
        if(prime[i]){
            for(long long p = i*i; p<=Num; p+=i)
                prime[p] = false;
        }
    }
}

void gold(long long N)
{
    long long j;
    if(N == 4) {cout << "2 2" << endl; return;}
    for(long long i = 3; i<=N; i+=2)
    {
        if(prime[i] == true){

            j = N - i;
            if(prime[j] == true){
                if(i > j) break;
                cout << i << " " << j <<  endl;
                return;
            }
        }
    }
}

int main()
{
    sieve();
    long long N;
    while(cin >> N)
    {
        if(N<8){
            cout << "Impossible." << endl;
            continue;
        }
        else if(N%2 == 0){
            cout << "2 2 ";
            N = N-4;
        }
        else {
            cout << "2 3 ";
            N = N-5;
        }
        gold(N);
    }
    return 0;
}


/////////////////////////////////////////////////////////////////////////////////////
/*int main()
{
    sieve();
    long long N;
    while(cin >> N)
    {
        long long a = 2, b = 2, j, rem, f = 0;
        rem = N - 4;
        if(N%2 == 0){
            for(long long i = 2; i<=rem; i++)
            {
                if(prime[i] == true){
                    j = rem - i;
                    if(prime[j] == true){
                        f = 1;
                        if(i > j) break;
                        cout <<a<<" "<<b<<" "<<i<<" " <<j <<endl;
                        break;
                    }
                }
            }
        }
        a = 2, b = 3;
        rem = N - 5;
        if(f == 0){
            for(long long i = 2; i<=rem; i++)
            {
                if(prime[i] == true){
                    j = rem - i;
                    if(prime[j] == true){
                        f = 1;
                        if(i > j) break;
                        cout <<a<<" "<<b<<" "<<i<<" " <<j <<endl;
                        break;
                    }
                }
            }
        }
        if(f == 0)
            cout << "Impossible." << endl;
    }
    return 0;
}*/
