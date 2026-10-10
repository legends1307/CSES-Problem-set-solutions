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
    int bmax = INT_MIN;
    vector<int> contained(n,0);
    for(int i : idx){
        if(rng[i].second <= bmax) contained[i] = 1;
        bmax = max(bmax,rng[i].second);
    }
    sort(idx.begin(),idx.end(),[&](int ia,int ib){
        auto a = rng[ia];
        auto b = rng[ib];
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    });
    int bmin = INT_MAX;
    vector<int> contains(n,0);
    for(int i : idx){
        if(rng[i].second >= bmin) contains[i] = 1;
        bmin = min(bmin,rng[i].second);
    }
    for(auto ele: contains) cout << ele << " ";
    cout << endl;
    for(auto ele: contained) cout << ele << " ";
    cout << endl;
    return 0;
}