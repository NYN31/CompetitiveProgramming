#include<bits/stdc++.h>
using namespace std ;

int main(){
    int n;
    while(cin>>n){
        vector<int>arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        int q;
        cin>>q;
        while(q--){
            int a;
            cin>>a;

            int x=upper_bound(arr.begin(),arr.end(),a)-arr.begin();
            int y=lower_bound(arr.begin(),arr.end(),a)-arr.begin()-1;
            int ans1=arr[y];
            int ans2=arr[x];
            if(y<0 && x>=n) cout<<'X'<<" "<<'X'<<endl;
            else if(y<0) cout<<'X'<<" "<<ans2<<endl;
            else if(x>=n) cout<<ans1<<" "<<'X'<<endl;
            else cout<<ans1<<" "<<ans2<<endl;
        }
    }
    return 0 ;
}
