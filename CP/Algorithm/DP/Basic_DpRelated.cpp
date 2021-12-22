/***
    problem 1: Given a 2XN grid, how many ways we can cover the whole grid with tiles. (tiles size: 2X1, 2X2) rotation may be allowed or not allowed.
    problem 2: You are given a 3XN grid. Given 3X1 and 3X2 tiles, what is the recurrence for f(N). (Rotation allowed)
    problem 3: Given an array with N integers, find a subsequence of this array to maximize the sum of the subsequence. (2 consecutive numbers not allowed)
    ----> Variation 1: Given an array with N(<1000) integers. Find a subsequence of array to maximize the following expression :
        Expression: 1*a1 + 2*a2 + 3*a3 + 4*a4 + .........
          Variation 2: Given an array with N(<100000) integers. Find a subsequence of array to maximize the following expression :
        Expression: a1 - a2 + a3 - a4 + a5 - ............ (2 consecutive numbers not allowed)
    problem 4: You are given N(<100000) tasks and each task has a starting time and finishing time and a profit. You can do any number of non-overlapping tasks and get the profit associated with them. Your goal is to maximize total profit;
    problem 5: given a number of elements n and another value sum.you have to find out, is it possible to make the givensum chossing from the array each element exactly one time..Thats mean, there is any subset, whose sum is exactly then givenvalue.....!

***/

---------------> Here solution part given bellow
/***
    problem 1: Given a 2XN grid, how many ways we can cover the whole grid with tiles. (tiles size: 2X1, 2X2) rotation may be allowed or not allowed.

    DP function:
                when rotation not allowed:
                 if n <= 2 : return 1 (base case)
                 if n > 2 : f(n) = f(n-1) + f(n-2) [which is finding a Fibonacci numbers]
                when rotation allowed:
                 if n <= 1 : return 1 (base case)
		 if n == 2 : return 2 (base case)
                 if n > 2 : f(n) = f(n-1) + f(n-2) + f(n-2)

***/

/***
    problem 2: You are given a 3XN grid. Given 3X1 and 3X2 tiles, what is the recurrence for f(N). (Rotation allowed)

    DP function:
                when rotation allowed:
                    if n <= 1 : return 1 (base case)
                    if n <= 2 : return 2 (base case)
                    if n > 3 : f(n) = f(n-1) + f(n-2) + 3*f(n-3) 

***/

/***
     problem 3: Given an array with N integers, find a subsequence of this array to maximize the sum of the subsequence. (2 consecutive numbers not allowed)

              Variation 1: Given an array with N(<100000) integers. Find a subsequence of array to maximize the value of sum (2 consecutive numbers not allowed)
              Variation 2: Given an array with N(<1000) integers. Find a subsequence of array to maximize the following expression :
            Expression: 1*a1 + 2*a2 + 3*a3 + 4*a4 + .........
              Variation 3: Given an array with N(<100000) integers. Find a subsequence of array to maximize the following expression :
            Expression: a1 - a2 + a3 - a4 + a5 - ............ (if consecutive elements are not allowed to take, then state will be f(pos, flag1, flag2))
***/

-----------------------------------------> Variation 1:
    ll dp[n+5][2] ;
    DP function :
        ll f(pos, flag) :
            if pos > n : return 0 ;
            if flag == 1 : return f(pos+1, 0) ;
            else if flag == 0 : return max(f(pos+1, 0), f(pos+1, 1)+value[pos])


----------------------------------------> Variation 2:
    ll dp[n][n] ;
    ll f(pos1, pos2) :
        if pos1 > n : return 1 (base case)
        return max(f(pos1+1, pos2), f(pos1+1, pos2+1) + pos2*value[pos1])

----------------------------------------> Variation 3:
    const int l = 100005 , inf = 1e18 ;
    ll dp[l+5][2] 
    ll arr[l+5], n, cnt 
    ll f(int pos, int flag) 
        if pos >= n : return 0 
        ll &ans = dp[pos][flag] 
        if ans != -1 : return ans 
        ans = -inf
        if flag == 0 : ans = max(ans, f(pos+1, 1) + arr[pos])
        if flag == 1 : ans = max(ans, f(pos+1, 0) - arr[pos]) 
        ans = max(ans, f(pos+1, flag))
        return ans
   



/***
    PROBLEM 4: You are given N(<100000) tasks and each task has a starting time and finishing time and a profit. You can do any number of non-overlapping tasks and get the profit associated with them. Your goal is to maximize total profit;
    complexity: O(n * log(n) ). [DP + Binary Search]
***/
const ll l = 200005 ;
vector <pair<ll, pair<ll, ll> > > arr ;
ll finish[l+5] ;
ll dp[l+5], n ;

ll call(ll pos) {
    if(pos >= n) return 0LL ;
    ll &ret = dp[pos] ;
    if(ret != -1) return ret ;
    ll d1, d2, pf, nxt ;
    d2 = arr[pos].ff, d1 = arr[pos].ss.ff, pf = arr[pos].ss.ss ;
    nxt = upper_bound(finish, finish+n, d2) - finish ; /// if we use vector for upper bound then we should write {d2, {-inf, -inf}} instead of only d2
    return ret = max(call(pos + 1), call(nxt) + pf) ;
}

void solve() {
    cin >> n ;
    for(int i=1; i<=n; i++) {
        ll a, b, c ; cin >> a >> b >> c ;
        arr.pb({a, {b, c}}) ;
    }
    sort(arr.begin(), arr.end()) ;
    for(int i=0; i<arr.size(); i++) {
        swap(arr[i].ff, arr[i].ss.ff) ;
        finish[i] = arr[i].ss.ff ;
    }
    memset(dp, -1, sizeof dp) ;
    ll ans = call(0) ;
    cout << ans << nl ;
}

/***
	problem 5: given a number of elements n and another value sum.you have to find out, is it possible to make the given sum choosing from the array each element exactly one time..Thats mean,
	Example:
	5
	2 3 7 8 10
	5  ---> YES
	7  ---> YES
	10 ---> YES
	14 ---> NO
***/
	int n,sum;
	int arr[110];
	bool dp[110][110];

	bool subset_sum(int pos, int rem) {
	    if(rem == 0) return true;
	    if(pos==n) {
	        if(rem==0) return true;
	        else return false;
	    }
	    bool &ret = dp[pos][rem];
    	if(ret != false) return ret;
    	if(rem-arr[pos]>=0) ret |= subset_sum(pos+1,rem-arr[pos]);
   		ret |= subset_sum(pos+1,rem);
    	return ret;

