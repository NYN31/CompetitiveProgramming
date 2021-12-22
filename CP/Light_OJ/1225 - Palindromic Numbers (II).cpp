#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T, no = 0;
    cin >> T;
    while(T--)
    {
        string s1, s2;
        cin >> s1;
        s2 = s1;
        reverse(s1.begin(), s1.end());
        if(s1 == s2) printf("Case %d: Yes\n", ++no);
        else printf("Case %d: No\n", ++no);
 
    }
    return 0;
}
