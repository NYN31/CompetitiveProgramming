#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
 
int main(){
    BeatMeScanf;
    int t,no=0;
    cin>>t;
    while(t--){
        int n,cnt=0;
        string s;
        cin>>n>>s;
        bool cheak[n+50];
        for(int i=0;i<n+5;i++) cheak[i]=true;
 
        for(int i=0;i<s.size();i++){
            if(s[i]=='.' && cheak[i]==1){
                if(i+1<n) cheak[i+1]=0;
                if(i+2<n) cheak[i+2]=0;
                cnt++;
            }
        }
        cout<<"Case "<<++no<<": "<<cnt<<endl;
    }
    return 0;
}
