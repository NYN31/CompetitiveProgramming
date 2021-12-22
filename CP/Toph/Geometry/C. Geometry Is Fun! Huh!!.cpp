#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define sz 100010
#define BeatMeScanf ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define pii pair<int,int>
#define ff first
#define ss second
#define pb push_back


int const mod = 1e9;
int const N = 2e5;

int main()
{
    BeatMeScanf;
    int t, no = 0;
    cin>>t;
    while(t--) {
        double r, chd, a, b, c, h, angle, p;
        cin>>r>>chd;
        a = sqrt((r*r)-((chd/2)*(chd/2))); /// AC/2
        h = ((r+r)-chd)/2;
        h = (r+r)-h;
        b = sqrt((h*h) + (a*a)); /// CE
        c = b; /// AE
        a *= 2; /// AC
        p = (b*b + c*c - a*a) / (2*b*c);

        angle = acos(p);
        angle=(angle*180)/(acos(-1.0));
        cout<<"Case "<<++no<<": ";
        cout<<fixed<<setprecision(4)<<angle<<endl;
    }
    return 0;

}
