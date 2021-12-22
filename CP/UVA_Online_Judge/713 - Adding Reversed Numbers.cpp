#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#define L 205
using namespace std;


void add(char s[], char t[], char f[])
{
    char r[L], sf[L], tf[L], res[L], res1[L];
    int i, j, n, c, s_len, t_len, m_len, sum, s_num, t_num, M;

    s_len = strlen(s);
    t_len = strlen(t);

    for(i = 0; i<s_len; i++)
        sf[i] = s[s_len-i-1];
    for(i = 0; i<t_len; i++)
        tf[i] = t[t_len-i-1];

    for(i = s_len; i<L; i++)
        sf[i] = '0';
    for(i = t_len; i<L; i++)
        tf[i] = '0';

    c = 0;
    for(i = 0; i<L; i++)
    {
            s_num = sf[i]-48;
            t_num = tf[i]-48;

            sum = s_num + t_num + c;
            if(sum>9){
                n = sum%10;
                c = 1;
            }
            else{
                n = sum;
                c = 0;
            }
            r[i] = n+48;
    }

    for(i = L-1; i>=0; i--)
        if(r[i] != '0') break;

    M = i;
    if(M == -1){
        res[0] = '0'; res[1] = '\0';
    }
    else{
        for(i = 0; i<=M; i++)
            res[M-i] = r[i];
        res[i] = '\0';
    }
    int z3 = strlen(res);
        for(i = 0; i<z3; i++)
            res1[i] = res[z3-i-1];

    int count = 0, k=0;
    for(i = 0; i<=M; i++)
    {
        if(res1[i] == '0'){
            count++;
        }
        else break;
    }
    for(i = count; i<=M; i++){
        f[k] = res1[i];
        k++;
    }
    f[k] = '\0';
}

int main()
{
    char a[L], b[L], result[L], a1[L], b1[L];
    int T, z1, z2,i;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s %s", a, b);
        z1 = strlen(a);
        z2 = strlen(b);
        for(i = 0; i<z1; i++)
            a1[i] = a[z1-i-1];
        a1[i] = '\0';
        for(i = 0; i<z2; i++)
            b1[i] = b[z2-i-1];
        b1[i] = '\0';
        add(a1, b1, result);
        printf("%s\n", result);
    }
    return 0;
}


