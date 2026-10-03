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
    int x, n;
    cin >> x >> n;
    set<int> start, end;
    multiset<int> widths;
    widths.insert(x);
    start.insert(0);
    end.insert(x);
    while(n--){
        int temp;
        cin >> temp;
        auto sit = start.lower_bound(temp);
        sit--;
        auto eit = end.upper_bound(temp);
        widths.erase(widths.find(*eit - *sit));
        widths.insert(temp - *sit);
        widths.insert(*eit - temp);
        start.insert(temp);
        end.insert(temp);
        cout << *widths.rbegin() << " ";
    }cout << endl;
    return 0;
}