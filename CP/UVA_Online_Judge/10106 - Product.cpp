#include<bits/stdc++.h>
using namespace std;

string add(string a,string b)
{
    string an, kl = "0";
    int sa = a.size();
    int sb = b.size();
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
            an.push_back((add%10)+'0');

            carry = add/10;
        }
        else
            an.push_back(add+'0');

    }
    if(carry)
        an.push_back(carry+'0');
    int count = 0;
    for(int i = 0; i<an.size(); i++)
    {
        if(an[i] != '0') count = 1;
    }
    if(count == 0) return kl;
    else return an;
}

void mult(string s1, string s2)
{
    string ans, res = "0";
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int sa1 = s1.size(), sa2 = s2.size(), carry, rem, j, k = 0;

    for(int i = 0; i<sa2; i++)
    {
        carry = 0;

        for(j = 0; j<sa1; j++){
            int t = (s1[j]-'0')*(s2[i]-'0')+carry;
            if(t>9){
                rem = t%10;
                carry = t/10;
            }
            else{
                rem = t;
                carry = 0;
            }
            ans.push_back(rem+'0');
        }
        if(carry > 0) ans.push_back(carry+'0');
        if(k){
            reverse(ans.begin(), ans.end());
            for(int i = 0; i<k; i++)
                ans.push_back('0');
            reverse(ans.begin(), ans.end());
        }
        k++;
        res = add(ans, res);
        ans.clear();
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    res.clear();

}

int main()
{
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        mult(s1, s2);
        s1.clear();
        s2.clear();
    }
    /*int num1, num2;
    while(cin >> num1 >> num2)
    {
        stringstream ss1, ss2;
        ss1 << num1; ss2 << num2;
        string s1 = ss1.str(), s2 = ss2.str();
        multiply(s1, s2);
    }*/

    return 0;
}
