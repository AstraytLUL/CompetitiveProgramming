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

vector<int> a, ans, dp0, dp1, sz, tans, t;
vector<vector<int>> adj;

void dfs1(int u, int p){
    int cost0 = 0, cost1 = 0;
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        cost0 += dp0[v];
        cost1 += dp1[v];
    }
    if(t[u]){
        dp0[u] = sz[u] + cost1;
        dp1[u] = cost1;
    }else{
        dp0[u] = cost0;
        dp1[u] = sz[u] + cost0;
    }
}

void dfs2(int u, int p){
    int tmp0 = dp0[u], tmp1 = dp1[u], csz = sz[u];
    int tmpp0 = dp0[p], tmpp1 = dp1[p], cszp = sz[p];
    if(u != 1){
        int n = sz[p];
        if(t[p]){
            dp0[p] = dp0[p] - sz[u] - dp1[u];
            dp1[p] = dp1[p] - dp1[u];
        }else{
            dp0[p] = dp0[p] - dp0[u];
            dp1[p] = dp1[p] - sz[u] - dp0[u];
        }
        if(t[u]){
            dp0[u] = dp0[u] + dp1[p] - sz[u] + n;
            dp1[u] = dp1[u] + dp1[p];
        }else{
            dp0[u] = dp0[u] + dp0[p];
            dp1[u] = dp1[u] + dp0[p] - sz[u] + n;
        }
        sz[p] = n - sz[u];
        sz[u] = n;
    }
    tans[u] = min(dp0[u], dp1[u]);
    for(auto v:adj[u]){
        if(v == p) continue;
        dfs2(v, u);
    }
    dp0[u] = tmp0, dp1[u] = tmp1, sz[u] = csz;
    dp0[p] = tmpp0, dp1[p] = tmpp1, sz[p] = cszp;
}

void solve(){
    int n; cin >> n;
    a.assign(n + 1, 0);
    ans.assign(n + 1, 0);
    adj.assign(n + 1, {});
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n - 1; ++i){
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int j = 0; j < 20; ++j){
        tans.assign(n + 1, 0);
        t.assign(n + 1, 0);
        dp0.assign(n + 1, 0);
        dp1.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        for(int i = 1; i <= n; ++i){
            if(a[i] & (1 << j)) t[i] = 1;
        }
        dfs1(1, 1);
        dfs2(1, 1);
        for(int i = 1; i <= n; ++i){
            ans[i] += tans[i] * (1 << j);
        }
    }
    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';
}

signed main(){
    starburst
    int t = 1; cin >> t;
    while(t--) solve();
}
