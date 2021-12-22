#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 100010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back

int const N = 18;

int main() {
    BeatMeScanf;
    char ch;
    string str;
    map<string,int>mp;
    while(1) {
        ch = getchar();
        if(ch == EOF) break;
        if(ch>='A' && ch<='Z') ch = ch + 32;
        if(ch>='a' && ch<='z') str.pb(ch);
        else if(ch != '-') {
            if(str.size() > 0)
                mp[str]++;
            str.clear();
        }
        else{
            ch = getchar();
            if(ch != '\n' && (ch>='a'&&ch<='z' || ch>='A'&&ch<='Z' || ch=='-')) {
                str.pb('-');
                if(ch>='A' && ch<='Z')
                    ch = ch + 32;
                str.pb(ch);
            }
            else if(ch!='\n') {
                str.pb('-');
                if(str.size()>0) mp[str]++;
                str.clear();
            }
        }
    }
    for(auto ans : mp) cout<<ans.ff<<endl;
    return 0;
}
