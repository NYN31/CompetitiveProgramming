/*
problem 1: finding divisors of a given number (1<=n<=10^9)
	   complexity: O(sqrt(n))
problem 2: finding all divisors from 1 to n (1<=n<=10^5)
	   complexity: O(n * sqrt(n) );
problem 3: Finding divisors from 1 to n (1<=n<=10^6)
	   complexity: O(N * log(N) + q)
problem 4: Finding divisors sum from 1 to n (1<=n<=10^6, 1<=q<=10^5)
	   complexity: O(N * log(N) + q)
problem 5:
*/


/*
problem 1: finding divisors of a given number (1<=n<=10^9)
	   complexity : O(sqrt(n))
*/
int main()
{
    BeatMeScanf;
    ll b;
    while(cin>>b){
        int divisors=0;
        for(ll i=1;i*i<=b;i++){
            if(b%i==0){
                divisors++;
                if(b/i!=i) divisors++;
            }
        }
        cout<<divisors<<endl;
    }
    return 0;
}


/*
problem 2: finding all divisors from 1 to n (1<=n<=10^5)
	   complexity: O(n * sqrt(n) );
*/

int main() {
	int n; cin>>n;
	for(int i=1;i<=n;i++) {
		int num = i;
		vector<int>div;
		for(int j=1;j*j<=num;j++) {
			if(num%j == 0) {
				if(j == num/j) div.pb(j);
				else {
					div.pb(j);
					div.pb(num/j);
				}
			}
		}
		for(auto x : div) cout<<x<<" ";
		cout<<endl;
		div.clear();
	}
	return 0;
}

/*
problem 3: Finding divisors from 1 to n (1<=n<=10^6)
	   complexity: O(N * log(N) + q)
*/

int const N = 10e6+5;

int div_count[N+5];
void precal() {
	for(int i=1;i<=N;i++) {
		for(int j=i;j<=N;j+=i){
			div_count[j]++;
		}
	}
}
/*
	complexity of precal function
	= n + n/2 + n/3 + n/4 + n/5 ..........
	= n * (1 + 1/2 + 1/3 + 1/4 + 1/5) ....
	= n * (1 + ln2);
	= nlog(n);
*/

int main() {
    precal();
    int q; cin>>q;
    while(q--) {
    	int n; cin>>n;
    	cout<<div_count[n]<<endl;
    }
    return 0;
}


/* 
problem 4: Finding divisors sum from 1 to n (1<=n<=10^6, 1<=q<=10^5)
	   complexity: O(N * log(N) + q)
*/
int const N = 10e6+5;
int div_sum[N+5];
void precal() {
	for(int i=1;i<=N;i++) {
		for(int j=i;j<=N;j+=i){
			div_sum[j] += i;
		}
	}
}
int main() {
    precal();
    int q; cin>>q;
    while(q--) {
    	int n; cin>>n;
    	cout<<div_sum[n]<<endl;
    }
    return 0;
}
