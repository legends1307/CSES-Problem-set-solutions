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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        arr[i]%=n;
    }   
    vector<ll> m(n,0);
    m[0]++;
    ll ans = 0;
    ll cursum = 0;
    for(int i = 0;i < n;i++){
        cursum = (cursum + arr[i] + 2*n)%n;
        ans += m[cursum];
        // cout << ans << " " << cursum << endl;
        m[cursum]++;
    }
    cout << ans << endl;
    return 0;
}