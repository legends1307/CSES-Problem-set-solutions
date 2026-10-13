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
    int n,x;
    cin >> n >> x;
    vector<int> price(n),pages(n);
    for(int i = 0;i < n;i++) cin >> price[i];   
    for(int i = 0;i < n;i++) cin >> pages[i];
    vector<ll> dp(x+1, 0);
    for(int i = 0;i < n;i++){
        auto odp = dp;
        for(int j = price[i];j <= x;j++){
            dp[j] = max(dp[j],odp[j-price[i]]+pages[i]);
            // if(j==10) cout << i << ":: " << dp[j] << endl;
        }
    }
    ll ans = 0;
    for(int i = 0;i <= x;i++) ans = max(ans,dp[i]);
    // cout << endl;
    cout << ans << endl;
    return 0;
}