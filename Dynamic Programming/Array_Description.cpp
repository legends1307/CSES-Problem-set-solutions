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
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0;i < n;i++)cin >> arr[i];
    vector<vector<ll>> dp(n+1, vector<ll>(m+1,-1));
    function<ll(int,int)> solve = [&](int idx, int prev){
        if(idx==n) return 1ll;
        // cout << "HERE" << endl;
        if(dp[idx][prev]!= -1) return dp[idx][prev];
        ll ans = 0;
        if(arr[idx]==0){
            if(prev  >1) ans += solve(idx+1, prev-1);
            ans+= solve(idx+1,prev);
            if(prev < m) ans += solve(idx + 1, prev+1);
        }
        else{
            if(abs(arr[idx]-prev)<=1) ans = solve(idx+1,arr[idx]);
        }
        return dp[idx][prev] = ans%M;
    };
    ll fans = 0;
    if(arr[0]==0){
        for(int i = 1;i<=m;i++){
            fans += solve(1,i);
            fans %=M;
        }
    }else{
        fans = solve(1,arr[0]);
    }
    cout << fans << endl;
    return 0;
}