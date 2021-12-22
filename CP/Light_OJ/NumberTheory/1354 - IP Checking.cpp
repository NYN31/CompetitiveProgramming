#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000500
#define toint(a) atoi(a.c_str())

int bpow(int a,int b){
    if(b==0) return 1;
    int ret=bpow(a,b/2);
    int tot=bpow(a,b-1);
    if(b%2==0) return ret*ret;
    else return a*tot;
}


int main(){
    int t,no=0;
    cin>>t;
    while(t--){
        string str1,str2;
        cin>>str1>>str2;
        int pos=0;
        string s[8];
        vector<int>v;

        for(int i=0;i<str1.size();i++){
            if(str1[i]!='.') s[pos].push_back(str1[i]);
            else pos++;
        }
        pos++;
        for(int i=0;i<str2.size();i++){
            if(str2[i]!='.') s[pos].push_back(str2[i]);
            else pos++;
        }
        for(int i=0;i<4;i++) v.push_back(toint(s[i]));
        for(int i=4;i<8;i++){
            string ret=s[i];
            reverse(ret.begin(),ret.end());
            int sum=0;
            for(int j=0;j<ret.size();j++)
                sum+=(ret[j]-'0')*bpow(2,j);
            v.push_back(sum);
        }
        bool flag=true;
        for(int i=0;i<v.size()-4;i++){
            if(v[i]!=v[i+4]){
                flag=false;
                break;
            }
        }
        if(flag) printf("Case %d: Yes\n",++no);
        else printf("Case %d: No\n",++no);
    }
    return 0;
}
