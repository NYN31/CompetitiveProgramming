#include<bits/stdc++.h>
#define N 1000000
int primesTable[N];

void SieveOfEratosthenes(){

    int i = 2, k;
    for(; i <= N; ++i)
        primesTable[i] = 1;
    primesTable[0] = primesTable[1] = 0;

    int len = sqrt(N);
    for(i = 2; i <= len; ++i){
        if(primesTable[i]){
            for(k = i*i; k<=N; k+=i)
                primesTable[k] = 0;
        }
    }
    primesTable[2] = 1;
}
int main() {

    SieveOfEratosthenes();
    int n, t;
    while(scanf("%d", &n) == 1)
    {
        if(n == 0) break;
        int f = 0;
        for(int a = 3; a < n; a++){
            if( primesTable[a] ){
                int b = n - a;

                if( primesTable[b] ){
                    if(a>b){
                        t = a;
                        a = b;
                        b = t;
                    }
                    f = 1;
                    printf("%d = %d + %d\n", n, a, b);
                    break;
                }
            }
        }
        //if(f == 0) printf("Goldbach's conjecture is wrong.\n");
        if(f == 0) printf("%d = %d + %d\n", n, f, n);
    }
    return 0;
}
