#include<bits/stdc++.h>
using namespace std;

string add(string a, string b)
{
    string ans;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int sa = a.size(), sb = b.size(), carry = 0;
    for(int i = 0; i<max(sa, sb); i++)
    {
        int x = 0, y = 0;
        if(i<sa)
            x = a[i]-'0';
        if(i<sb)
            y = b[i]-'0';
        int add = x+y+carry;
        carry = 0;
        if(add>9){
            ans.push_back((add%10)+'0');
            carry = 1;
        }
        else ans.push_back(add+'0');
    }
    if(carry)
        ans.push_back(carry+'0');
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int T, flag = 0;;
    cin >> T;
    while(T--)
    {
        int N, x, y;
        string a, b, res;
        cin >> N;
        if(flag == 1)
            cout << endl;
        flag = 1;
        while(N--)
        {
            cin >> x; a.push_back(x+'0');
            cin >> y; b.push_back(y+'0');
        }
        res = add(a, b);
        cout << res << endl;
    }
    return 0;
}

