const int b = 31, mod = 1423165193, lm = 1e6+5;
ll h[lm], po[lm] ;
 
void build_hash(string s){
    po[0] = 1 ;
    int len = s.size();
    h[len] = 0 ;
    for(int i = 1; i < lm; i++) po[i] = (po[i-1] * b) % mod ;
    for(int i = len-1; i >= 0; i--)
        h[i] = (((h[i+1] * b) % mod ) + s[i] ) % mod ;
}
 
inline int range_hash(int b,int e){
    return (((h[b] - ((ll)h[e+1] * po[e-b+1]) % mod ) %mod) + mod ) % mod ;
}
 
inline int get_hash(string s){
    ll res_hash = 0, len = s.size() ;
    for(int i = len-1; i >= 0; i--)
        res_hash = (((res_hash * b) % mod ) + s[i] ) % mod ;
    return res_hash ;
}
 
 
void solve() {
    string str1, str2 ;
    cin >> str1 >> str2 ;
    int len1 = str1.size(), len2 = str2.size() ;
    int val2 = get_hash(str2) ;
    int cnt = 0, val1 = 0;
    build_hash(str1) ;

    for(int i=0; i<str1.size() - str2.size() + 1; i++) {
        val1 = range_hash(i, i + len2 - 1) ;
        if(val1 == val2) cnt += 1 ;
    }
    cout << cnt << endl ;
}

/// 2nd way:
 
const int b = 31, mod = 1423165193, lm = 1e6+5;
ll h[lm], po[lm] ;
 
void build_hash(string s){
    po[0] = 1 ;
    int len = s.size();
    h[len] = 0 ;
    for(int i = 1; i < lm; i++) po[i] = (po[i-1] * b) % mod ;
    for(int i = len-1; i >= 0; i--)
        h[i] = (((h[i+1] * b) % mod ) + s[i] ) % mod ;
}
 
inline int range_hash(int b,int e){
    return (((h[b] - ((ll)h[e+1] * po[e-b+1]) % mod ) %mod) + mod ) % mod ;
}
 
inline int get_hash(string s){
    int res_hash = 0, len = s.size() ;
    for(int i = len-1; i >= 0; i--)
        res_hash = (((res_hash * b) % mod ) + s[i] ) % mod ;
    return (res_hash + mod) % mod ;
}
 
 
void solve() {
    string str1, str2 ;
    cin >> str1 >> str2 ;
    build_hash(str2) ;
    int len1 = str1.size(), len2 = str2.size() ;
    int val2 = range_hash(0, len2 - 1) ;
    
    int cnt = 0, val1 = 0;
    build_hash(str1) ;
 
    for(int i=0; i<str1.size() - str2.size() + 1; i++) {
        val1 = range_hash(i, i + len2 - 1) ;
        if(val1 == val2) cnt += 1 ;
    }
    cout << cnt << endl ;
}
