#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 110
int n1,n2;
string str1,str2,str,ans;
int dp[sz][sz];

int lcs(int m,int n){
    if(str1[m]=='\0' || str2[n]=='\0') return 0;
    else if(dp[m][n]!=-1) return dp[m][n];
    else if(str1[m]==str2[n]) return dp[m][n]=lcs(m+1,n+1)+1;
    else return dp[m][n]=max(lcs(m+1,n),lcs(m,n+1));
}

void print(int m,int n){
    if(str1[m]=='\0' || str2[n]=='\0') return ;
    else if(str1[m]==str2[n]){
        str+=str1[m];
        print(m+1,n+1);
    }
    else{
        if(dp[m+1][n]>dp[m][n+1]) print(m+1,n);
        else print(m,n+1);
    }
}

void printAll(int i,int j)
{
	if(str1[i]=='\0' || str2[j]=='\0'){
		cout<<ans<<endl;
		return;
	}
	if(str1[i]==str2[j]){
		ans+=str1[i];
		printAll(i+1,j+1);
		ans.erase(ans.end()-1); //Delete last character
	}
	else
	{
		if(dp[i+1][j]>dp[i][j+1]) printAll(i+1,j);
		else if(dp[i+1][j]<dp[i][j+1]) printAll(i,j+1);
		else
		{
			printAll(i+1,j);
			printAll(i,j+1);
		}
	}
}

int main(){
    cin>>str1>>str2;
    memset(dp,-1,sizeof dp);
    ll ans=lcs(0,0); /// Finding max length
    print(0,0); ///Printing only one ans
    printAll(0,0); /// Printing all possible ans
    cout<<ans<<endl;
    cout<<str<<endl;
}

/*
void print(ll a,ll b,ll lcs){

    for(ll add=0; add<lcs; add++){
        for(char ch='a'; ch<='z'; ch++){
            ll i,j,temp=add;
            for(i=a; i<str1.size() && str1[i]!=ch ; i++) ;
            for(j=b; j<str2.size() && str2[j]!=ch ; j++) ;
            if(str1[i]==ch && str2[j]==ch && dp[i][j]+temp == lcs){
                a = i+1 ;
                b = j+1 ;
                temp++ ;
                cout<< ch ;
            }
            if(temp == lcs) break ;
        }

    }
    cout<< endl ;
}
*/
