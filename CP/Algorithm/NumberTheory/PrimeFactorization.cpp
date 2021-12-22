/*
problem 1: how to find prime factor of a number where (1<=n<=10^9)
          complexity: O(sqrt(n))
problem 2: how to find prime factor of all number from 1 to n where (1<=n<=10^5)
          complexity: O(n * sqrt(n))
problem 3: How to find largest prime factor of all number frome 1 to n (1<=n<=10^6)
          complexity: O(N * log(N) )
Problem 4: how to find prime factor of a number query where 1<=n<=q<=10^5;
          complexity: O(N*log(N) + q*log(n))
          process: normal sieve + largest prime factor
problem 5: how to find smallest prime factor of all number from 1 to n (1<=n<=10^6)
          complexity: O(Nlog(N))
problem 6: how to find total number of divisors with prime factorization (1<=n<=10^7, 1<=q<=10^5)
          complexity: O(N * log(N) + q * log(n))
problem 7: How to find sum of divisors of a number with prime factorization (1<=n<=10^7)
          complexity: O(n(log(n)) + )
problem 8: pollard rho
*/

/*
problem 1 : How to find prime factor of a number with given constraints
            For all composite number this solution takes log(n) time
            But for Prime number it takes sqrt(n) time, so Total time
            complexity is O(sqrt(n)).
*/
int main() {
    int n; cin>>n;
    int cnt1=0,cnt2=0 ;
    vector<int>primeFactor;
    for(int i=2;i*i<=n;i++) {
        if(n%i == 0) {
            while(n%i == 0) {
                primeFactor.push_back(i);
                n /= i;
            }
        }
    }
    if(n > 1) primeFactor.push_back(n);
    for(int i=0;i<primeFactor.size();i++)
        cout<<primeFactor[i]<<" ";
    return 0;
}

/*
problem 2: How to find prime factor of all number from 1 to n where (1<=n<=10^5)
          here is two for loop. Outer for loop iterate all number from 1 to n
          then inner for loop is for find out prime factor of each number whose 
          complexity is sqrt(n), and outer loops iterate through 1 to n, so the 
          total complexity is O(n * sqrt(n) );
*/


int main() {
    int n; cin>>n;
    for(int j=2;j<=n;j++) {
        vector<int>primeFactor;
        int num = j;
        for(int i=2;i*i<=num;i++) {
            if(num%i == 0) {
                while(num%i == 0) {
                    primeFactor.push_back(i);
                    num /= i;
                }
            }
        }
        if(num > 1) primeFactor.push_back(num);
        cout<<j<<": ";
        for(int i=0;i<primeFactor.size();i++)
            cout<<primeFactor[i]<<" ";
        cout<<endl;
    }
    return 0;
}

/*
problem 3: How to find largest prime factor of all number frome 1 to n (1<=n<=10^6)
*/
//// Process 1:
void sieve() {
    for(int i=0;i<=N;i++) isprime[i]=true;
    isprime[0]=isprime[1]=false;
    for(int i=4;i<=N;i+=2) isprime[i]=false;
    primes.pb(2);
    for(int i=3;i*i<=N;i++){
        if(isprime[i]){
            primes.pb(i);
            for(int j=i*i;j<=N;j+=i)
                isprime[j]=false;
        }
    }
    /// Here finding largest prime of all number frome 1 to 10^6
    for(int i=0;i<primes.size();i++) {
        for(int j=primes[i];j<=N;j+=primes[i]){
            lp[j] = primes[i];
        }
    }
}
//// Process 2:
void sieve()
{
    lps[1]=1;
    for(ll i=2;i<mxn;i++)
        if(!lps[i])
            for(ll j=i;j<mxn;j+=i)
                lps[j]=i;
}


/*
Problem 4: how to find prime factor of a number query where 1<=n<=q<=10^6;
          here given some number of query, we have to find prime factor for
          each number which takes q*log(n) times. Precalculation of sieve 
          also takes n*log(n).
*/
int const N = 10e5+5;
bool isprime[N+5];
vector<int>primes;
int lp[N+5];

