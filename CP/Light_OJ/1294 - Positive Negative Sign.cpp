#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int T, no = 0;
    cin >> T;
    while(T--)
    {
        long long m, n;
        cin >> m >> n;
        cout << "Case " << ++no << ": " << (m/2)*n << endl;
    }
    return 0;
}
