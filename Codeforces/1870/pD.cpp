//君の手を握ってしまったら
//孤独を知らないこの街には
//もう二度と帰ってくることはできないのでしょう
//君が手を差し伸べた 光で影が生まれる
//歌って聞かせて この話の続き
//連れて行って見たことない星まで
//さユリ - 花の塔
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <bitset>
#include <climits>
#include <set>
#include <map>
#include <iomanip>
#include <queue>
#include <cstring>
#include <fstream>
using namespace std;
typedef long long ll;
#define int ll
#define starburst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pii pair<int,int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define maxn 200005
#define mod 1000000007

void solve(){
    int n, k; cin >> n;
    vector<int> c(n);
    for(auto &x:c) cin >> x;
    cin >> k;
    vector<pii> p;
    for(int i = n - 1, cur = 1e18; i >= 0; --i){
        if(cur > c[i]){
            cur = c[i];
            p.pb(pii(c[i], i));
        }
    }
    vector<int> ans(n);
    reverse(p.begin(), p.end());
    int t = p[0].ff, r = k % t, lim = k / t;
    ans[p[0].ss] = k / t;
    for(int i = 1; i < p.size(); ++i){
        int x = p[i].ff - p[i - 1].ff;
        ans[p[i].ss] += min(lim, r / x);
        r -= min(lim, r / x) * x;
        lim = ans[p[i].ss];
    }
    for(int i = n - 2; i >= 0; --i) ans[i] = max(ans[i + 1], ans[i]);
    for(int i = 0; i < n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