void sieve() {
    for(int i=0;i<=N;i++) isprime[i]=true;
    isprime[0]=isprime[1]=false;
    for(int i=4;i<=N;i+=2) isprime[i]=false;
    primes.pb(2);
    for(int i=3;i*i<=N;i++){
        if(isprime[i]){
            primes.pb(i);
            for(int j=i*i;j<=N;j+=i)
                isprime[j]=false;
        }
    }
    /// Here finding largest prime factor of all number frome 1 to 10^6
    /// so, first we have found out all primes from 1 to 10^6, then
    for(int i=0;i<primes.size();i++) {
        for(int j=primes[i];j<=N;j+=primes[i]){
            lp[j] = primes[i];
        }
    }
}
int main() {
    sieve();
    int q; cin>>q;
    while(q--) {
        int n; cin>>n;
        vector<int>primeFact;
        /// Here finding factor of number n with log(n) complexity
        /// logic: iterate n to n > 1, then divide its laregest prime factor for 
        ///        each iteration.
        while(n > 1) {
            int x = lp[n];
            while(n%x == 0) {
                primeFact.pb(x);
                n /= x;
            }
        }
       for(int i=0;i<primeFact.size();i++)
            cout<<primeFact[i]<<" ";
        cout<<endl;
    }
    return 0;
}

/*
Problem 5: how to find smallest prime factor of all number from 1 to n
*/
int const N = 10e6+5;
int spf[N+5];
void precal() {
    for(int i=2;i*i<=N;i++) {
        for(int j=i*i;j<=N;j+=i) {
            if(spf[j] == 0) spf[j] = i;
        }
    }
    for(int i=2;i<=N;i++) if(!spf[i]) spf[i]=i;
}

/*
problem 6: how to find total number of divisors with prime factorization
          formula: 
                    prime factorization of n = p1^a1 * p2^a2 * p3^a3 ....... px^ax [here, p1, p2, p3, .... px are prime factors and a1, a2, a3, .... ax are how many of them]
                    Then the total number of divisors are: ans = (a1+1)*(a2+1)*(a3+1)*....*(ax+1)
*/

int const N = 1e7+5;
bool isprime[N+5];
vector<int>primes;

void sieve() {
    for(int i=0;i<=N;i++) isprime[i] = true;
    for(int i=4;i<=N;i+=2) isprime[i] = false;
    isprime[0]=isprime[1]=false;
    primes.pb(2);
    for(int i=3;i*i<=N;i++){
        if(isprime[i]){
            primes.pb(i);
            for(int j=i*i;j<=N;j+=i)
                isprime[j]=false;
        }
    }
}

ll factorize(int n) {
    ll ans = 1;
    if(isprime[n]) return 2;
    for(int i=0;i<primes.size()&&primes[i]*primes[i]<=n;i++){
        int p = primes[i], power=0;
        if(n%p != 0) continue;
        while(n%p == 0) {
            power++;
            n/=p;
        }
        ans *= (power+1);
    }
    if(n>1) ans *= 2;
    return ans;
}

int main() {
    sieve();
    int q; cin>>q;
    while(q--) {
        int n; cin>>n;
        ll divisor_count = factorize(n);
        cout<<divisor_count<<endl;
    }
    return 0;
}
/*
problem 7: How to find sum of divisors of a number with prime factorization (1<=n<=10^7)
          formula: ans = (p1^(a1+1) - 1)/(p1-1) * (p2^(a2+1) - 1)/(p2-1) * (p3^(a3+1) - 1)/(p3-1) * ..... * (px^(ax+1) - 1)/(px-1)
*/

int const N = 1e7+5;
bool isprime[N+5];
vector<int>primes;

ll binpow(ll a, ll p) {
    if(p == 0) return 1;
    else if(p%2==0) {
        ll ret = binpow(a, p/2);
        return ret*ret;
    }
    else {
        ll ret = binpow(a, p-1);
        return a*ret;
    }
}

void sieve() {
    for(int i=0;i<=N;i++) isprime[i] = true;
    for(int i=4;i<=N;i+=2) isprime[i] = false;
    isprime[0]=isprime[1]=false;
    primes.pb(2);
    for(int i=3;i*i<=N;i++){
        if(isprime[i]){
            primes.pb(i);
            for(int j=i*i;j<=N;j+=i)
                isprime[j]=false;
        }
    }
}

ll factorize(int n) {
    ll ans = 1;
    if(isprime[n]) return 2;
    for(int i=0;i<primes.size()&&primes[i]*primes[i]<=n;i++){
        int p = primes[i], power=0;
        if(n%p != 0) continue;
        while(n%p == 0) {
            power++;
            n/=p;
        }
        ans *= (binpow(p, power+1)-1) / (p - 1);
    }
    if(n>1) ans *= (binpow(n,2)-1) / (n-1);
    return ans;
}

