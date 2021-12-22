#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1500

vector<int>divi[sz];
vector<int>vec;

void divisor(){
    int ans=0;
    divi[1].push_back(1);
    for(int n=2;n<=1000;n++){
        ans=0;
        for(int i=1;i*i<=n;i++){
            if(n%i == 0){
                if(n/i == i) ans++;
                else ans+=2;
            }
        }
        divi[ans].push_back(n);
    }
    for(int i=1;i<=32;i++){
        sort(divi[i].rbegin(),divi[i].rend());
        for(int j=0;j<divi[i].size();j++)
            vec.push_back(divi[i][j]);
    }
}

int main()
{
    divisor();
    int t,no=0;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("Case %d: ",++no);
        cout<<vec[n-1]<<endl;
    }
    return 0;
}

