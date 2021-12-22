const int b = 31, mod = 1423165193, lm = 1e6+5;
ll hash[lm], pow[lm] ;
 
void build_hash(string s){
    pow[0] = 1 ;
    int len = s.size();
    hash[len] = 0 ;
    for(int i = 1; i < lm; i++) pow[i] = (pow[i-1] * b) % mod ;
    for(int i = len-1; i >= 0; i--)
        hash[i] = (((hash[i+1] * b) % mod ) + s[i] ) % mod ;
}
 
inline int range_hash(int b,int e){
    return (((hash[b] - ((ll)hash[e+1] * pow[e-b+1]) % mod ) %mod) + mod ) % mod ;
}
 
inline int get_hash(string s){
    ll hash = 0, len = s.size() ;
    for(int i = len-1; i >= 0; i--)
        hash = (((hash * b) % mod ) + s[i] ) % mod ;
    return hash ;
}