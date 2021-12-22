#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000500

int freq[sz];
int main(){
    int t,no=0;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>tot;
        memset(freq,0,sizeof freq);
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            freq[a]++;
        }
        for(int i=0;i<sz;i++){
            if(freq[i]>0){
                int x = freq[i]%(i+1);
                freq[i]=freq[i]/(i+1);
                if(x != 0) freq[i]++;
                tot.push_back(freq[i]*(i+1));
            }
        }
        ll sum=0;
        for(int i=0;i<tot.size();i++)
            sum+=tot[i];
        printf("Case %d: %lld\n",++no,sum);
    }
    return 0;
}
