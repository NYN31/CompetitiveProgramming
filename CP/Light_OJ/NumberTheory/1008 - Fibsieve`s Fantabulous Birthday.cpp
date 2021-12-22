#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 1000500
int main()
{
    ll t,no=0;
    cin>>t;
    while(t--)
    {
        ll n,root1,a,b,c,d,sub;
        cin>>n;
        root1=sqrt(n);
        if(root1*root1==n){
            if(n%2==0) cout<<"Case "<<++no<<": "<<root1<<" "<<1<<endl;
            else cout<<"Case "<<++no<<": "<<1<<" "<<root1<<endl;
        }
        else{
             if(root1%2==0){
                a=root1+1;
                b=n-(root1*root1);
                sub=n-(root1*root1);
                if(sub>a){
                    d=sub-a;
                    b=b-(d+d);
                    swap(a,b);
                }
                printf("Case %lld: %lld %lld\n", ++no, a, b);
            }
            else{
                a=root1+1;
                b=n-(root1*root1);
                sub=n-(root1*root1);
                swap(a,b);
                if(sub>b){
                    d=sub-b;
                    a=a-(d+d);
                    swap(a,b);
                }
                printf("Case %lld: %lld %lld\n", ++no, a, b);
            }
        }
    }
    return 0;
}
