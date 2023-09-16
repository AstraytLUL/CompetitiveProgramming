#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define pii pair<int, int>
#define ff first
#define ss second
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

void solve(){
    int n; cin >> n;
    vector<int> v(n);
    for(auto &x:v) cin >> x;
    int m = -1;
    if(v[0] == 0){
        m = 1;
    }else{
        for(int i = 1; i < n; ++i){
            if(v[i] < v[i - 1]){
                m = v[i - 1] * 2 - v[i];
                break;
            }
        }
    }
    if(m != -1){
        bool ok = 1;
        int cur = 1;
        for(int i = 0; i < n; ++i){
            ok &= (v[i] == cur % m);
            cur = cur * 2 % m;
        }
        if(!ok) m = -1;
    }
    cout << m << '\n';
}

signed main(){
    io
    int t; cin >> t;
    while(t--) solve();
}