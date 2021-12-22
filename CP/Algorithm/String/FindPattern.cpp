/**
  Technique: Rolling Hash
  Problem : String Matching
**/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll B = 26;
const ll mod = 1423172537;


/**
    some random primes
    1979339339
    1000163491
    1000173893
    1423165193
    1423172537
    2513475829
**/


vector<int>pos;
ll getHash(string str){
    ll h=0;
    for(int i=0;i<str.size();i++){
        h=h*B + str[i];
        h%=mod;
    }
    return h;
}

void strMat(string str, string pat){
    int n=str.size();
    int m=pat.size();
    ll ph=getHash(pat);
    ll th=0;

    for(int i=0;i<m;i++){
        th=th*B+str[i];
        th%=mod;
    }
    if(th==ph) pos.push_back(0);
    ll basepow=1;
    for(int i=0;i<m-1;i++){
        basepow=basepow*B;
        basepow%=mod;
    }
    for(int i=m;i<n;i++){
        th=th-(str[i-m]*basepow);
        th%=mod;
        th=(th+mod)%mod;
        th=th*B+str[i];
        th%=mod;
        if(th==ph) pos.push_back(i-m+1);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string str,pat;
        cin>>str>>pat;
        strMat(str,pat);
        if(pos.size() == 0) cout<<"Not Found"<<endl<<endl;
        else{
            cout<<pos.size()<<endl;
            for(int i=0;i<pos.size();i++) cout<<pos[i]+1<<" ";
            cout<<endl<<endl;
        }
        pos.clear();
    }
    return 0;
}
