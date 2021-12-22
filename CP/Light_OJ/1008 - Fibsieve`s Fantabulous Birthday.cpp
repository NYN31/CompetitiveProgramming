#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
    ll T, l = 0;
    cin >> T;
    while(T--)
    {
        ll N, root1, a, b, c, d, sub;
        cin >> N;
        root1 = sqrt(N);
        if(root1*root1 == N)
        {
            if(N%2 == 0){
                cout << "Case " << ++l << ": " << root1 << " " << 1 << endl;
            }
            else
                cout << "Case " << ++l << ": " << 1 << " " << root1 << endl;
        }
        else{
 
             if(root1%2 == 0)
             {
                a = (root1)+1;
                b = N - (root1*root1);
                sub = N-(root1*root1);
                if(sub > a)
                {
                    d = sub-a;
                    b = b - (d+d);
                    swap(a,b);
 
                }
                printf("Case %lld: %lld %lld\n", ++l, a, b);
            }
             else
             {
                a = (root1)+1;
                b = N - (root1*root1);
                sub = N-(root1*root1);
                swap(a, b);
                if(sub > b)
                {
                    d = sub-b;
                    a = a - (d+d);
                    swap(a,b);
 
                }
                printf("Case %lld: %lld %lld\n", ++l, a, b);
            }
        }
    }
    return 0;
}
