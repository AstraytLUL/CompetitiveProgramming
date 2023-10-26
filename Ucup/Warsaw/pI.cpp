#include <iostream>
#include <algorithm>
#include <queue> 
using namespace std;
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pii pair<int,int>
#define int long long
#define owo ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve(){
    int n; cin >> n;
    vector<int> v(n), cnt(61);
    for(auto &x:v) {
        cin >> x;
        for(int i = 0; i <= 60; ++i){
            if((1ll << i) == x) cnt[i]++;
        }
    }
    int ans = 0, cur = 0;
    for(int i = 1; i <= 60; ++i){
        int len = (1ll<<(i - 1)) * cnt[i];
        for(int j = 0; j < i; ++j){
            int c = len;
            len = max(0ll, len - cnt[j]);
            cnt[j] = max(0ll, cnt[j] - c);
            len /= 2;
        }
    }
    for(auto &x:cnt){
        ans += x;
    }
    cout << ans << '\n';
}

signed main(){
    owo
    int t = 1; cin >> t;
    while(t--) solve();
}