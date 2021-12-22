#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string s1, s2;
    char ans[1000], ans2[1000];
    int no = 0;
    while(getline(cin, s1))
    {
        getline(cin, s2);
        int len1 = s1.size(), len2 = s2.size(), i, j;
        if(s1.size() == 0 || s2.size() == 0){
            cout << "You can visit at most " << 0 << " cities." << endl;
            continue;
        }
        int a[len1+1][len2+1];
        for( i = 0; i<=len1; i++)
        {
            for( j = 0; j<=len2; j++){
                if(i == 0 || j == 0)
                    a[i][j] = 0;
                else if(s1[i-1] == s2[j-1])
                    a[i][j] = 1 + a[i-1][j-1];
                else
                    a[i][j] = max(a[i-1][j], a[i][j-1]);
            }
        }
        cout << "You can visit at most " << a[len1][len2] << " cities." << endl;

        /// Displaying the longest common sub-sequence
        i = len1; j = len2;
        int cccc = 0, k = 0;
        while(1)  
        {
            if(cccc == a[len1][len2]) break;
            if(a[i][j] > max(a[i-1][j], a[i][j-1])){
                ans[k] = s1[i-1]; k++; i--; j--; cccc++;
            }
            else {
                if(a[i][j] == a[i-1][j]){
                    i--;
                }
                else if(a[i][j] == a[i][j-1]){
                    j--;
                }
            }
        }
        for(int i = strlen(ans)-1, j = 0; i>=0; i--, j++)
            ans2[j] = ans[i];
        puts(ans2);
        /*
        for(int i = strlen(ans)-1, j = 0; i>=0; i--, j++)
            cout << ans[i] << " ";
        cout << endl;
        */
        s1.clear(); s2.clear();
    }
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
string s,t;
int dp[1010][1010];
int total;
int lcs(int n,int m){
    if(n==s.size() || m==t.size()) return 0;
    else if(dp[n][m]!=-1) return dp[n][m];
    else if(s[n]==t[m]) return dp[n][m]=lcs(n+1,m+1)+1;
    else return dp[n][m]=max(lcs(n+1,m),lcs(n,m+1));
}

string Findstr(int n,int m){
    if(n==0 || m==0) return string("");
    else if(s[n-1]==t[m-1]) return Findstr(n-1,m-1)+s[n-1];
    //else if(dp[n-1][m]==dp[n][m-1]) return Findstr(n-1,m-1)+s[n-1];
    else if(dp[n-1][m]>dp[n][m-1]) return Findstr(n-1,m);
    else return Findstr(n,m-1);
}

int main(){
    while(getline(cin,s)){
        getline(cin,t);
        memset(dp,-1,sizeof(dp));
        int ans=lcs(0,0);
        string str=Findstr(s.size(),t.size());
        cout<<ans<<" "<<str<<endl;
    }
    return 0;
}
/*
ABCBDAB
BDCABA
*/

*/
/*
abcde
cede
    c e d e
  0 0 0 0 0
a 0 0 0 0 0
b 0 0 0 0 0
c 0 1 1 1 1
d 0 1 1 2 2
e 0 1 2 2 3
Case 1: you can visit at most 3 cities.
cde
*/
