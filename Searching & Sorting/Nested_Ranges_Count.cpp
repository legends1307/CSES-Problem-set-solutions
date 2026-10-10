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
    int n;
    cin >> n;
    vector<pair<int,int>> rng(n);
    for(int i = 0;i < n;i++) cin >> rng[i].first >> rng[i].second;
    vector<int> idx(n);
    iota(idx.begin(),idx.end(),0);
    sort(idx.begin(),idx.end(),[&](int ia,int ib){
        auto a = rng[ia];
        auto b = rng[ib];
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }); 
    ordered_set<pair<int,int>> bmax;
    vector<int> contained(n,0);
    for(int i : idx){
        contained[i] = bmax.size() - bmax.order_of_key({rng[i].second,-1});
        bmax.insert({rng[i].second,i});
    }
    sort(idx.begin(),idx.end(),[&](int ia,int ib){
        auto a = rng[ia];
        auto b = rng[ib];
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    ordered_set<pair<int,int>> bmin;
    vector<int> contains(n,0);
    for(int i : idx){
        contains[i] = bmin.order_of_key({rng[i].second,INT_MAX});
        bmin.insert({rng[i].second,i});
    }
    for(auto ele: contains) cout << ele << " ";
    cout << endl;
    for(auto ele: contained) cout << ele << " ";
    cout << endl;
    return 0;
}