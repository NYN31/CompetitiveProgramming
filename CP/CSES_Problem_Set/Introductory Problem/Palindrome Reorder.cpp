#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 1010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back
 
int pref[30];
 
int main()
{
    BeatMeScanf;
    string str;
    cin>>str;
    deque<char>dq;
    int len = str.size(),cnt=0;
    for(int i=0;i<len;i++) pref[str[i]-'A']++;
    for(int i=0;i<26;i++) {
        if(pref[i]>0 && pref[i]%2==1) cnt++;
    }
    if(cnt>1) cout<<"NO SOLUTION"<<endl;
    else{
        for(int i=0;i<26;i++) {
            if(pref[i]%2==1) {
                while(pref[i]){
                    dq.push_back((char)i+65);
                    pref[i]--;
                }
            }
        }
        for(int i=0;i<26;i++) {
            if(pref[i]%2==0 && pref[i]>0){
                while(pref[i]){
                    dq.push_back((char)i+65);
                    dq.push_front((char)i+65);
                    pref[i]-=2;
                }
            }
        }
        for(auto v : dq) cout<<v;
        cout<<endl;
    }
    return 0;
}
