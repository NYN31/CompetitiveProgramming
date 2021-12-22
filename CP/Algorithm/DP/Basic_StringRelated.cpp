/******

        problem 1: find the maximum length of a substring, which is palindrome (longest palindromic substring) ;
        problem 2: find the maximum length of a subsequence, which is palindrome (longest palindromic subsequence) ;
        problem 3 : longest common subsequence ;

******/


/***
    problem 1: find the maximum length of a substring, which is palindrome (longest palindromic substring) ;
    complexity : O(n * n + n * n)
***/
const int l = 1005;
string str1, str2 ;
int dp[l+5][l+5]  ;

int lps(int i, int j) {
    if(i >= j) return 1 ;
    int &ret = dp[i][j]  ;
    if(ret != -1) return ret ;
    /*** as str1[i] & str1[j] are equal, so there might be e substring
         from i to j, which may be palindrome;
    ***/
    if(str1[i] == str1[j]) return ret = lps(i+1, j-1) ;
    /*** as str1[i] & str1[j] are not equal, so there must be no palindrome
         from i to j.
    ***/
    else return ret = 0 ;
}

void solve() {
    cin >> str1 ;
    int len = str1.size(), ans = 0 ;
    memset(dp, -1, sizeof dp) ;
    for(int i=0; i<len; i++) {
        for(int j=i; j<len; j++) {
            if(lps(i, j)) {
                ans = max(ans, j - i + 1) ;
            }
        }
    }
    cout << ans << nl ;
}


/***
    problem 2 : find the maximum length of a subsequence, which is palindrome (longest palindromic subsequence) ;
    complexity : O(n * n)
***/

int lps(int i, int j) {
    if(i >= j) return 0 ;
    int &ret = dp[i][j]  ;
    if(ret != -1) return ret ;
    if(str[i] == str[j]) return dp[i][j] = lps(i+1, j-1) + 2 ;
    else return dp[i][j] = max(lps(i+1, j), lps(i, j-1)) ;
}

void solve() {
    cin >> str ;
    int len = str.size(), ans = 0 ;
    memset(dp, -1, sizeof dp) ;
    ans = lps(0, len-1) ;
    cout << ans << nl ;
}


/***
    problem 3 : longest common subsequence ;
    complexity : O(n * n)
***/

string s, t ;
int lcs(int n, int m){
    if(n == s.size() || m == t.size()) return 0;
    else if(dp[n][m]!=-1) return dp[n][m];
    else if(s[n]==t[m]) return dp[n][m] = lcs(n+1, m+1)+1;
    else return dp[n][m]=max(lcs(n+1, m), lcs(n, m+1));
}

void solve() {
    cin >> s >> t ;
    int len = str.size(), ans = 0 ;
    memset(dp, -1, sizeof dp) ;
    ans = lcs(0, 0) ;
    cout << ans << nl ;
}
