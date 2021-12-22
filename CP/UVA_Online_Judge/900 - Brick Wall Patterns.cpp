/// It can be solved by array with size 50

#include<bits/stdc++.h>
#define L 51
using namespace std;

string fib[L];

string add(string a,string b)
{
    string ans;
    int sa = a.size();
    int sb = b.size();
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int carry=0;
    for(int i=0; i<max(sa,sb); ++i)
    {
        int x;
        if(i<sa)
            x = a[i]-'0';
        else x=0;
        int y=0;
        if(i<sb)
            y = b[i]-'0';
        int add = x+y+carry;
        carry=0;
        if(add>9)
        {
            ans.push_back((add%10)+'0');

            carry = add/10;
        }
        else
            ans.push_back(add+'0');

    }
    if(carry)
        ans.push_back(carry+'0');
    reverse(ans.begin(),ans.end());
    return ans;
}

void precalc()
{
    fib[1]="1";
    fib[2]="2";
    for(int i=3; i<L; ++i)
    {
        fib[i] = add(fib[i-1],fib[i-2]);

    }
}

int main()
{
    precalc();
    int n;
    while(cin>>n && n!=0)
    {
        cout<<fib[n]<<"\n";
    }
}