int main() {
    sieve();
    int q; cin>>q;
    while(q--) {
        int n; cin>>n;
        ll divisor_sum = factorize(n);
        cout<<divisor_sum<<endl;
    }
    return 0;
}

/*
Problem 8: Pollard rho
*/

#include<bits/stdc++.h>
using namespace std;

// Integer factorization in O(N^{1/4}
// probably fails on 5003^5 which is ~10^{18.5}
namespace NT {
    template<typename T>
    struct bigger_type {};
    template<typename T> using bigger_type_t = typename bigger_type<T>::type;
    template<> struct bigger_type<int> {
        using type = long long;
    };
    template<> struct bigger_type<unsigned int> {
        using type = unsigned long long;
    };
    template<typename int_t = unsigned long long>
    struct modint {
        static inline int_t add(int_t const&a, int_t const&b, int_t const&mod) {
            int_t ret = a+b;
            if (ret>=mod) ret-=mod;
            return ret;
        }
        static inline int_t sub(int_t const&a, int_t const&b, int_t const&mod) {
            return add(a, mod-b);
        }
        static inline int_t mul(int_t const&a, int_t const&b, int_t const&mod) {
            uint64_t ret = a * (uint64_t)b - (uint64_t)((long double)a * b / mod - 1.1) * mod;
            if (-ret < ret) {
                ret = mod-1-(-ret-1)%mod;
            } 
            else {
                ret %= mod;
            }
            int64_t out = ret;
            return out;
        }
        static inline int_t pow(int_t const&a, int_t const&b, int_t const&mod) {
            int_t ret = 1;
            int_t base = a;
            for (int i=0; b>>i; ++i) {
                if ((b>>i)&1) ret = mul(ret, base, mod);
                base = mul(base, base, mod);
            }
            return ret;
        }
    };
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type is_prime(T x) {
        if (x<T(4)) return x>T(1);
        for (T i=2; i*i<=x; ++i) {
            if (x%i == 0) return false;
        }
        return true;
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_single(T const&x, T base) {
        if (x<T(4)) return x>T(1);
        if (x%2 == 0) return false;
        base%=x;
        if (base == 0) return true;
        T xm1 = x-1;
        int j = 1;
        T d = xm1/2;
        while(d%2 == 0) {
            d/=2;
            ++j;
        }
        T t = modint<T>::pow(base, d, x);
        if (t==T(1) || t==T(xm1)) return true;
        for (int k=1; k<j; ++k) {
            t = modint<T>::mul(t, t, x);
            if (t == xm1) return true;
            if (t<=1) break;
        }
        return false;
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_multi(T const&) {
        return true;
    }
    template<typename T, typename... S>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_multi(T const&x, T const&base, S const&...bases) {
        if (!miller_rabin_single(x, base)) return false;
        return miller_rabin_multi(x, bases...);
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin(T const&x) {
        if (x < 316349281) return miller_rabin_multi(x, T(11000544), T(31481107));
        if (x < 4759123141ull) return miller_rabin_multi(x, T(2), T(7), T(61));
        return miller_rabin_multi(x, T(2), T(325), T(9375), T(28178), T(450775), T(9780504), T(1795265022));
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type isqrt(T const&x) {
        assert(x>=T(0));
        T ret = static_cast<T>(sqrtl(x));
        while(ret>0 && ret*ret>x) --ret;
        while(x-ret*ret>2*ret)
            ++ret;
        return ret;
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type icbrt(T const&x) {
        assert(x>=T(0));
        T ret = static_cast<T>(cbrt(x));
        while(ret>0 && ret*ret*ret>x) --ret;
        while(x-ret*ret*ret>3*ret*(ret+1))
            ++ret;
        return ret;
    }
    vector<uint16_t> saved;
    // https://github.com/radii/msieve
    uint64_t squfof_iter_better(uint64_t const&x, uint64_t const&k, uint64_t const&it_max, uint32_t cutoff_div) {
        if (__gcd((uint64_t)k, x)!=1) return __gcd((uint64_t)k, x);
        saved.clear();
        uint64_t scaledn = k*x;
        if (scaledn>>62) return 1;
        uint32_t sqrtn = isqrt(scaledn);
        uint32_t cutoff = isqrt(2*sqrtn)/cutoff_div;
        uint32_t q0 = 1;
        uint32_t p1 = sqrtn;
        uint32_t q1 = scaledn-p1*p1;
        if (q1 == 0) {
            uint64_t factor = __gcd(x, (uint64_t)p1);
            return factor==x ? 1:factor;
        }
        uint32_t multiplier = 2*k;
        uint32_t coarse_cutoff = cutoff * multiplier;
        uint32_t i, j;
        uint32_t p0 = 0;
        uint32_t sqrtq = 0;
        for (i=0; i<it_max; ++i) {
            uint32_t q, bits, tmp;
            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
            if (q1 < coarse_cutoff) {
                tmp = q1 / __gcd(q1, multiplier);
                if (tmp < cutoff) {
                    saved.push_back((uint16_t)tmp);
                }
            }
            bits = 0;
            tmp = q0;
            while (!(tmp & 1)) {
                bits++;
                tmp >>= 1;
            }
            if (!(bits & 1) && ((tmp & 7) == 1)) {
                sqrtq = (uint32_t)isqrt(q0);
                if (sqrtq * sqrtq == q0) {
                    for (j=0; j<saved.size(); ++j) {
                        if(saved[j] == sqrtq) break;
                    }
                    if(j == saved.size()) break;
                    //else cerr << "skip " << i << "\n";;
                }
            }
            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;
            if (q0 < coarse_cutoff) {
                tmp = q0 / __gcd(q0, multiplier);
                if (tmp < cutoff) {
                    saved.push_back((uint16_t) tmp);
                }
            }
        }
        if(sqrtq == 1) {
            return 1;
        }
        if(i == it_max) {
            return 1;
        }
        q0 = sqrtq;
        p1 = p0 + sqrtq * ((sqrtn - p0) / sqrtq);
        q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;
        for (j=0; j<it_max; ++j) {
            uint32_t q, tmp;
            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
            if (p0 == p1) {
                q0 = q1;
                break;
            }
            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;

            if (p0 == p1)
                break;
        }
        if(j==it_max) {
            cerr << "RNG\n";    // random fail
            return 1;
        }
        uint64_t factor = __gcd((uint64_t)q0, x);
        if(factor == x) factor=1;
        return factor;
    }
    uint64_t squfof(uint64_t const&x) {
    // for  using only squfof don't comment the following lines.
    // for  factorizing comment these, no problem.
    //        for (uint64_t i=2;i<=min((int64_t)5000,(int64_t)x/2-1);i++){
    //            uint64_t p=(uint64_t)((1.0*x)/(i*1.0)+eps);
    //            if(p*i==x) return i;
    //        }
        static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};

        uint64_t cbrt_x = icbrt(x);
        if(cbrt_x*cbrt_x*cbrt_x == x) return cbrt_x;

        //uint32_t iter_lim = isqrt(isqrt(x))+10;
        uint32_t iter_lim = 300;
        for (uint32_t iter_fact = 1; iter_fact<20000; iter_fact*=4) {
            for (uint32_t const&k : multipliers) {
                if(numeric_limits<uint64_t>::max()/k<=x) continue; //would overflow
                uint32_t const it_max = iter_fact*iter_lim;
                uint64_t factor = squfof_iter_better(x, k, it_max, 1);
                if(factor==1 || factor==x) continue;
                return factor;
            }
        }
        cerr << "failed to factor: " << x << "\n";
        assert(0);
        assert(0);
        return 1;
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, vector<T>>::type factorize_brute(T x) {
        vector<T> ret;
        while(x%2 == 0) {
            x/=2;
            ret.push_back(2);
        }
        for (uint32_t i=3; i*(T)i <= x; i+=2) {
            while(x%i == 0) {
                x/=i;
                ret.push_back(i);
            }
        }
        if(x>1) ret.push_back(x);
        return ret;
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, vector<T>>::type factorize(T x) {
        vector<T> ret;
        const uint32_t trial_limit = 5000;
        auto trial = [&](uint32_t const&i) {
            while(x%i == 0) {
                x/=i;
                ret.push_back(i);
            }
        };
        trial(2);
        trial(3);
        for (uint32_t i=5, j=2; i<trial_limit && i*i <= x; i+=j, j=6-j) {
            trial(i);
        }
        if (x>1) {
            static stack<T> s;
            s.push(x);
            while (!s.empty()) {
                x = s.top();
                s.pop();
                if (!miller_rabin(x)) {
                    T factor = squfof(x);
                    if (factor == 1 || factor == x) {
                        assert(0);
                        return ret;
                    }
                    s.push(factor);
                    s.push(x/factor);
                } else {
                    ret.push_back(x);
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
}
using ll = int64_t;
using namespace NT;

