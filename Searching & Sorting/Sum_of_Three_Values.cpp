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
    vector<pair<int,int>> arr;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        arr.push_back({temp,i+1});
    }
    if(n < 3) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    sort(arr.begin(),arr.end());
    // for(auto ele: arr) cout << ele.first << ", " << ele.second << endl;
    for(int i = 0;i < n-2;i++){
        int k = n-1;
        for(int j = i+1;j < n-1;j++){
            // cout << i << ", " << j << ", " << k << endl;
            while(k > j+1 && arr[i].first + arr[j].first + arr[k].first > x){
                k--;
            }
            if(arr[i].first + arr[j].first + arr[k].first == x){
                // cout << arr[i].second << " " << arr[j].second << " " << arr[k].second << endl;
                vector<int> ans = {arr[i].second, arr[j].second, arr[k].second};
                sort(ans.begin(),ans.end());
                cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}