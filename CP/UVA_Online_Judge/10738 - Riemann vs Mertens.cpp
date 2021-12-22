#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1000009
int P[mx],mu[mx],M[mx];

void factor()
{
    mu[1]=1;
    for(int m=2;m<=1000005;m++)
    {
        int n=m,total_factor=0,f=0,cnt=0;
        while(n%2==0){
            cnt++;
            total_factor++;
            n/=2;
        }
        if(cnt>=2){
            mu[m]=0;
            continue;
        }
        for(int i=3;i*i<=n;i+=2){
            cnt=0;
            while(n%i==0){
                cnt++;
                total_factor++;
                n/=i;
            }
            if(cnt>=2){
                mu[m]=0;
                f=1;
                break;
            }
        }
        if(f==1){
            continue;
        }
        if(n>2){
            total_factor++;
        }
        if(total_factor%2==1) mu[m]=-1;
        else if(total_factor%2==0) mu[m]=1;
    }
    M[1]=1;
    for(int i=2;i<=1000005;i++){
        M[i]=M[i-1]+mu[i];
    }
}

int main()
{
    factor();
    int n;
    while(cin>>n&&n!=0){
        cout.width(8);
        cout<<n;
        cout.width(8);
        cout<<mu[n];
        cout.width(8);
        cout<<M[n]<<endl;
    }
    return 0;
}
