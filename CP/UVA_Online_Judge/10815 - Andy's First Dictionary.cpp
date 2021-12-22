#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

int main(){
    BeatMeScanf;
    string s;
    map<string,int>mp;
    map<string,int>::iterator it;
    while(getline(cin,s)){

        string x;
        for(int i=0;i<s.size();i++){
            if(!(s[i]>='A'&&s[i]<='Z' || s[i]>='a'&&s[i]<='z')){
                if(x.size()>0) mp[x]=1;
                x.clear();
            }else if(s[i]>='A'&&s[i]<='Z' || s[i]>='a'&&s[i]<='z') {
                x.push_back(tolower(s[i]));
            }
        }
        if(x.size()>0) mp[x]=1;
    }
    for(it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<endl;
    }

    return 0;
}
