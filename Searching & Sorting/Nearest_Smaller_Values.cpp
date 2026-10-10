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
    stack<pair<int,int>> s;
    vector<int> ans;
    for(int i = 0;i <n;i++){
        int temp;
        cin >> temp;
        int a = 0;
        while(s.size()){
            auto [ele, idx] = s.top();
            if(ele < temp) {
                a = idx;
                break;
            }
            s.pop();
        }
        ans.push_back(a);
        s.push({temp,i+1});
    }   
    for(auto ele: ans) cout << ele << " ";
    cout << endl;
    return 0;
}