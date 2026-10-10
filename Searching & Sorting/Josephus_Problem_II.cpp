#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
template <typename T>
using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 2e5 + 10;
const int M = 1e9 + 7;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    ordered_set<int> s;
    for(int i = 0;i < n;i++) {
        s.insert(i+1);
    }
    int start = 0;
    while(s.size() > 0){
        int idx = (start + k) % s.size();
        // cout << "idx: " << idx << endl;
        auto it = s.find_by_order(idx);
        start = idx ;
        cout << *it << " ";
        s.erase(it);
    }cout << endl;
    return 0;
}