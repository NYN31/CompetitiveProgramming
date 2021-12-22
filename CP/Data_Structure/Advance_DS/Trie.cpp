#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define sz 1030

int ind;
bool flag[sz];
int trie[sz][26];

void add(string str){
    int u=0;
    for(int i=0;i<str.size();i++){
        int d=str[i]-'a';
        if(!trie[u][d]) trie[u][d]=++ind;
        u=trie[u][d];
    }
    flag[u]=true;
}

bool query(string str){
    int u=0;
    for(int i=0;i<str.size();i++){
        int d=str[i]-'a';
        if(!trie[u][d]) return false;
        u=trie[u][d];
    }
    if(flag[u]) return true;
    return false;
}

int main()
{
    BeatMeScanf;
    memset(flag,0,sizeof flag);
    memset(trie,0,sizeof trie);

    add("noyon");
    add("rohan");
    add("jaber");

    if(query("noyon")) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;

    add("aber");

    if(query("borhan")) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
    if(query("karim")) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;

    add("ashik");

    if(query("ashik")) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
    if(query("aber")) cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;
    return 0;
}
