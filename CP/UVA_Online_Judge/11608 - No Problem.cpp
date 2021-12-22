#include<bits/stdc++.h>
using namespace std;

int main()
{
    int prob[13], prob_req[13], cum_sum[13], no = 0;
    while(cin >> prob[0])
    {
        if(prob[0] < 0)
            break;
        else{
            for(int i = 1; i<=12; i++) cin >> prob[i];
            for(int i = 0; i<12; i++) cin >> prob_req[i];

            printf("Case %d:\n", ++no);

            for(int i = 0; i<12; i++)
            {
                if(prob[i]-prob_req[i] >= 0)
                {
                    prob[i+1] += prob[i]-prob_req[i];
                    cout << "No problem! :D" << endl;
                }
                else {
                    prob[i+1] += prob[i];
                    cout << "No problem. :(" << endl;
                }
            }
        }

    }
    return 0;
}
