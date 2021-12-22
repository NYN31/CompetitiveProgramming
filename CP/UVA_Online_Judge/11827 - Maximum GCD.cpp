#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
using namespace std;

typedef int ll;

ll gcd(ll a, ll b)
{
    if(a == 0) return b;
    else return gcd(b%a, a);
}

int main()
{
    string s;
    ll T;
    cin >> T;
    getchar();
    while(T--)
    {
        getline(cin, s);
        ll len = s.size(), arr[99], l = 0, num = 0,i, flag = 0;
        for(i = 0; i<len; i++){
            if(s[i] == ' '){

                if(num != 0){
                    if(flag == 1){
                        num = num*-1;
                        flag = 0;
                    }
                    arr[l] = num;
                    l++;
                }
                 num = 0;
            }
            else if(s[i] == '-')
                flag = 1;
            else if(s[i]>='0' && s[i]<='9'){
                num = num*10 + (s[i]-'0');
            }
            else if(s[i]>=65 && s[i]<=90 || s[i]>=97 && s[i]<=122)
                break;

        }
        if(num == 0)
            l--;
        else
            arr[l] = num;

        ll max = 0, GCD,j;
        for(i = 0; i<l; i++){
            for(j = i+1; j<=l; j++){
                GCD = gcd(arr[i], arr[j]);
                if(GCD>max){
                    max = GCD;
                }
            }
        }
       cout << max << endl;

    }
    return 0;
}
/*
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int gcd(int a, int b){
	if(a%b==0) return b;
	return gcd(b,a%b);
}

int main(){
	int T,N,a[99],ans;
	string s;

	cin>>T;
	getline(cin,s);

	while(T--){
		getline(cin,s);
		istringstream is(s);
		N = 0;

		while(is>>a[N]) ++N;

		ans = 0;

		for(int i = 0;i<N;++i)
			for(int j = i+1;j<N;++j)
				ans = max(ans,gcd(a[i],a[j]));

		cout<<ans<<endl;
	}

	return 0;
}
*/
