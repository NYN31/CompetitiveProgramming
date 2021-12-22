
ll product(ll a, ll b, ll m) {
      /// a * b
      /// (a1*10^6+a2) * (b1*10^6*b2) ;
      /// (a1*b1*10^12) + {(a1*b2 + a2*b1) * 10^6} + (a2*b2) ;

      ll a1 = a / 1000000, a2 = a % 1000000 ;
      ll b1 = b / 1000000, b2 = b % 1000000 ;
      ll x = (a1 * (b1 * 1000000000000LL % m)) % m ;
      ll y = (a1 * b2 + a2 * b1) % m * 1000000 % m;
      ll z = a2 * b2 ;
      ll res = (x + y + z) % m ;
      return res ;
}
