#include<bits/stdc++.h>
#define L 110
using namespace std;

void add(char s[], char t[])
{
    char r[L], sf[L], tf[L];
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
        s[0] = '0'; s[1] = '\0';
    }
    else{
        for(i = 0; i<=M; i++)
            s[M-i] = r[i];
        s[i] = '\0';
    }
}

int main()
{
    char a[L], b[L], res[L];
    a[0] = '0';
    while(cin >> b && b[0] != '0')
    {
        add(a, b);
    }
    cout << a << endl;
    return 0;
}

