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
    vector<int> arr(n);
    for(int i = 0;i < n;i++) cin >> arr[i];
    map<int,int> m;
    int start = 0;
    m[arr[0]] = 0;
    int ans = 1;
    for(int i = 1;i < n;i++){
        auto it =m.find(arr[i]);
        if(it == m.end()){
            m[arr[i]]= i;
        }else{
            if(m[arr[i]] < start) m[arr[i]] = i;
            else{
                start = m[arr[i]]+1;
                m[arr[i]] = i;
            }
        }
        ans = max(ans,i-start + 1);
    }   
    cout << ans << endl;
    return 0;
}