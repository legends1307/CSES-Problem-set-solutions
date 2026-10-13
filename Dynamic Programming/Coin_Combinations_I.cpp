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
const int N = 1e6 + 10;
const int M = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i =0 ;i < n;i++) cin >> coins[i];
    vector<ll> dp(N,-1);
    // for(auto c: coins) dp[c] = ;
    dp[0] = 1;
    // dp[2] = 2;
    // dp[3] = 3;
    function<ll(int)> solve = [&](int target){
        if(dp[target] != -1) return dp[target];
        ll ans = 0;
        for(auto c: coins){
            if(target < c)continue;
            ll tans = solve(target-c);
            ans += tans;
            ans %= M;
        }
        return dp[target] = ans;
    };
    // for(auto ele: dp) cout << ele << " " ;
    // cout << endl;
    cout << solve(x) << endl;

    return 0;
}