#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 10000010

ll const row = 2 ;
ll const col = 2 ;
ll a,b,m,n,mod;

struct matrix{
    ll mat[row][col] ;
    matrix(){}
    matrix(int type){
        memset(mat,0,sizeof mat) ;
        if(type == 1){              /// Identity matrix
            for(int i=0,j=0; i<row&&j<col; i++,j++)
                mat[i][j] = 1 ;
        }
        else if(type == 2){         /// Fibonacci matrix
            mat[0][0] = mat[0][1] = mat[1][0] = 1 ;
        }
        else if(type == 3){         /// nth order fibb: f(n) = f(n-1)+f(n-2)+f(n-3)...
            for(int i=0; i<col; i++) mat[0][i] = 1 ;
            for(int i=1; i<row; i++) mat[i][i-1] = 1 ;
        }
    }
    matrix(int arr[]){
        for(int i=0,k=0; i<row; i++)
            for(int j=0; j<col; j++)
                mat[i][j] = arr[k++] ;
    }

    matrix operator+(const matrix b) const{
        matrix ans = matrix(0) ;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                ans.mat[i][j] = mat[i][j] + b.mat[i][j] ;
        return ans ;
    }

    matrix operator*(const matrix b) const{
        matrix ans = matrix(0) ;
        for(int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                for(int k=0; k<col; k++)
                ans.mat[i][j] = (ans.mat[i][j]+ mat[i][k]*b.mat[k][j]) % mod ;
        return ans ;
    }

    matrix operator^(int p){
        matrix res(1) ;
        matrix x = *this ;
        while(p){
            if(p&1)
                res = res * x ;
            p >>= 1 ;
            x = x * x ;
        }
        return res ;
    }
};

ll fibo(){
    if(n==0) return a%mod;
    if(n==1) return b%mod;
    a=a%mod, b=b%mod;
    matrix ans = matrix(2);
    ans = ans^(n-1);
    return ((ans.mat[0][0]*b)%mod + (ans.mat[0][1]*a)%mod)%mod;
}

int main()
{
    int t,no=0;
    cin>>t;
    while(t--){
        scanf("%lld %lld %lld %lld",&a,&b,&n,&m);
        mod=1;
        for(int i=1;i<=m;i++) mod*=10;
        ll ans=fibo();
        printf("Case %d: %lld\n",++no,ans);
    }
    return 0;
}
