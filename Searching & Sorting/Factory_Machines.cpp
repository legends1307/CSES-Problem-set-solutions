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
    ll n,t;
    cin >> n >> t;
    vector<ll> arr(n);
    for(int i = 0;i < n;i++) cin >> arr[i];
    ll lo = 1,hi = 1e18+3;
    auto solve = [&](ll x){
        ll p = 0;
        for(int i = 0;i < n;i++){
            p += x/arr[i];
            if(p>=t) return true;
            // cout << x/arr[i] << ", " << arr[i] << endl;
        }
        // cout << p << ", " << t << endl;
        return p>=t;
    };
    // cout << solve(8) << endl;
    ll ans = hi;
    while(hi >= lo){
        ll mid = lo + (hi - lo)/2;
        if(solve(mid)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
        // cout << lo << "-" << hi;
        // cout <<  "(ans=" << ans << endl;
    }   
    cout << ans << endl;
    return 0;
}