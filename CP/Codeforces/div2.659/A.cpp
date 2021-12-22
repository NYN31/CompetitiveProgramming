#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

int main() {
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        string str;
        vector<string>ans;
        for(int i=0;i<200;i++) {
            char ch = (char)((i%26) + 97);
            str.pb(ch);
        }
        ans.pb(str);
        for(int i=0;i<n;i++) {
            int x = arr[i];
            string temp = str;
            int g = (int)(temp[x]-97);
            g = g%26; g++; g=g%26;
            char ch = (char)(g+97);
            temp[x] = ch;
            str = temp;
            ans.pb(temp);
        }
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
    }
    return 0;
}
