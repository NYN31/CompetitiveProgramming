#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> v;
    int n;
    while(cin >> n)
    {
        int a[100], length[100], sub_seq[100], tot;
        length[0] = 1;
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }

        for(int i = 0; i<n; i++)
            length[i] = 1; /// Initially all index have value 1
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(a[i]>a[j] && length[j]+1 >= length[i]){
                        length[i] = length[j]+1;
                        sub_seq[i] = j;
                }
            }
        }
        int max = 0, loc = 0;
        for(int i = 0; i<n; i++){
            if(max<length[i]){
                max = length[i];
                loc = i;
            }
        }
        cout << max << endl; /// displaying max length

        v.push_back(a[loc]);
        for(int i = 1; i<max; i++){
            v.push_back(a[sub_seq[loc]]);
            loc = sub_seq[loc];
        }

        reverse(v.begin(), v.end());
        for(int i = 0; i<v.size(); i++)
            cout << v[i] << " "; /// displaying longest subsequence
        cout << endl;

        v.clear();
    }
    return 0;
}
/*
12
0 4 12 2 10 6 9 13 3 11 7 15
*/

