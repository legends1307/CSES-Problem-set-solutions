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
    multiset<int> prices;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        prices.insert(temp);
    }
    for(int i = 0;i < m;i++){
        int bid;
        cin >> bid;
        if(prices.size() ==0) {
            cout << "-1" << endl;
            continue;
        }
        auto it = prices.lower_bound(bid);
        if(it == prices.end()){
            auto it2 = prices.rbegin();
            cout << *it2 << endl;
            prices.erase(prices.find(*it2));
        }else if(*it == bid){
            cout << *it << endl;
            prices.erase(it);
        }else{
            if(it==prices.begin()){
                cout << "-1" << endl;
                continue;
            }
            cout << *--it << endl;
            prices.erase(it);
        }
    }
    return 0;
}