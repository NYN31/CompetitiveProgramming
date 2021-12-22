#include<bits/stdc++.h>
using namespace std;

void large_factor(long long N)
{
    set<long long>s;
    set<long long>::iterator it;
    while(N%2 == 0){
        s.insert(2);
        N/=2;
    }
    for(long long i = 3; i*i <= N; i++)
    {
        while(N%i == 0){
            s.insert(i);
            N/=i;
        }
    }
    if(N>2){
        s.insert(N);
    }
    it = max_element(s.begin(), s.end());
    if(s.size() > 1)
        cout << *it << endl;
    else cout << "-1\n";
}


int main()
{
    long long N;
    while(cin >> N && N!=0)
    {
        if(N < 0)
            N*=(-1);
        large_factor(N);
    }
    return 0;
}
