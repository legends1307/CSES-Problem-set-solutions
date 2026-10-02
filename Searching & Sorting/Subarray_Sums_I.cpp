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
    vector<int> arr(n);
    for(int i =0 ;i < n;i++){
        cin >> arr[i];
    }
    int r = 0;
    int ans =0;
    int sm = arr[0];
    for(int l = 0;l < n;l++){
        if(r < l){
            r = l;
            sm = arr[l];
        }
        while(sm < x){
            r++;
            if(r == n) break;
            sm += arr[r];
        }
        if(r == n) break;
        if(sm == x) ans++;
        sm -= arr[l]; 
        // cout << l << ": " << ans << endl;  
    }
    cout << ans << endl;
    return 0;
}