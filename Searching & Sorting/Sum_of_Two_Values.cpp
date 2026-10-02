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
    vector<pair<int,int> > arr;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        arr.push_back(make_pair(temp,i+1));
    }
    sort(arr.begin(),arr.end());
    int p1 = 0,p2 = n-1;
    vector<int> ans;
    while(p1 < p2){
        int tot = arr[p1].first + arr[p2].first;

        if(tot == x){
            ans = {arr[p1].second,arr[p2].second};
            break;
        }
        else if(tot < x){
            p1++;
        }else{
            p2--;
        }
    }
    if(ans.size() > 0){
        sort(ans.begin(),ans.end());
        cout << ans[0] << " " << ans[1] << endl;
    }else{
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}   