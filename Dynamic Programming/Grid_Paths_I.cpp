#include <bits/stdc++.h>
using namespace std;
#define debug(a) cout<<"Value: "<<a<<endl;
#define ll long long
#define vll vector<ll>
#define vpll vector<pair<ll,ll> >
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define Fill(a,n) for(int i=0;i<n;i++){cin >> a[i];}
#define printarr(a,s,e) for(int i=s;i<=e;i++){cout<<a[i]<<" ";}cout<<endl;
#define printall(a) for(auto ele : a){cout<<ele<<" ";}cout<<endl;
const int N = 2e5 + 10;
const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i=0;i < n;i++) cin >> grid[i];
    vector<vector<ll>> dp(n, vector<ll>(n,0));
    if(grid[n-1][n-1] != '*') dp[n-1][n-1] = 1;
    // cout << dp[n-1][n-1] << endl;
    for(int i = n-1;i >=0;i--){
        for(int j = n-1;j >= 0;j--){
            if(grid[i][j] == '*') continue;
            if(j+1 <n && grid[i][j+1]!='*') dp[i][j] += dp[i][j+1];
            if(i+1 < n && grid[i+1][j]!='*') dp[i][j] += dp[i+1][j];
            dp[i][j] %=M;
        }
    }   
    cout << dp[0][0] << endl;
    return 0;
}