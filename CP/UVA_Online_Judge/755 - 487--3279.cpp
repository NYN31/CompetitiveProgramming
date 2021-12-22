#include<iostream>
#include<string.h>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, flg;
    char str[1000], nyn[1000];
    char ch[] = "22233344455566677778889991";
    cin >> t;
    while(t--)
    {
        map<string, int>mp;
        map<string, int>::iterator it;
        cin >> n;
        cin.ignore();
        while(n--){
            gets(str);
            int j = 0;
            for(int i = 0; str[i]; i++)
            {
                if(str[i]>='0' && str[i]<='9')
                    nyn[j++] = str[i];
                else if(str[i]>='A' && str[i]<='Z')
                    nyn[j++] = ch[str[i]-'A'];
                if(j == 3)
                    nyn[j++] = '-';
            }
            nyn[j] = '\0';
            mp[nyn]++;
        }
        flg = 0;
        for(it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second != 1){
                flg = 1;
                cout << it->first << " " << it->second << endl;
            }
        }
        if(!flg) puts("No duplicates.");
        if(t) puts("");
    }
    return 0;
}
