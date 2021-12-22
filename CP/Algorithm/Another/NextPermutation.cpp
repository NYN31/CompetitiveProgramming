#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n, num, j=1;
        string str;
        cin >> n;
        for(int i = 1; i<=n; i++){
            cin >> num;
            str.push_back(num+48);
        }
        bool ans = next_permutation(str.begin(), str.end());
        if(!ans)
            cout << -1 << endl;
        else{
            cout << str << endl;
        }
    }
    return 0;
}
