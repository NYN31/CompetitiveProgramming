#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 10000010

ll const row = 4 ;
ll const col = 4 ;
ll const mod = 10007 ;
ll a,b,c,n;

struct matrix{
    ll mat[row][col] ;
    matrix(){}
    matrix(int type){
        memset(mat,0,sizeof mat) ;
        if(type == 1){
            for(int i=0,j=0; i<row&&j<col; i++,j++)
                mat[i][j] = 1 ;
        }
        else if(type == 2){
            mat[0][0]=a, mat[0][2]=b, mat[0][3]=1;
            mat[1][0]=1,mat[2][1]=1,mat[3][3]=1;
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
    if(n<=2) return 0LL;
    matrix ans = matrix(2);
    ans = ans^(n-2);
    ll x = (ans.mat[0][3]*c)%mod;
    return x;
}

int main()
{
    int t,no=0;
    cin>>t;
    while(t--){
        scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
        ll ans=fibo();
        printf("Case %d: %lld\n",++no,ans);
    }
    return 0;
}

