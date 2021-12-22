///Finding primitive Pythagorean triple

#include<bits/stdc++.h>
using namespace std;
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long

const int sz = 1000100;

int gcd(int a,int b) {return b==0? a:gcd(b,a%b);}

int main(){
    BeatMeScanf;
    int n;
    while(cin>>n){
        int cntT=0,a,b,c,cnt=0,cheak[sz]={0};
        for(int i=1;i*i<=n;i++){
            for(int j=i+1;j*j<=n;j++){
                if(gcd(i,j)==1){
                    a=j*j-i*i;
                    b=2*i*j;
                    c=j*j+i*i;
                    if(c>n) break;
                    if(gcd(a,gcd(b,c))==1) cntT++;

                    int x=a,y=b,z=c;
                    while(z<=n){
                        cheak[x]=cheak[y]=cheak[z]=1;
                        x+=a;
                        y+=b;
                        z+=c;
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(cheak[i]) cnt++;
        }
        cout<<cntT<<" "<<n-cnt<<endl;
    }
    return 0;
}
