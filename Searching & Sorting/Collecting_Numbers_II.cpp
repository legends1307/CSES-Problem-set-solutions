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
    int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0;i < n;i++) cin >> arr[i];
    vector<int> ind(n+1);
    for(int i = 0;i<n;i++){
        ind[arr[i]] = i;
    }
    int ans = 1;
    for(int i = 1;i < n;i++) if(ind[i] > ind[i+1]) ans++;
    while(m--){
        int a,b;
        cin >> a >> b;
        a--;b--;
        swap(ind[arr[a]],ind[arr[b]]);
        swap(arr[a],arr[b]);
        int lo_idx = min(arr[a],arr[b]);
        int hi_idx = max(arr[a],arr[b]);
        int prev_hi = ind[lo_idx];
        int prev_lo = ind[hi_idx];
        if(hi_idx != n){
            if(prev_hi > ind[hi_idx+1] && ind[hi_idx] < ind[hi_idx+1])ans--;
            if(prev_hi < ind[hi_idx+1] && ind[hi_idx] > ind[hi_idx+1])ans++;
        }
        // if(m==1){
        //     cout << endl << endl;
        //     cout << ans << endl << ind[lo_idx] << " " << ind[hi_idx] << endl;
        //     for(auto ele: ind) cout << ele << " ";
        //     cout << endl;
        // }
        if(lo_idx != 1){
            if(ind[lo_idx-1] > prev_lo && ind[lo_idx-1] < ind[lo_idx]) ans--;
            if(ind[lo_idx-1] < prev_lo && ind[lo_idx-1] > ind[lo_idx]) ans++;
        }
        if(hi_idx - lo_idx != 1){
            if(prev_lo < ind[lo_idx+1] && ind[lo_idx] > ind[lo_idx+1]) ans++;
            if(prev_lo > ind[lo_idx+1] && ind[lo_idx] < ind[lo_idx+1]) ans--;
            if(ind[hi_idx-1] > prev_hi && ind[hi_idx-1] < ind[hi_idx]) ans--;
            if(ind[hi_idx-1] < prev_hi && ind[hi_idx-1] > ind[hi_idx]) ans++;
        }else{
            if(ind[lo_idx] < ind[hi_idx]) ans--;
            else ans++;
        }
        cout << ans << endl;
    }    
    return 0;
}