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
    vector<ll> dp(n+1,0);
    for(int i = 1;i <=6;i++) dp[i]++;
    for(int i = 1;i <=n;i++){
        for(int j = i-1;j >= i-6 && j > 0;j--){
            dp[i] += dp[j];
            dp[i]%=M;
        }
        // for(int i = 0;i <= n;i++)cout << dp[i] << " ";
        // cout << endl;
    }   
    cout << dp[n] << endl;
    return 0;
}