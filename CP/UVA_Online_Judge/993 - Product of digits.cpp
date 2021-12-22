#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,cnt2=0,cnt3=0;
        string str;
        vector<int>v;
        cin>>n;
        if(n==1||n==0){
            cout<<n<<endl;
            continue;
        }
        while(n%2==0){
            n=n/2;
            cnt2++;
            v.push_back(2);
        }
        for(int i=3;i*i<=n;i+=2){
            while(n%i==0){
                n=n/i;
                v.push_back(i);
                if(i==3) cnt3++;
            }
        }
        if(n!=1) { if(n==3) cnt3++; v.push_back(n); }
        if(v[v.size()-1]>9) {
            cout<<-1<<endl;
            continue;
        }
        int x2=cnt2/3;
        int y2=cnt2%3;
        for(int i=1;i<=x2;i++) str.push_back((char)(8+'0'));

        int x3=cnt3/2;
        int y3=cnt3%2;

        for(int i=1;i<=x3;i++) str.push_back((char)(9+48));

        if(y2>0&&y3>0) y2--, y3--, str.push_back((char)((2*3)+48));
        if(y2<=2) y2=y2*2;
        if(y2!=0) str.push_back((char)(y2+48));
        if(y3==1) str.push_back((char)(3+48));


        for(int i=0;i<v.size();i++) {
            if(v[i]!=2 && v[i]!=3){
                str.push_back((char)(v[i]+48));
            }
        }
        sort(str.begin(),str.end());
        cout<<str<<endl;
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,arr[1000];
        cin>>n;
        if(n<10){
            cout<<n<<endl;
            continue;
        }
        int d=9,i=0;
        while(d>1){
            while(n%d==0){
                n=n/d;
                arr[i++]=d;
            }
            d--;
        }
        sort(arr,arr+i);
        if(n==1){
            for(int j=0;j<i;j++) cout<<arr[j];
            cout<<endl;
        }
        else cout<<-1<<endl;
    }
    return 0;
}

*/
