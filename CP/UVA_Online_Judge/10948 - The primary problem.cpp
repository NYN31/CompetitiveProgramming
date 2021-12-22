#include<bits/stdc++.h>
#define m 1000005
using namespace std;
int ary[m];
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
int main()
{
    sieve();
    long long N;
    while(cin >> N && N != 0)
    {
        long long f = 0, j, max, t, k, l;

        for(long long i = 2; i<N; i++){
            if(!ary[i]){
                j = N-i;
                if(i>j) break;
                max = 0;
                if(!ary[j]) {
                    f = 1;
                    cout << N << ":" << endl << i << "+" << j << endl;
                    break;
                }
            }
        }
        if(f == 0)
            cout << N << ":" << endl << "NO WAY!" << endl;


    }
    return 0;
} /// DONE THIS
