#include<stdio.h>
 
int main()
{
    int T, n, j = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        printf("Case %d: ", ++j);
        int rem, count, binary, i;
        binary = 0;
        i = 1;
        count = 0;
        while(n!=0){
            rem = n%2;
            n = n/2;
            binary = binary + (rem*i);
            i = i*10;
            if(rem == 1)
                count++;
        }
        if(count%2 == 1)
            printf("odd\n");
        else
            printf("even\n");
    }
    return 0;
}
