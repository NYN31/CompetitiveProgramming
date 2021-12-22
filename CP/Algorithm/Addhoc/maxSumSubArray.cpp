/*
1. create two variable far and mx and initialize with 0...!
2. iterate all over the loop & in each iteration you have to do the following operation:
    i.   Add value of i'th position of the array with mx variable...!
    ii.  Update the value of far (maximum value of far or mx) ...! (update start & end position)
    iii. if mx value becomes negative then initialize it with 0...! (update start position)
3. print the value of far...! 

*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long

int maxSumSubArray(vector<int>v){
    int far=0,mx=0, start=0,end=0,s=0;

    for(int i=0;i<v.size();i++){
        mx=mx+v[i];
        if(far<mx){
            far=mx;
            start=s;
            end=i;
        }
        if(mx<0){
            mx=0;
            s=i+1;
        }
    }
    cout<<"Starting Index: "<<start<<endl;
    cout<<"Ending Index: "<<end<<endl;
    return far;
}

int main()
{
    int n ; 
    cin >> n ;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int max_sum = maxSumSubArray(v);
    cout<<"Maximum contiguous sum is "<<max_sum<<endl;
    return 0;

}
