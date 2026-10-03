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
    int ans = 1;
    vector<int> ind(n+1);
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        ind[temp] = i;
    }
    // for(int i = 0;i <= n;i++) cout << ind[i] << " ";
    // cout << endl;
    for(int i = 1;i <n;i++){
        if(ind[i] > ind[i+1]) ans++;
    }
    cout << ans << endl;
    return 0;
}