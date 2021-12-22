/// problem 1 : string sum

#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false)
#define ll long long
#define sz 500005
#define mod 1000000007
#define toint(a) atoll(a.c_str())
string tostr(ll n) {stringstream rr;rr<<n;return rr.str();}
ll power(ll a,ll b){return b==0?:a*power(a,b-1);}
ll gcd(ll a,ll b) {return b==0? a:gcd(b,a%b);}
string add(string a,string b)
{
    string ans;int sa = a.size();int sb = b.size();
    reverse(a.begin(),a.end());reverse(b.begin(),b.end());int carry=0;
    for(int i=0; i<max(sa,sb); ++i)
    {
        int x;if(i<sa) x = a[i]-'0';else x=0;int y=0;
        if(i<sb) y = b[i]-'0';int add = x+y+carry;carry=0;
        if(add>9){ans.push_back((add%10)+'0');carry = add/10;}else ans.push_back(add+'0');
    }
    if(carry) ans.push_back(carry+'0');reverse(ans.begin(),ans.end());
    return ans;
}
int main()
{
    BeatMeScanf;
    string a,b;
    cin>>a>>b;
    cout<<add(a,b)<<endl;
    return 0;
}

/// problem 2 : string multiplication

void mult(string s1, string s2)
{
    string ans, res = "0";
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int sa1 = s1.size(), sa2 = s2.size(), carry, rem, j, k = 0;
    for(int i = 0; i<sa2; i++){
        carry = 0;
        for(j = 0; j<sa1; j++){
            int t = (s1[j]-'0')*(s2[i]-'0')+carry;
            if(t>9){rem = t%10;carry = t/10;}
            else{rem = t;carry = 0;ans.push_back(rem+'0');
        }
        if(carry > 0) ans.push_back(carry+'0');
        if(k){reverse(ans.begin(), ans.end());
            for(int i = 0; i<k; i++)
                ans.push_back('0');
            reverse(ans.begin(), ans.end());
        }
        k++;res = add(ans, res);ans.clear();
    }
    reverse(res.begin(), res.end());cout << res << endl;
    res.clear();
}

/// Problem 3: string modulas
int mod(string num, int a) { 
    // Initialize result 
    int res = 0; 
  
    // One by one process all digits of 'num' 
    for (int i = 0; i < num.length(); i++) 
         res = (res*10 + (int)num[i] - '0') %a; 
  
    return res; 
} 
