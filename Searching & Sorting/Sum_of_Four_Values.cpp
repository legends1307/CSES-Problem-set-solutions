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
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i =0;i < n;i++)cin >> arr[i];
    map<int,pair<int,int>> m;
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            auto it = m.find(x-arr[i] - arr[j]);
            if(it!=m.end()){
                cout << it->second.first + 1 << " " << it->second.second + 1 << " " << i +1 << " " <<  j+1 << endl;
                return 0;
            }
        }
        for(int j= 0;j < i;j++){
            m[arr[i] + arr[j]] = {j,i};
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}