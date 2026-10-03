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
struct Node{
    int val;
    Node* next;
    Node(int v){
        val = v;
        next = nullptr;    
    }
};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    Node* head = new Node(1);  
    Node* temp =head;
    for(int i = 2;i <= n;i++){
        Node* tm = new Node(i);
        temp->next = tm;
        temp = tm;
    }
    temp->next = head;
    // Node* pr = head;
    // for(int i = 0;i < n+1;i++) {
    //     cout << pr->val << endl;
    //     pr=pr->next;
    // }
    while(head->next != head){
        cout << head->next->val << " ";
        head->next = head->next->next;
        head = head->next;
    }
    cout << head->val << endl;
    return 0;
}