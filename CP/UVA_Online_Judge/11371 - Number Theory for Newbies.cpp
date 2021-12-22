#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
    string s;
    while(cin>>s){
        string small,big;
        int k=1;
        sort(s.begin(),s.end());
        big=s;
        reverse(big.begin(),big.end());
        do{
            if(s[0]!='0'&&k){
                k=0;
                small=s;
            }
        }while(next_permutation(s.begin(), s.end()));
        ll a=atoll(big.c_str());
        ll b=atoll(small.c_str());
        cout<<a<<" - "<<b<<" = "<<a-b<<" = "<<9<<" * "<<(a-b)/9<<endl;
    }
}

